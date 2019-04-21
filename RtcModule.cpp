#include "RtcModule.h"

#define bcd2bin(h, l) (((h) * 10) + (l))
#define bin2bcd_h(x) ((x) / 10)
#define bin2bcd_l(x) ((x) % 10)

#define dayOfWeek(_time_) (( _time_ / SECS_PER_DAY + 4)  % DAYS_PER_WEEK) // 0 = Sunday

#define DS1302_SECONDS 0x80
#define DS1302_MINUTES 0x82
#define DS1302_HOURS 0x84
#define DS1302_DATE 0x86
#define DS1302_MONTH 0x88
#define DS1302_DAY 0x8A
#define DS1302_YEAR 0x8C
#define DS1302_ENABLE 0x8E
#define DS1302_TRICKLE 0x90

#define DS1302_CLOCK_BURST 0xBE
#define DS1302_CLOCK_BURST_WRITE 0xBE
#define DS1302_CLOCK_BURST_READ 0xBF

#define DS1302_RAMSTART 0xC0
#define DS1302_RAMEND 0xFC
#define DS1302_RAM_BURST 0xFE
#define DS1302_RAM_BURST_WRITE 0xFE
#define DS1302_RAM_BURST_READ 0xFF

#define DS1302_D0 0
#define DS1302_D1 1
#define DS1302_D2 2
#define DS1302_D3 3
#define DS1302_D4 4
#define DS1302_D5 5
#define DS1302_D6 6
#define DS1302_D7 7

// Bit for reading (bit in address)
#define DS1302_READBIT DS1302_D0 // READBIT=1: read instruction

// Bit for clock (0) or ram (1) area, called R/C-bit (bit in address)
#define DS1302_RC DS1302_D6

// Seconds Register
#define DS1302_CH DS1302_D7 // 1 = Clock Halt, 0 = start

// Hour Register
#define DS1302_AM_PM DS1302_D5 // 0 = AM, 1 = PM
#define DS1302_12_24 DS1302 D7 // 0 = 24 hour, 1 = 12 hour

// Enable Register
#define DS1302_WP DS1302_D7 // 1 = Write Protect, 0 = enabled

// Trickle Register
#define DS1302_ROUT0 DS1302_D0
#define DS1302_ROUT1 DS1302_D1
#define DS1302_DS0 DS1302_D2
#define DS1302_DS1 DS1302_D2
#define DS1302_TCS0 DS1302_D4
#define DS1302_TCS1 DS1302_D5
#define DS1302_TCS2 DS1302_D6
#define DS1302_TCS3 DS1302_D7

RtcModule::RtcModule(byte clock, byte data, byte rst)
{
  this->clock = clock;
  this->data = data;
  this->rst = rst;
  
  DS1302_write (DS1302_ENABLE, 0); // Clearing the Write Protect bit.
  DS1302_write (DS1302_TRICKLE, 0x00); // Disable Trickle Charger.
}

String RtcModule::GetDateAndTime()
{
  String nameOfDay = GetNameOfDay(dayofweek);  
  return GetShortDate() + " (" + nameOfDay + ") " + GetShortTime();
}

String RtcModule::GetShortDate()
{
  return String(year) + "." + GetPreatyValue(month) + "." + GetPreatyValue(dayofmonth);
}

String RtcModule::GetLongDate()
{
  return String(year) + "." + GetNameOfMonth(month) + "." + GetPreatyValue(dayofmonth);
}

String RtcModule::GetShortTime()
{
  return GetPreatyValue(hours) + ":" + GetPreatyValue(minutes) + ":" + GetPreatyValue(seconds);
}

String RtcModule::GetPreatyValue(byte value)
{
  if (value < 10)
  {
    return "0" + String(value);
  }
  return String(value);
}

void RtcModule::SetDateAndTime(int year, byte month, byte day, byte hour, byte minute, byte second)
{
  byte dayOfWeek = GetDayOfWeek(year, month, day);
  SetDS1302Time(second, minute, hour, dayOfWeek, day, month, year);
}

