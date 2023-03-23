#include "DiagDisp.h"
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
startDiagDisplay();
}
int i = 0;
char buf[21];
void loop() {
  // put your main code here, to run repeatedly:
sprintf(buf,"this is line %d",i);
displayln(buf);
  i++;
delay(500);
}
