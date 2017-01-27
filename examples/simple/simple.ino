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

#include <m72198d.h>

#define MAX7219_DIN 5
#define MAX7219_CS  6
#define MAX7219_CLK 7
#define NUMDISP 1

Max7219 display1(MAX7219_DIN, MAX7219_CS, MAX7219_CLK, NUMDISP);

void setup() {
  // put your setup code here, to run once:
//  initialise();
//  output(0x0f, 0x00); //display test register - test mode off
  display1.begin(); // initialize and display test register - test mode off
//  output(0x0c, 0x01); //shutdown register - normal operation
//  output(0x0b, 0x07); //scan limit register - display digits 0 thru 7
//  output(0x0a, 0x0f); //intensity register - max brightness
//  output(0x09, 0xff); //decode mode register - CodeB decode all digits
//  output(0x08, 0x0c); //digit 7 (leftmost digit) data
//  output(0x07, 0x0b);
//  output(0x06, 0x0d);
//  output(0x05, 0x0e);
//  output(0x04, 0x08);
//  output(0x03, 0x07);
//  output(0x02, 0x06);
//  output(0x01, 0x05); //digit 0 (rightmost digit) data

}

void loop() {
  // put your main code here, to run repeatedly:

}
