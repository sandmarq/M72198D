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

void Max7219::init()
{
  digitalWrite(_max7219cs, HIGH);
  pinMode(_max7219din, OUTPUT);
  pinMode(_max7219cs, OUTPUT);
  pinMode(_max7219clk, OUTPUT);
  setaddress(MAX7212_REG_ADD_DPTE);
  setdata(MAX7212_REG_ADD_NOOP);
  output();
}

void Max7219::output()
{
  digitalWrite(_max7219cs, LOW);
  shiftOut(_max7219din, _max7219clk, MSBFIRST, _address);
  shiftOut(_max7219din, _max7219clk, MSBFIRST, _data);
  digitalWrite(_max7219cs, HIGH);
}
