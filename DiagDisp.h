/**************************************************************************
 *     This file is part of DiagDisp.
    I, John Turner, the author of this program disclaim all copyright
    in order to make this program freely available in perpetuity to
    anyone who would like to use it. John Turner, 3/22/2023
    DiagDisp is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    DiagDisp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    See <https://www.gnu.org/licenses/>.

    To use this with BSOS requires a version of the Rev4 board with the display module - it assumes a compatible display is installed 
    NOTE: some of the 128x64 displays have reversed vcc and gnd pins please match the pins to the board correctly or you risk destroying the display
    if you wish to use this in sub libraries be sure to include it in those libraries
    it assumes a max character limit of 21 characters per line char txt[21] - I didn't make it safe - violate this and you will see fun characters in the display
    startDiagDisplay() should be called in setup() 
 */

#ifndef DiagDisp_h
#define DiagDisp_h
#include "Arduino.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4
#define MAX_LINES 8


    void displayln(char txt[21]);
    void startDiagDisplay();

#endif