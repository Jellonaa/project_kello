#include <uRTCLib.h>
#include <LiquidCrystal.h>

void TimetoLcd();
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sunnuntai", "Maanantai", "Tiistai", "Keskiviikko", "Torstai", "Perjantai", "Lauantai"};
const int rs = 12, epin = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
//backlightpin?
LiquidCrystal lcd(rs, epin, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  delay(3000);
  URTCLIB_WIRE.begin();
  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // rtc.set(0, 53, 14, 4, 29, 3, 23);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)

}

void loop()
{
  lcd.setCursor(0,1);
  TimetoLcd();
}

  void TimetoLcd()
  {
    rtc.refresh();
    
    lcd.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
    lcd.print(" ");
    lcd.print(rtc.day());
    lcd.print('/');
    lcd.print(rtc.month());
    lcd.print('/');
    lcd.print(rtc.year());

    
    //lcd.println(daysOfTheWeek[rtc.dayOfWeek()-1]);
    

    lcd.print(" | klo: ");
    lcd.print(rtc.hour());
    lcd.print(':');
    lcd.print(rtc.minute());
    lcd.print(':');
    lcd.print(rtc.second());
    lcd.scrollDisplayLeft();
    delay(500);
  };
