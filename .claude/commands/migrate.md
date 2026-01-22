---
description: Migrate a keyboard from legacy format to keyboard.json
arguments:
  - name: keyboard
    description: Keyboard path (e.g., lazydesigners/apricot)
    required: true
---

# Migrate Keyboard to keyboard.json Format

Migrate `$ARGUMENTS.keyboard` from legacy format (info.json + config.h + rules.mk) to modern keyboard.json format for QMK 0.31.9+ compatibility.

## Pre-flight Checks

1. Verify the keyboard exists in `firmware/$ARGUMENTS.keyboard`
2. Check if already migrated (keyboard.json exists and no legacy files)
3. Read the existing legacy files to understand the current configuration

## Migration Steps

Follow the migration guide in CLAUDE.md:

### Step 1: Create keyboard.json

Combine these legacy files into one `keyboard.json`:
- `info.json` → `keyboard_name`, `manufacturer`, `url`, `maintainer`, `layouts`
- `config.h` → `usb`, `matrix_pins`, `diode_direction`, `ws2812`, `rgblight`
- `rules.mk` → `processor`, `bootloader`, `features`

**Important:** Convert layout from labels to matrix positions:
```json
// OLD: {"label": "K000", "x": 0, "y": 0}
// NEW: {"matrix": [0, 0], "x": 0, "y": 0}
```

Matrix gaps (KC_NO in old LAYOUT macro) should be omitted from the layout array.

### Step 2: Update Header File

Remove the LAYOUT macro from `<keyboard>.h`. Keep only:
```c
#pragma once
#include "quantum.h"
```

### Step 3: Delete Legacy Files

Remove: `info.json`, `config.h`, `rules.mk`

### Step 4: Validate

```bash
# Reset keyboard in QMK_HOME (clears and re-copies from firmware/)
mise run reset $ARGUMENTS.keyboard

# Check JSON syntax
python3 -m json.tool firmware/$ARGUMENTS.keyboard/keyboard.json

# Verify keyboard is recognized
mise run qmk list-keyboards | grep $ARGUMENTS.keyboard

# Check configuration
mise run qmk info -kb $ARGUMENTS.keyboard

# Test compile (find keymap from keymaps file or use default)
mise run qmk compile -kb $ARGUMENTS.keyboard -km <keymap>
```

### Step 5: Update Checklist

Mark the keyboard as complete in MIGRATION_CHECKLIST.md.

## Notes

- If compilation fails due to old keycodes, check CLAUDE.md for the keycode migration table
- The `firmware/` directory is the canonical source - changes here will be copied to $QMK_HOME during setup
- Use `mise run reset <keyboard>` to clear legacy files from QMK_HOME that rsync doesn't remove
