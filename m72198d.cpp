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

void Max7219::setaddress(byte address)
{
  _address = address;
}

void Max7219::setdata(byte data)
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
  setaddress(MAX7212_REG_ADD_DPTE);
  setdata(MAX7212_REG_ADD_NOOP);
  output();

  //  output(0x0c, 0x01); //shutdown register - normal operation
  setaddress(MAX7212_REG_ADD_SHTD);
  setdata(MAX7219_SHTD_REG_FOR_NOR);
  output();

  // output(0x0b, 0x07); //scan limit register - display digits 7 thru 0
  setaddress(MAX7212_REG_ADD_SCLT);
  setdata(MAX7219_NUM_DIGIT_8);
  output();

  //  output(0x0a, 0x0f); //intensity register - max brightness
  setaddress(MAX7212_REG_ADD_BRIG);
  setdata(MAX7219_INTE_MAX);
  output();

  //  output(0x09, 0xff); //decode mode register - CodeB decode all digits
  setaddress(MAX7212_REG_ADD_DECM);
  setdata(MAX7219_DEC_MOD_REG_CB70);
  output();
}

void Max7219::output()
{
  digitalWrite(_max7219cs, LOW);
  shiftOut(_max7219din, _max7219clk, MSBFIRST, _address);
  shiftOut(_max7219din, _max7219clk, MSBFIRST, _data);
  digitalWrite(_max7219cs, HIGH);
}
