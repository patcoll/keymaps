# QMK Keymaps Project

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

### Build Tasks (run in keymaps folder)

- **`mise run setup`** - Run QMK setup (`make`)
- **`mise run clean`** - Clean build artifacts (`make clean`)

### QMK Tasks (run in QMK_HOME folder)

- **`mise run compile`** - Compile QMK firmware
  ```bash
  mise run compile -kb lazydesigners/apricot -km patcoll
  ```

- **`mise run flash`** - Flash firmware to keyboard
  ```bash
  mise run flash -kb lazydesigners/apricot -km patcoll
  ```

## Daily Workflow

```bash
# Compile your keymap
mise run compile -kb <keyboard> -km <keymap>

# Flash to keyboard
mise run flash -kb <keyboard> -km <keymap>
```

## Upgrading QMK Firmware

To switch QMK firmware versions:

1. Edit `bin/init-qmk` and uncomment the desired version
2. Run: `uv run bin/init-qmk`

This will re-clone the firmware and sync its Python dependencies.
