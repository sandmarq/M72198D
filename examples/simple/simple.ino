#include <m72198d.h>

#define MAX7219_DIN 13
#define MAX7219_CS  15
#define MAX7219_CLK 14
#define NUMDISP 1

unsigned long time;

Max7219 display1(MAX7219_DIN, MAX7219_CS, MAX7219_CLK, NUMDISP);

void setup() {
  Serial.begin(115200);
  //  initialise();
  display1.init();
  display1.setBrightness(MAX7219_INTE_MIN);
  Serial.println("init");
  delay(250);
}

void loop() {
  time = millis();
  display1.writeNumInFontB(String(time));

  delay(10);
}
