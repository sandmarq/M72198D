/*
  m72198d.h - MAX7219 8-Digit LED Display 7 Segment For Arduino Library.
  Created by Sandrine Marquis, 27 janvier, 2017.
*/

#ifndef m72198d_h
#define m72198d_h

#if ARDUINO >= 100
 #include "Arduino.h"
 #define WIRE_WRITE Wire.write
#else
 #include "WProgram.h"
 #define WIRE_WRITE Wire.send
#endif

#if defined(ESP8266) || defined(ESP32)
  typedef volatile uint32_t PortReg;
  typedef uint32_t PortMask;
#endif

/*
Max7219 register address map
*/
#define MAX7219_REG_ADD_NOOP             0x00
#define MAX7219_REG_ADD_DIG0             0x01
#define MAX7219_REG_ADD_DIG1             0x02
#define MAX7219_REG_ADD_DIG2             0x03
#define MAX7219_REG_ADD_DIG3             0x04
#define MAX7219_REG_ADD_DIG4             0x05
#define MAX7219_REG_ADD_DIG5             0x06
#define MAX7219_REG_ADD_DIG6             0x07
#define MAX7219_REG_ADD_DIG7             0x08
#define MAX7219_REG_ADD_DECM             0x09
#define MAX7219_REG_ADD_BRIG             0x0A
#define MAX7219_REG_ADD_SCLT             0x0B
#define MAX7219_REG_ADD_SHTD             0x0C
#define MAX7219_REG_ADD_DPTE             0x0f

/*
Max7219 Test Mode
*/
#define MAX7219_TEST_MODE_ON             0xFF
#define MAX7219_TEST_MODE_OFF            0x00

/*
Max7219 Shutdown Register Format
*/
#define MAX7219_SHTD_REG_FOR_SHM         0x00
#define MAX7219_SHTD_REG_FOR_NOR         0x01

/*
Max7219 Decode-Mode Register Example
*/
#define MAX7219_DEC_MOD_REG_NDC70        0x00
#define MAX7219_DEC_MOD_REG_CB0_NDC71    0x01
#define MAX7219_DEC_MOD_REG_CB30_NDC74   0x0F
#define MAX7219_DEC_MOD_REG_CB70         0xFF

/*
Max7219 Code B Font Register Data
*/
#define MAX7219_CODEB_FONT_REG_0             0x00
#define MAX7219_CODEB_FONT_REG_1             0x01
#define MAX7219_CODEB_FONT_REG_2             0x02
#define MAX7219_CODEB_FONT_REG_3             0x03
#define MAX7219_CODEB_FONT_REG_4             0x04
#define MAX7219_CODEB_FONT_REG_5             0x05
#define MAX7219_CODEB_FONT_REG_6             0x06
#define MAX7219_CODEB_FONT_REG_7             0x07
#define MAX7219_CODEB_FONT_REG_8             0x08
#define MAX7219_CODEB_FONT_REG_9             0x09
#define MAX7219_CODEB_FONT_REG__             0x0A
#define MAX7219_CODEB_FONT_REG_E             0x0B
#define MAX7219_CODEB_FONT_REG_H             0x0C
#define MAX7219_CODEB_FONT_REG_L             0x0D
#define MAX7219_CODEB_FONT_REG_P             0x0E

/*
Max7219 Code B Font Register On Segment = 1
*/
#define MAX7219_CODEB_FONT_SEG_0             0x7E
#define MAX7219_CODEB_FONT_SEG_1             0x30
#define MAX7219_CODEB_FONT_SEG_2             0x33
#define MAX7219_CODEB_FONT_SEG_3             0x79
#define MAX7219_CODEB_FONT_SEG_4             0x33
#define MAX7219_CODEB_FONT_SEG_5             0x5B
#define MAX7219_CODEB_FONT_SEG_6             0x5F
#define MAX7219_CODEB_FONT_SEG_7             0x70
#define MAX7219_CODEB_FONT_SEG_8             0x7F
#define MAX7219_CODEB_FONT_SEG_9             0x7B
#define MAX7219_CODEB_FONT_SEG__             0x01
#define MAX7219_CODEB_FONT_SEG_E             0x4F
#define MAX7219_CODEB_FONT_SEG_H             0x37
#define MAX7219_CODEB_FONT_SEG_L             0x0E
#define MAX7219_CODEB_FONT_SEG_P             0x67
#define MAX7219_CODEB_FONT_SEG_C             0x4E
#define MAX7219_CODEB_FONT_SEG_F             0x47
#define MAX7219_CODEB_FONT_SEG               0x00
/*
Max7219 Intensity
*/
#define MAX7219_INTE_MAX                     0x0F
#define MAX7219_INTE_MED                     0x07
#define MAX7219_INTE_MIN                     0x00

/*
Max7219 Scan-Limit Register
*/
#define MAX7219_NUM_DIGIT_1                  0x00
#define MAX7219_NUM_DIGIT_2                  0x01
#define MAX7219_NUM_DIGIT_3                  0x02
#define MAX7219_NUM_DIGIT_4                  0x03
#define MAX7219_NUM_DIGIT_5                  0x04
#define MAX7219_NUM_DIGIT_6                  0x05
#define MAX7219_NUM_DIGIT_7                  0x06
#define MAX7219_NUM_DIGIT_8                  0x07

/*
main class
*/

class Max7219
{
  public:
    Max7219(int max7219din=5, int max7219cs=6, int max7219clk=7, int numdisp=1);
    void init(void);
    void setAddress(byte address);
    void setData(byte address);
    void output(void);
    void setTestModeOff(void);
    void setTestModeOn(void);
    void setShutdownRegShut(void);
    void setShutdownRegNorm(void);
    void setLimitScanReg(int numDigits=MAX7219_NUM_DIGIT_8);
    void setBrightness(int brightness=MAX7219_INTE_MAX);
    void setDecodeMode(int decodeMode=MAX7219_DEC_MOD_REG_CB70);
    void writeNumInFontB(void);

  private:
    int _max7219din;
    int _max7219cs;
    int _max7219clk;
    int _numdisp;
    byte _address;
    byte _data;
};

#endif