void RtcModule::UpdateTime()
{
  DS1302_clock_burst_read((byte *) &rtc);
  
  seconds = (rtc.Seconds10  * 10) + rtc. Seconds;
  minutes = (rtc. Minutes10 * 10) + rtc.Minutes;
  hours = (rtc.h24.Hour10 * 10) + rtc.h24.Hour;
  dayofweek = (rtc.Day);
  dayofmonth = (rtc.Date10  * 10) + rtc.Date;
  month = (rtc.Month10 * 10) + rtc.Month;
  year = (rtc.Year10  * 10) + rtc.Year + 2000;
}

byte RtcModule::GetDayOfWeek(int year, byte month, byte day)
{
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  year -= month < 3;
  return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

String RtcModule::GetNameOfDay(byte day)
{
  switch (day)
  {
    case 0:
      return "Sunday";
    case 1:
      return "Monday";
    case 2:
      return "Tuesday";
    case 3:
      return "Wednesday";
    case 4:
      return "Thursday";
    case 5:
      return "Friday";
    case 6:
      return "Saturday";
    default:
      return "Unknown";
  }
}

String RtcModule::GetNameOfMonth(byte month)
{
  switch (month)
  {
    case 1:
      return "January";
    case 2:
      return "February";
    case 3:
      return "March";
    case 4:
      return "April";
    case 5:
      return "May";
    case 6:
      return "June";
    case 7:
      return "July";
    case 8:
      return "August";
    case 9:
      return "September";
    case 10:
      return "October";
    case 11:
      return "November";
    case 12:
      return "December";
    default:
      return "Unknown";
  }
}

// This function reads 8 bytes clock data in burst mode from the DS1302. This function may be called as the first function, also the pinMode is set.
void RtcModule::DS1302_clock_burst_read(byte *p)
{
  _DS1302_start();

  // Instead of the address, the CLOCK_BURST_READ command is issued the I/O-line is released for the data
  _DS1302_togglewrite(DS1302_CLOCK_BURST_READ, true);

  for (byte i = 0; i < 8; i++)
  {
    *p++ = _DS1302_toggleread();
  }
  _DS1302_stop();
}

// This function writes 8 bytes clock data in burst mode to the DS1302. This function may be called as the first function, also the pinMode is set.
void RtcModule::DS1302_clock_burst_write(byte *p)
{
  _DS1302_start();

  // Instead of the address, the CLOCK_BURST_WRITE command is issued. The I/O-line is not released
  _DS1302_togglewrite(DS1302_CLOCK_BURST_WRITE, false);

  for (byte i = 0; i < 8; i++)
  {
    // the I/O-line is not released
    _DS1302_togglewrite(*p++, false);
  }
  _DS1302_stop();
}

// This function reads a byte from the DS1302 (clock or ram). The address could be like "0x80" or "0x81", the lowest bit is set anyway. This function may be called as the first function, also the pinMode is set.
byte RtcModule::DS1302_read(int address)
{
  // set lowest bit (read bit) in address
  bitSet(address, DS1302_READBIT);

  _DS1302_start();
  // the I/O-line is released for the data
  _DS1302_togglewrite(address, true);
  byte data = _DS1302_toggleread();
  _DS1302_stop();

  return(data);
}

// This function writes a byte to the DS1302 (clock or ram). The address could be like "0x80" or "0x81", the lowest bit is cleared anyway. This function may be called as the first function, also the pinMode is set.
void RtcModule::DS1302_write(int address, byte data)
{
  // clear lowest bit (read bit) in address
  bitClear(address, DS1302_READBIT);

  _DS1302_start();

  // don't release the I/O-line
  _DS1302_togglewrite(address, false);

  // don't release the I/O-line
  _DS1302_togglewrite(data, false);
  _DS1302_stop();
}

// A helper function to setup the start condition. An 'init' function is not used.  But now the pinMode is set every time. That's not a big deal, and it's valid. At startup, the pins of the Arduino are high impedance. Since the DS1302 has pull-down resistors, the signals are low (inactive) until the DS1302 is used.
void RtcModule::_DS1302_start()
{
  digitalWrite(rst, LOW); // default, not enabled
  pinMode(rst, OUTPUT);

  digitalWrite(clock, LOW); // default, clock low
  pinMode(clock, OUTPUT);

  pinMode(data, OUTPUT);

  digitalWrite(rst, HIGH); // start the session
  delayMicroseconds(4); // tCC = 4us
}

// A helper function to finish the communication.
void RtcModule::_DS1302_stop(void)
{
  // Set CE low
  digitalWrite(rst, LOW);
  delayMicroseconds(4); // tCWH = 4us
}

// A helper function for reading a byte with bit toggle. This function assumes that the clock is still high.
byte RtcModule::_DS1302_toggleread()
{
  byte data = 0;

  for (byte i = 0; i <= 7; i++)
  {
    // Issue a clock pulse for the next databit. If the 'togglewrite' function was used before this function, the clock is already high.
    digitalWrite(clock, HIGH);
    delayMicroseconds(1);

    // Clock down, data is ready after some time.
    digitalWrite(clock, LOW);
    delayMicroseconds(1); // tCL=1000ns, tCDD=800ns

    // read bit, and set it in place in 'data' variable
    bitWrite(data, i, digitalRead(this->data));
  }
  return(data);
}

// A helper function for writing a byte with bit toggle.  The 'release' parameter is for a read after this write.  It will release the I/O-line and will keep the clock high.
void RtcModule::_DS1302_togglewrite(byte data, byte release)
{
  for (byte i = 0; i <= 7; i++)
  {
    // set a bit of the data on the I/O-line
    digitalWrite(this->data, bitRead(data, i));
    delayMicroseconds(1); // tDC = 200ns

    // clock up, data is read by DS1302
    digitalWrite(clock, HIGH);
    delayMicroseconds(1); // tCH = 1000ns, tCDH = 800ns

    // If this write is followed by a read, the I/O-line should be released after the last bit, before the clock line is made low. This is according the datasheet. I have seen other programs that don't release the I/O-line at this moment, and that could cause a shortcut spike on the I/O-line.
    if (release && i == 7)
    {
      pinMode(this->data, INPUT);
    }
    else
    {
      digitalWrite(clock, LOW);
      delayMicroseconds(1); // tCL=1000ns, tCDD=800ns
    }
  }
}

// A function to set the initial time within the DS1302 Real Time Clock.
void RtcModule::SetDS1302Time(byte seconds, byte minutes, byte hours, byte dayofweek, byte dayofmonth, byte month, int year)
{
  seconds = seconds;
  minutes = minutes;
  hours = hours;
  dayofweek = dayofweek;
  dayofmonth = dayofmonth;
  month = month;
  year = year;

  memset((char *) &rtc, 0, sizeof(rtc));

  rtc.Seconds = bin2bcd_l(seconds);
  rtc.Seconds10 = bin2bcd_h(seconds);
  rtc.CH = 0; // 1 for Clock Halt, 0 to run
  rtc.Minutes = bin2bcd_l(minutes);
  rtc.Minutes10 = bin2bcd_h(minutes);
  
  // To use the 12 hour format, use it like these four lines:
  //rtc.h12.Hour bin2bcd_l(hours);
  //rtc.h12.Hour10 = bin2bcd_h( hours);
  //rtc.h12.AM_PM = 0; AM = 0
  //rtc.h12.hour_12_24 = 1; // 1 for 24 hour format
  
  rtc.h24.Hour = bin2bcd_l(hours);
  rtc.h24.Hour10 = bin2bcd_h(hours);
  rtc.h24.hour_12_24 = 0; // 0 for 24 hour format
  
  rtc.Date = bin2bcd_l(dayofmonth);
  rtc.Date10 = bin2bcd_h(dayofmonth);
  rtc.Month = bin2bcd_l(month);
  rtc.Month10 = bin2bcd_h(month);
  rtc.Day = dayofweek;
  rtc.Year = bin2bcd_l(year - 2000);
  rtc.Year10 = bin2bcd_h(year - 2000);
  rtc.WP = 0;

  DS1302_clock_burst_write( (byte *) &rtc);
}
