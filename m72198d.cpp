/*
Software License Agreement (BSD License)

Copyright (c) 2012, Adafruit Industries
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holders nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
  m72198d.cpp - MAX7219 8-Digit LED Display 7 Segment For Arduino Library.
  Created by Sandrine Marquis, 27 janvier, 2017.
*/

#include "Arduino.h"
#include "m72198d.h"
#include "SPI.h"

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
