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
void Max7219::init(void)
{
  digitalWrite(_max7219cs, HIGH);
  pinMode(_max7219din, OUTPUT);
  pinMode(_max7219cs, OUTPUT);
  pinMode(_max7219clk, OUTPUT);

  for (int x=1; x<=_numdisp; x++){
    //  output(0x0f, 0x00); //display test register - test mode off
    setTestModeOff(x);
    //  output(0x0c, 0x01); //shutdown register - normal operation
    setShutdownRegNorm(x);
    // output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
    setLimitScanReg(MAX7219_NUM_DIGIT_8, x);
    //  output(0x0a, 0x0f); //intensity register - max brightness
    setBrightness(MAX7219_INTE_MAX, x);
    //  output(0x09, 0xff); //decode mode register - CodeB decode all digits
    setDecodeMode(MAX7219_DEC_MOD_REG_CB70, x);
   }
}

void Max7219::output(int display)
{
    digitalWrite(_max7219cs, LOW);
    shiftOut(_max7219din, _max7219clk, MSBFIRST, _address);
    shiftOut(_max7219din, _max7219clk, MSBFIRST, _data);

    if(display>1){
      for(int d=display; d>1;d--){
        shiftOut(_max7219din, _max7219clk, MSBFIRST, 0x00);
        shiftOut(_max7219din, _max7219clk, MSBFIRST, 0x00);
      }
    }

    digitalWrite(_max7219cs, HIGH);
}


// void Max7219::output(int display)
// {
//   digitalWrite(_max7219cs, LOW);
//   shiftOut(_max7219din, _max7219clk, MSBFIRST, _address);
//   shiftOut(_max7219din, _max7219clk, MSBFIRST, _data);
//   digitalWrite(_max7219cs, HIGH);
//
//   digitalWrite(_max7219cs, LOW);
//   shiftOut(_max7219din, _max7219clk, MSBFIRST, _address);
//   shiftOut(_max7219din, _max7219clk, MSBFIRST, _data);
//
//   shiftOut(_max7219din, _max7219clk, MSBFIRST, 0x00);
//   shiftOut(_max7219din, _max7219clk, MSBFIRST, 0x00);
//
//   digitalWrite(_max7219cs, HIGH);
// }

//  output(0x0f, 0x00); //display test register - test mode off
void Max7219::setTestModeOff(int display){
  setAddress(MAX7219_REG_ADD_DPTE);
  setData(MAX7219_TEST_MODE_OFF);
  output(display);
}

//  output(0x0f, 0x01); //display test register - test mode on
void Max7219::setTestModeOn(int display){
  setAddress(MAX7219_REG_ADD_DPTE);
  setData(MAX7219_TEST_MODE_ON);
  output(display);
}

//  output(0x0c, 0x00); //shutdown register - shutdown
void Max7219::setShutdownRegShut(int display){
  setAddress(MAX7219_REG_ADD_SHTD);
  setData(MAX7219_SHTD_REG_FOR_SHM);
  output(display);
  }

//  output(0x0c, 0x01); //shutdown register - normal operation
void Max7219::setShutdownRegNorm(int display){
  setAddress(MAX7219_REG_ADD_SHTD);
  setData(MAX7219_SHTD_REG_FOR_NOR);
  output(display);
}

// output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
void Max7219::setBrightness(int brightness, int display){
  setAddress(MAX7219_REG_ADD_BRIG);
  setData(brightness);
  output(display);
}

// output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
void Max7219::setLimitScanReg(int numDigits, int display){
  setAddress(MAX7219_REG_ADD_SCLT);
  setData(numDigits);
  output(display);
}

//  output(0x09, 0xff); //decode mode register - CodeB decode all digits
void Max7219::setDecodeMode(int decodeMode, int display){
  setAddress(MAX7219_REG_ADD_DECM);
  setData(decodeMode);
  output(display);
}

// Write text on display Max 8 Digit
void Max7219::writeNumInFontB(String a, int display){
  // empty 8 digits
  for(int x=1;x<=8;x++){
    setAddress(x);
    setData(15);
    output(display);
  }
  for(int x=0;x<a.length();x++){
    setAddress(a.length()-x);
    setData((int)a[x]);
    output(display);
  }
}
