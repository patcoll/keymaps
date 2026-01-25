# QMK Keymaps Project

## Repository Structure

```
keymaps/
├── firmware/           # Canonical keyboard definitions (synced to $QMK_HOME via sync tasks)
│   └── lazydesigners/
│       └── apricot/    # keyboard.json, apricot.h, apricot.c
├── keyboards/          # Keymaps for keyboards
│   └── lazydesigners/
│       └── apricot/
│           └── keymaps/
│               └── patcoll/
├── users/              # User-specific keymap code (shared across keyboards)
│   └── patcoll/
├── working_area/       # $QMK_HOME lives here (external, not in repo)
│   └── qmk_firmware/
└── qmk.json            # QMK external userspace config
```

**Key directories:**
- `firmware/` - Custom keyboard definitions. Synced to QMK_HOME via `mise run sync`.
- `keyboards/` - Keymaps that reference keyboards (either from firmware/ or upstream QMK).
- `users/` - Shared user code (macros, combos, tap behaviors, etc.). This repo is configured as a QMK external userspace.
- `working_area/qmk_firmware/` - Working copy of QMK firmware (cloned via `mise run setup`).

**Key files:**
- `keymaps` - Canonical list of keyboards we care about. Used by build system.

To get the list of keyboards with custom firmware (keyboards in `keymaps` that have firmware in `firmware/`):
```bash
mise run firmware:list
```

## Setup

This project uses `uv` for Python dependency management and `mise` for task automation. It also uses QMK's [external userspace](https://docs.qmk.fm/newbs_external_userspace) feature.

### Initial Setup

1. **Install dependencies**:
   ```bash
   uv sync
   ```

2. **Clone QMK firmware and install its dependencies**:
   ```bash
   mise run setup
   ```

3. **Sync keyboards and keymaps**:
   ```bash
   mise run sync-all
   ```

The setup task will:
- Clone the QMK firmware repository to `working_area/qmk_firmware/`
- Install QMK firmware Python dependencies into the uv-managed virtual environment

The sync-all task will:
- Rsync custom firmware from `firmware/` to QMK_HOME
- Symlink keymaps from `keyboards/` into QMK_HOME

### Environment Variables

- `QMK_HOME`: Points to `working_area/qmk_firmware` (defined in `mise.toml`)
- `QMK_USERSPACE`: Points to this repo root (enables external userspace for `users/` directory)

## Available Tasks

Use `mise run <task>` to execute:

- **`mise run setup`** - Clone QMK firmware and install dependencies (run after teardown)
- **`mise run teardown`** - Remove QMK firmware directory (requires setup to rebuild)
- **`mise run sync <keyboard>`** - Sync firmware and keymaps for one keyboard to QMK_HOME
- **`mise run sync-all`** - Sync all keyboards listed in `keymaps` file
- **`mise run reset <keyboard>`** - Remove and re-sync a keyboard (only for keyboards with custom firmware)
- **`mise run remove <keyboard>`** - Remove a keyboard's firmware from QMK_HOME
- **`mise run clean`** - Run `qmk clean -a` to clean build artifacts
- **`mise run test`** - Build all keymaps to verify they compile
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

**CRITICAL**: After `mise run teardown`, you must run both `mise run setup` and `mise run sync-all` before builds will work.

```bash
# Correct workflow after teardown
mise run teardown
mise run setup      # Clone QMK firmware
mise run sync-all   # Sync keyboards and keymaps
mise run qmk compile -kb <keyboard> -km <keymap>

# Incorrect - will fail
mise run teardown
mise run qmk compile -kb <keyboard> -km <keymap>  # ERROR: no QMK firmware

# Also incorrect - keyboard not synced
mise run teardown
mise run setup
mise run qmk compile -kb <keyboard> -km <keymap>  # ERROR: keyboard not found
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

**How it works:** The `firmware/` directory is the canonical source. Running `mise run sync <keyboard>` rsyncs these files to `$QMK_HOME/keyboards/`, overriding any upstream QMK files. Keymaps from `keyboards/` are symlinked into QMK_HOME. QMK auto-generates the LAYOUT macro from keyboard.json at compile time.

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

1. Edit `mise-tasks/setup` and change the `qmk clone -b <version>` line
2. Run:
   ```bash
   mise run teardown
   mise run setup
   mise run sync-all
   ```

This will re-clone the firmware at the new version and re-sync all keyboards.

## CI Notes

The GitHub Actions workflow (`.github/workflows/keymaps.yml`) uses `awalsh128/cache-apt-pkgs-action` to cache apt packages for faster builds. The `qmk_install.sh` step in build jobs is commented out because the cache action already installs the packages. If builds fail due to missing dependencies, uncomment that step.
