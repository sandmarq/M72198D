/*
  m72198d.cpp - MAX7219 8-Digit LED Display 7 Segment For Arduino Library.
  Created by Sandrine Marquis, 27 janvier, 2017.
*/

#include "Arduino.h"
#include "m72198d.h"

Max7219::Max7219(int max7219din, int max7219cs, int max7219clk, int numdisp)
{
  _max7219din = max7219din;
  _max7219cs = max7219cs;
  _max7219clk = max7219clk;
  _numdisp = numdisp;
}

void Max7219::setAddress(byte address)
{
  _address = address;
}

void Max7219::setData(byte data)
{
  _data = data;
}

/*
initialize the display to normal operation, with 8 digits, maximum brightness,
with CodeB decode on all digits.
*/
void Max7219::init()
{
  digitalWrite(_max7219cs, HIGH);
  pinMode(_max7219din, OUTPUT);
  pinMode(_max7219cs, OUTPUT);
  pinMode(_max7219clk, OUTPUT);

  //  output(0x0f, 0x00); //display test register - test mode off
  setTestModeOff();
  //  output(0x0c, 0x01); //shutdown register - normal operation
  setShutdownRegNorm();
  // output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
  setLimitScanReg();
  //  output(0x0a, 0x0f); //intensity register - max brightness
  setBrightness();
  //  output(0x09, 0xff); //decode mode register - CodeB decode all digits
  setDecodeMode();
}

void Max7219::output()
{
  digitalWrite(_max7219cs, LOW);
  shiftOut(_max7219din, _max7219clk, MSBFIRST, _address);
  shiftOut(_max7219din, _max7219clk, MSBFIRST, _data);
  digitalWrite(_max7219cs, HIGH);
}

//  output(0x0f, 0x00); //display test register - test mode off
void Max7219::setTestModeOff(){
  setAddress(MAX7219_REG_ADD_DPTE);
  setData(MAX7219_TEST_MODE_OFF);
  output();
}

//  output(0x0f, 0x01); //display test register - test mode on
void Max7219::setTestModeOn(){
  setAddress(MAX7219_REG_ADD_DPTE);
  setData(MAX7219_TEST_MODE_ON);
  output();
}

//  output(0x0c, 0x00); //shutdown register - shutdown
void Max7219::setShutdownRegShut(){
  setAddress(MAX7219_REG_ADD_SHTD);
  setData(MAX7219_SHTD_REG_FOR_SHM);
  output();
}

//  output(0x0c, 0x01); //shutdown register - normal operation
void Max7219::setShutdownRegNorm(){
  setAddress(MAX7219_REG_ADD_SHTD);
  setData(MAX7219_SHTD_REG_FOR_NOR);
  output();
}

// output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
void Max7219::setLimitScanReg(int numDigits){
  setAddress(MAX7219_REG_ADD_SCLT);
  setData(numDigits);
  output();
}

//  output(0x0a, 0x0f); //intensity register - max brightness
void Max7219::setBrightness(int brightness){
  setAddress(MAX7219_REG_ADD_BRIG);
  setData(MAX7219_INTE_MAX);
  output();
}

//  output(0x09, 0xff); //decode mode register - CodeB decode all digits
void Max7219::setDecodeMode(int decodeMode){
setAddress(MAX7219_REG_ADD_DECM);
setData(MAX7219_DEC_MOD_REG_CB70);
output();
}

// Write text on display Max 8 Digit
void Max7219::writeNumInFontB(){
  // To-Do
}
