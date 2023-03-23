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
    it assumes a max character limit of 21 characters per line - I didn't make it safe - violate this and you will see fun characters in the display
    startDiagDisplay() should be called in setup() 
 */

#include "Arduino.h"
#include "DiagDisp.h"
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int line=0;
char lines[MAX_LINES][21];

void startDiagDisplay() {
  display.begin(0x3C, true);
}

void displayln(char txt[21]) {
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.clearDisplay();
  if (line <=MAX_LINES - 1){ //fill the first x lines up
    strcpy(lines[line],txt);
    line++;
  } else {
    for (int i = 0; i <= MAX_LINES - 2; i++) { //move all lines up by 1
    strcpy(lines[i],lines[i+1]);
    }
    strcpy(lines[MAX_LINES - 1],txt); // copy the new last line in 
    line = MAX_LINES;
  }
  display.setCursor(0, 0);
  for (int i = 0; i <= MAX_LINES - 1; i++) { // populate the display
    display.println(lines[i]);
    Serial.println(lines[i]);
  }
  display.display();
}