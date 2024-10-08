/*
Copyright 2022 Matthew Dias <matthewdias@me.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #include "config_common.h"


/* USB Device descriptor parameter */
// #define VENDOR_ID       0x6D64
// #define PRODUCT_ID      0x7274
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    Matthew Dias
// #define PRODUCT         Rescue Truck

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* model-v PCB default pin-out */
#define MATRIX_ROW_PINS { D3, D5, D4, D6 }
#define MATRIX_COL_PINS { B4, B5, B6, C6, C7, F7, F6, F5, F4, F1, F0, D7 }

/* COL2ROW or ROW2COL */
// #define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE 5

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
