/*

    This file is part of KBox.

    Copyright (C) 2016 Thomas Sarlandie.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <Arduino.h>

#include <stdint.h>
typedef uint16_t pin_t;


static const pin_t led_pin = 13;

/* TFT Screen Definition */
static const uint32_t display_width = 320;
static const uint32_t display_height = 240;
static const pin_t display_miso = 12;
static const pin_t display_mosi = 11;
static const pin_t display_sck = 14;
static const pin_t display_cs = 20;
static const pin_t display_dc = 21;
static const pin_t display_backlight= 32;
#ifdef BOARD_v1_revA
static const uint8_t display_rotation = 3;
#else
static const uint8_t display_rotation = 1;
#endif

static const pin_t encoder_a = 19;
static const pin_t encoder_b = 18;
static const pin_t encoder_button = 17;

static const pin_t neopixel_pin = 22;

static const pin_t wifi_enable = 2;
static const pin_t wifi_program = 5;
static const pin_t wifi_rst = 23;
#ifdef BOARD_v1_revA
// On v1 revA, the CS line was supposed to be 21 but was hijacked to be display_dc.
#error No wifi cs line available on v1 revA. Use a more recent board!
#else
static const pin_t wifi_cs = 31;
#endif

static const pin_t can_standby = 33;

static const uint8_t ina219_address = 0x40;

static const uint8_t bmp280_address = 0x76;

static const pin_t nmea1_out_enable = 24;
static const pin_t nmea2_out_enable = 16;

#ifdef BOARD_v1_revA
static const pin_t bat1_analog = A10;
static const pin_t bat2_analog = A11;
static const pin_t bat3_analog = A12;
static const float analog_max_voltage = 3.3 / (10000/(10000+56000.0));
#else
static const pin_t bat1_analog = A12;
static const pin_t bat2_analog = A11;
static const pin_t bat3_analog = A10;
static const float analog_max_voltage = 3.0 / (10000/(10000+56000.0));
#endif
static const pin_t supply_analog = A14;

static const pin_t sdcard_cs = 15;

void init_board();