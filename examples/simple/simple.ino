#include <m72198d.h>

#define MAX7219_DIN 13
#define MAX7219_CS  15
#define MAX7219_CLK 14
#define NUMDISP 2

unsigned long time;

Max7219 display1(MAX7219_DIN, MAX7219_CS, MAX7219_CLK, NUMDISP);

void setup() {
  Serial.begin(115200);
  //  initialise();
  Serial.println("Starting init");
  display1.init();
  Serial.println("Ended init");
  delay(250);
}

void loop() {
  time = millis();
  //int displaySerial.println(String(time));
  display1.writeNumInFontB("12345678", 1);
  display1.writeNumInFontB(String(time), 2);

  delay(1000);
}
