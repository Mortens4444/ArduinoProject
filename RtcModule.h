#ifndef RtcModule_h
#define RtcModule_h

#include "Arduino.h"
#include "stdio.h"
#include <stddef.h>
#include <string.h>
//#include "Time.h"

struct ds1302_struct
{
  byte Seconds:4; // 4-bits to hold low decimal digits 0-9
  byte Seconds10:3; // 3-bits to hold high decimal digit 0-5
  byte CH:1; // 1-bit to hold CH = Clock Halt
  byte Minutes:4; // 4-bits to hold low decimal digits 0-9
  byte Minutes10:3; // 3-bits to hold high decimal digit 0-5
  byte reserved1:1;
  union
  {
    struct
    { // 24-hour section
      byte Hour:4; // 4-bits to hold low decimal digits 0-9
      byte Hour10:2; // 2-bits to hold high decimal digits 0-2
      byte reserved2:1;
      byte hour_12_24:1; // 1-bit to set 0 for 24 hour format
    } h24;
    struct
    { // 12 hour section
      byte Hour:4; // 4-bits to hold low decimal digits 0-9
      byte Hour10:1; // 2-bits to hold high decimal digits 0-2
      byte AM_PM:1; // 1-bit to set AM or PM, 0 = AM, 1 = PM
      byte reserved2:1;
      byte hour_12_24:1; // 1-bit to set 1 for 12 hour format
    } h12;
  };
  byte Date:4; // 4-bits to hold low decimal digits 0-9
  byte Date10:2; // 2-bits to hold high decimal digits 0-3
  byte reserved3:2;
  byte Month:4; // 4-bits to hold low decimal digits 0-9
  byte Month10:1; // 3-bits to hold high decimal digits 0-5
  byte reserved4:3;
  byte Day:3; // 3-bits to hold decimal digit 1-7
  byte reserved5:5;
  byte Year:4; // 4-bits to hold high decimal digit 20
  byte Year10:4; // 4-bits to hold high decimal digit 14
  byte reserved6:7;
  byte WP:1; // WP = Write Protect
};

class RtcModule
{
  public:
    RtcModule(byte, byte, byte);
    
    void SetDateAndTime(int, byte, byte, byte, byte, byte);
    String GetDateAndTime();
    String GetShortDate();
    String GetLongDate();
    String GetShortTime();
    
    void UpdateTime();
    String GetNameOfDay(byte);
    String GetNameOfMonth(byte);    
    byte GetDayOfWeek(int, byte, byte);
    
    byte clock;
    byte data;
    byte rst;
    byte seconds;
    byte minutes;
    byte hours;
    byte dayofweek;
    byte dayofmonth;
    byte month;
    int year;
    
  private:
    String GetPreatyValue(byte);

    void DS1302_clock_burst_read(byte *); // Reads clock data, and sets pinmode
    void DS1302_clock_burst_write(byte *); // Writes clcok data, and sets pinmode
    byte DS1302_read(int); // Reads a byte from DS1302, sets pinmode
    void DS1302_write(int, byte); // Writes a byte to DS1302, sets pinmode
    void _DS1302_start(); // Function to help setup start condition
    void _DS1302_stop(); // Function to help stop the communication
    byte _DS1302_toggleread(); // Function to help read byte with bit
    void _DS1302_togglewrite(byte, byte); // Function to help wrtie byte with bit
    void SetDS1302Time(byte, byte, byte, byte, byte, byte, int); // This function sets the time on the DS1302

    ds1302_struct rtc; // Creates the Real Time Clock object
};

#endif
