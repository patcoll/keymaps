/*
Copyright 2021 Nachie

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

#define RP2040_FLASH_GENERIC_03H

#define HAL_USE_I2C TRUE

/* Oled config */
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11
#define OLED_TIMEOUT 60000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 13
#define OLED_BRIGHTNESS 50
#define OLED_UPDATE_INTERVAL 16

#define SOLENOID_PINS { GP15 }

#define VIA_CUSTOM_LIGHTING_ENABLE
