# QMK Keymaps Project

## Repository Structure

```
keymaps/
├── firmware/           # Canonical keyboard definitions (copied to $QMK_HOME during setup)
│   └── lazydesigners/
│       └── apricot/    # keyboard.json, apricot.h, apricot.c
├── keyboards/          # Keymaps for keyboards
│   └── lazydesigners/
│       └── apricot/
│           └── keymaps/
│               └── patcoll/
├── users/              # User-specific keymap code (shared across keyboards)
│   └── patcoll/
└── keymaps_qmk/        # $QMK_HOME - Working QMK firmware (external, not in repo)
```

**Key directories:**
- `firmware/` - Custom keyboard definitions. These override upstream QMK keyboards during setup.
- `keyboards/` - Keymaps that reference keyboards (either from firmware/ or upstream QMK).
- `users/` - Shared user code (macros, combos, tap behaviors, etc.).
- `$QMK_HOME` (keymaps_qmk/) - Working copy of QMK firmware. Gets cloned from upstream, then files from `firmware/` and `keyboards/` are copied in during setup.

**Key files:**
- `keymaps` - Canonical list of keyboards we care about. Used by build system.

To get the list of keyboards with custom firmware (keyboards in `keymaps` that have firmware in `firmware/`):
```bash
mise run firmware
```

## Setup

This project uses `uv` for Python dependency management and `mise` for task automation.

### Initial Setup

1. **Install dependencies**:
   ```bash
   uv sync
   ```

2. **Clone QMK firmware and install its dependencies**:
   ```bash
   uv run bin/init-qmk
   ```

The `init-qmk` script will:
- Clone the QMK firmware repository to `keymaps_qmk/` (configured via `QMK_HOME`)
- Install QMK firmware Python dependencies into the uv-managed virtual environment

### Environment Variables

- `QMK_HOME`: Points to `../keymaps_qmk` (defined in `mise.toml`)

## Available Tasks

Use `mise run <task>` to execute:

- **`mise run setup`** - Initialize QMK environment (run after teardown)
- **`mise run teardown`** - Tear down QMK environment (requires setup to rebuild)
- **`mise run qmk <command>`** - Run any QMK CLI command in $QMK_HOME

### Examples

```bash
# Compile firmware
mise run qmk compile -kb lazydesigners/apricot -km patcoll

# Flash firmware to keyboard
mise run qmk flash -kb lazydesigners/apricot -km patcoll

# List available keyboards
mise run qmk list-keyboards

# Get keyboard info
mise run qmk info -kb lazydesigners/apricot
```

## Daily Workflow

```bash
# Compile your keymap
mise run qmk compile -kb <keyboard> -km <keymap>

# Flash to keyboard
mise run qmk flash -kb <keyboard> -km <keymap>
```

## Important Build Rules

**CRITICAL**: Always run `mise run setup` after `mise run teardown`. The setup command initializes the QMK environment and is required for builds to work.

```bash
# Correct workflow
mise run teardown
mise run setup    # REQUIRED after clean
mise run qmk compile -kb <keyboard> -km <keymap>

# Incorrect - will fail
mise run teardown
mise run qmk compile -kb <keyboard> -km <keymap>  # ERROR: build will not work
```

## Keyboard Migrations

### Apricot Keyboard (lazydesigners/apricot)

This keyboard has been migrated from legacy format to modern keyboard.json format for QMK 0.31.9+ compatibility.

**Modern format (in `firmware/lazydesigners/apricot/`):**
- `keyboard.json` - All hardware configuration (USB IDs, matrix pins, features, layout)
- `apricot.h` - Header only, no LAYOUT macro (auto-generated from keyboard.json)
- `apricot.c` - Keyboard code

**Removed legacy files:**
- `info.json` - Replaced by keyboard.json
- `config.h` - Merged into keyboard.json
- `rules.mk` - Merged into keyboard.json

