#pragma once

// Custom matrix configuration for multiplexer
#define MATRIX_ROWS 3
#define MATRIX_COLS 16
#define MATRIX_ROW_PINS { D0, D1, D2 }
#define MATRIX_COL_PINS { 1, 2, 3, 4, 5, 6, 0, 7, 13, 12, 11, 10, 9, 14, 15, 8 }

// Multiplexer pins (directly connected to MCU)
#define MULTIPLEX_PINS { D4, D6, D7, B4 }
#define MULTIPLEX 4
