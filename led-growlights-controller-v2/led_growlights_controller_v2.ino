#include <Wire.h>
#include <RTClib.h>
#include <Time.h>
#include <sunGrowLight.h>

// initiate RTC module object
RTC_DS3231 rtc;

// Johannesburg, South Africa (in Northern hemisphere)
#define SA_LAT    26.195246
#define SA_LONG   28.034088
#define SA_TZ     120

// Joshua Tree National Park, California, USA
#define JT_LAT    33.881866
#define JT_LONG  -115.900650
#define JT_TZ    -420

// Los Angeles, California, USA
#define LA_LAT    34.052235
#define LA_LONG  -118.243683
#define LA_TZ    -420


// IO pins
int relayOne = 10;
int relayTwo = 11;
int relayThree = 12;
int buttonOne = 2;
int buttonTwo = 3;
int buttonThree = 4;

// self-defined grow-lights object
sunGrowLight lightOne(relayOne, SA_LAT, SA_LONG, SA_TZ);
sunGrowLight lightTwo(relayTwo, JT_LAT, JT_LONG, JT_TZ);
sunGrowLight lightThree(relayThree, LA_LAT, LA_LONG, LA_TZ);

void setup() {

    Serial.begin(9600);
    Serial.print("Setting up... ");
    
    pinMode(LED_BUILTIN, OUTPUT);
    
    // begin RTC
    rtc.begin();
    
    if (false) {
        Serial.println("Reseting RTC time and date.");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    
    // declare IO
    pinMode(buttonOne, INPUT_PULLUP);
    pinMode(buttonTwo, INPUT_PULLUP);
    pinMode(buttonThree, INPUT_PULLUP);

    // pause before starting to control the lights
    delay(3000);

    Serial.println("done.");
}

void loop() {
    // Retrieve the current time.
    DateTime now_dt = rtc.now();

    // A function to help with troubleshooting.
    printSunriseSunsetDateTimes(now_dt);
    
    // Check the current time against the time limits
    lightOne.updateLights(now_dt.unixtime());
    lightTwo.updateLights(now_dt.unixtime());
    lightThree.updateLights(now_dt.unixtime());
    
    // Check time every 15 sec, otherwise look for button presses
    int checkTimeDelay = 2000;
    unsigned long start_timer = millis();
    unsigned long end_timer = start_timer;
    while(end_timer >= start_timer && checkTimeDelay > (end_timer - start_timer)) {

        if (
            checkButtonForLight(buttonOne, &lightOne, now_dt) == LOW ||
            checkButtonForLight(buttonTwo, &lightTwo, now_dt) == LOW ||
            checkButtonForLight(buttonThree, &lightThree, now_dt) == LOW
        ) {
            delay(500);
            break;
        }
        
        delay(50);
        end_timer = millis();
    }
    
//    Serial.println("(end of cycle)");
}


// Check if the `button` is pressed. If it is, toggle the
// lights `gl` override switch.
int checkButtonForLight(int button, sunGrowLight *gl, DateTime now_dt) {
    int buttonState = digitalRead(button);
    if (buttonState == LOW) {
            gl->overrideLights(now_dt.unixtime());
        }
    return buttonState;
}


void printDate(time_t date) {
    char buff[20];
    sprintf(buff, "%2d-%02d-%4d %02d:%02d:%02d",
    day(date), month(date), year(date), hour(date), minute(date), second(date));
    Serial.print(buff);
}


void printSunriseSunsetDateTimes(DateTime now_dt) {
    Serial.print("Current date time: ");
    Serial.println(now_dt.year());
    Serial.print("Current unixtime date time: ");
    printDate(now_dt.unixtime());
    Serial.println("");

    Serial.print("SA sunrise, sunset: ");
    printDate(lightOne.getSunriseDate(now_dt.unixtime()));
    Serial.print(", ");
    printDate(lightOne.getSunsetDate(now_dt.unixtime()));
    Serial.println("");
    Serial.print("JT sunrise, sunset: ");
    printDate(lightTwo.getSunriseDate(now_dt.unixtime()));
    Serial.print(", ");
    printDate(lightTwo.getSunsetDate(now_dt.unixtime()));
    Serial.println("");
    Serial.print("LA sunrise, sunset: ");
    printDate(lightThree.getSunriseDate(now_dt.unixtime()));
    Serial.print(", ");
    printDate(lightThree.getSunsetDate(now_dt.unixtime()));
    Serial.println("\n");
}
