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

- **`mise run setup`** - Initialize QMK environment (run after clean)
- **`mise run clean`** - Clean build artifacts
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

**CRITICAL**: Always run `mise run setup` after `mise run clean`. The setup command initializes the QMK environment and is required for builds to work.

```bash
# Correct workflow
mise run clean
mise run setup    # REQUIRED after clean
mise run qmk compile -kb <keyboard> -km <keymap>

# Incorrect - will fail
mise run clean
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

## Upgrading QMK Firmware

To switch QMK firmware versions:

1. Edit `bin/init-qmk` and uncomment the desired version
2. Run: `uv run bin/init-qmk`

This will re-clone the firmware and sync its Python dependencies.
