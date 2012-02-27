// Get date and time using a DS1307, DS1337 or DS1340 RTC connected via I2C


#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;    // Uncommnt this line if you are using the DS1307 chip or only use the basic functions of DS1337, DS1340, Chronodot (DS3132)
// RTC_DS1340 RTC;    // Uncomment this line if you are using the DS1340 chip
// Chronodot RTC;     // Uncomment this line if you are using the Chronodot (DS3132) 


void setup () {
    Serial.begin(57600); // Set serial port speed
    Wire.begin(); // Start the I2C
    RTC.begin(); // Init RTC
}

void loop () {
    DateTime now = RTC.now(); // Read the time and date from the DS1340
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    delay(3000);
}