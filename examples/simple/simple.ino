#include <m72198d.h>

#define MAX7219_DIN 13
#define MAX7219_CS  15
#define MAX7219_CLK 14
#define NUMDISP 1

Max7219 display1(MAX7219_DIN, MAX7219_CS, MAX7219_CLK, NUMDISP);

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
//  initialise();
//  output(0x0f, 0x00); //display test register - test mode off
  display1.init(); // initialize and display test register - test mode off
  Serial.println("init");
  delay(250);
}

void loop() {
//  output(0x0c, 0x01); //shutdown register - normal operation
  display1.setaddress(MAX7212_REG_ADD_SHTD);
  display1.setdata(MAX7219_SHTD_REG_FOR_NOR);
  display1.output();
  Serial.println("shutdown register - normal operation");

  // output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
  display1.setaddress(MAX7212_REG_ADD_SCLT);
  display1.setdata(MAX7219_NUM_DIGIT_8);
  display1.output();
  Serial.println("scan limit register - display digits 7 thru 0");

//  output(0x0a, 0x0f); //intensity register - max brightness
  display1.setaddress(MAX7212_REG_ADD_BRIG);
  display1.setdata(MAX7219_INTE_MAX);
  display1.output();
  Serial.println("intensity register - max brightness");

//  output(0x09, 0xff); //decode mode register - CodeB decode all digits
  display1.setaddress(MAX7212_REG_ADD_DECM);
  display1.setdata(MAX7219_DEC_MOD_REG_CB70);
  display1.output();
  Serial.println("decode mode register - CodeB decode all digits");

//  output(0x08, 0x0c); //digit 7 (leftmost digit) data
  display1.setaddress(MAX7212_REG_ADD_DIG7);
  display1.setdata(MAX7219_CODEB_FONT_REG_3);
  display1.output();
  Serial.println("digit 7 (leftmost digit) data");

//  output(0x07, 0x0b);
  display1.setaddress(MAX7212_REG_ADD_DIG6);
  display1.setdata(MAX7219_CODEB_FONT_REG_0);
  display1.output();


//  output(0x06, 0x0d);
  display1.setaddress(MAX7212_REG_ADD_DIG5);
  display1.setdata(MAX7219_CODEB_FONT_REG_0);
  display1.output();

//  output(0x05, 0x0e);
  display1.setaddress(MAX7212_REG_ADD_DIG4);
  display1.setdata(MAX7219_CODEB_FONT_REG_1);
  display1.output();

//  output(0x04, 0x08);
  display1.setaddress(MAX7212_REG_ADD_DIG3);
  display1.setdata(MAX7219_CODEB_FONT_REG_2);
  display1.output();

//  output(0x03, 0x07);
  display1.setaddress(MAX7212_REG_ADD_DIG2);
  display1.setdata(MAX7219_CODEB_FONT_REG_0);
  display1.output();

//  output(0x02, 0x06);
  display1.setaddress(MAX7212_REG_ADD_DIG1);
  display1.setdata(MAX7219_CODEB_FONT_REG_1);
  display1.output();

//  output(0x01, 0x05); //digit 0 (rightmost digit) data
  display1.setaddress(MAX7212_REG_ADD_DIG0);
  display1.setdata(MAX7219_CODEB_FONT_REG_7);
  display1.output();
  Serial.println("digit 0 (rightmost digit) data");

  delay(1000);

}