**How it works:** The `firmware/` directory is the canonical source. During `mise run setup`, these files are copied to `$QMK_HOME/keyboards/`, overriding any upstream QMK files. QMK auto-generates the LAYOUT macro from keyboard.json at compile time.

## Migration Guide: Legacy to keyboard.json

How to convert old QMK firmware (info.json + config.h + rules.mk) to modern keyboard.json format.

### Step 1: Create keyboard.json

Combine these legacy files into one `keyboard.json`:

| Legacy File | keyboard.json Section |
|-------------|----------------------|
| `info.json` | `keyboard_name`, `manufacturer`, `url`, `maintainer`, `layouts` |
| `config.h` | `usb`, `matrix_pins`, `diode_direction`, `ws2812`, `rgblight` |
| `rules.mk` | `processor`, `bootloader`, `features` |

**Layout format change:** Old info.json uses labels, new format uses matrix positions:
```json
// OLD: {"label": "K000", "x": 0, "y": 0}
// NEW: {"matrix": [0, 0], "x": 0, "y": 0}
```

Matrix gaps (KC_NO in old LAYOUT macro) are simply omitted from the layout array.

### Step 2: Update Header File

Remove the LAYOUT macro from `<keyboard>.h` - QMK auto-generates it from keyboard.json.

Keep only:
```c
#pragma once
#include "quantum.h"
```

### Step 3: Delete Legacy Files

Remove: `info.json`, `config.h`, `rules.mk`

Keep: `keyboard.json`, `<keyboard>.h`, `<keyboard>.c`

### Step 4: Update Keycodes in Keymaps

QMK 0.31.9 renamed many keycodes:

**Mouse movement:**
| Old | New |
|-----|-----|
| `KC_MS_L` | `MS_LEFT` |
| `KC_MS_R` | `MS_RGHT` |
| `KC_MS_U` | `MS_UP` |
| `KC_MS_D` | `MS_DOWN` |

**Mouse buttons:**
| Old | New |
|-----|-----|
| `KC_BTN1` | `MS_BTN1` |
| `KC_BTN2` | `MS_BTN2` |
| `KC_BTN3` | `MS_BTN3` |

**Mouse wheel:**
| Old | New |
|-----|-----|
| `KC_WH_L` | `MS_WHLL` |
| `KC_WH_R` | `MS_WHLR` |
| `KC_WH_U` | `MS_WHLU` |
| `KC_WH_D` | `MS_WHLD` |

**RGB underglow:**
| Old | New |
|-----|-----|
| `RGB_TOG` | `UG_TOGG` |
| `RGB_MOD` | `UG_NEXT` |
| `RGB_HUI` | `UG_HUEU` |
| `RGB_SAI` | `UG_SATU` |
| `RGB_VAI` | `UG_VALU` |

### Step 5: Clean Up Keymap config.h

Remove redundant defines that are now in keyboard.json:
- `RGBLIGHT_LED_COUNT` (now `rgblight.led_count` in keyboard.json)
- Any `#define` that duplicates keyboard.json settings

### Step 6: Validate

```bash
# Check JSON syntax
python3 -m json.tool firmware/<keyboard>/keyboard.json

# Verify keyboard is recognized
mise run qmk list-keyboards | grep <keyboard>

# Check configuration
mise run qmk info -kb <keyboard>

# Test compile
mise run qmk compile -kb <keyboard> -km <keymap>
```

### Common Gotchas

1. **Both info.json and keyboard.json exist** - QMK gets confused. Delete info.json.
2. **LAYOUT macro still in .h file** - Causes "Layout macro should not be defined within .h files" warning. Remove it.
3. **Old keycodes in keymaps** - Compilation errors like "'KC_BTN1' undeclared". Update to new names.
4. **Redundant defines in keymap config.h** - Warnings about redefinition. Remove duplicates.

## Upgrading QMK Firmware

To switch QMK firmware versions:

1. Edit `bin/init-qmk` and uncomment the desired version
2. Run: `uv run bin/init-qmk`

This will re-clone the firmware and sync its Python dependencies.
