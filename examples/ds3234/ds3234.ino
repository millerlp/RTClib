// Date and time functions using a DS3234 RTC connected via SPI 

#include <SPI.h>
#include <Wire.h>  // not used here, but needed to prevent a RTClib compile error
#include <RTClib.h>


// Avoid spurious warnings
#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))
#undef PSTR
#define PSTR(s) (__extension__({static prog_char __c[] PROGMEM = (s); &__c[0];}))

// Create an RTC instance, using the chip select pin it's connected to
RTC_DS3234 rtc(8);

void setup () {
    Serial.begin(57600);
    Serial.println("RTClib/examples/ds3234/");
    SPI.begin();
    rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("rtc is NOT running!");
    Serial.print("Setting time to... ");
    Serial.print(__DATE__);
    Serial.print(' ');
    Serial.println(__TIME__);
    // following line sets the rtc to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop () {
    const int len = 32;
    static char buf[len];

    DateTime now = rtc.now();

    Serial.println(now.toString(buf,len));
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");
    
    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now.unixtime() + 7 * 86400L + 30 );
    
    Serial.print(" now + 7d + 30s: ");
    Serial.println(future.toString(buf,len));
    
    Serial.println();
    delay(3000);
}
