#include <Wire.h>
#include <RTClib.h>
#include "GrowLight.h"

// initiate RTC module object
RTC_DS3231 rtc;

// IO pins
int relayOne = 10;
int relayTwo = 11;
int relayThree= 12;
int buttonOne = 2;
int buttonTwo = 3;
int buttonThree = 4;

// self-defined grow-lights object
GrowLight lightOne(relayOne, 8, 21);
GrowLight lightTwo(relayTwo, 8, 21);
GrowLight lightThree(relayThree, 8, 21);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    
    // begin RTC
    rtc.begin();
    
    if (rtc.lostPower()) {
        Serial.println("RTC lost power, lets set the time!");
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    
    // declare IO
    pinMode(buttonOne, INPUT_PULLUP);
    pinMode(buttonTwo, INPUT_PULLUP);
    pinMode(buttonThree, INPUT_PULLUP);

    Serial.begin(9600);

    // pause before starting to control the lights
    // delay(3000);
    delay(300);
}

void loop() {
    // Retrieve the current time.
    DateTime now = rtc.now();
    
    // Check the current time against the time limits
    lightOne.updateLights(now.hour());
    lightTwo.updateLights(now.hour());
    lightThree.updateLights(now.hour());
    
    // Check time every 15 sec, otherwise look for button presses
    int checkTimeDelay = 2000;
    unsigned long start_timer = millis();
    unsigned long end_timer = start_timer;
    while(end_timer >= start_timer && checkTimeDelay > (end_timer - start_timer)) {

        if (
            checkButtonForLight(buttonOne, &lightOne) == LOW ||
            checkButtonForLight(buttonTwo, &lightTwo) == LOW ||
            checkButtonForLight(buttonThree, &lightThree) == LOW
        ) {
            delay(500);
            break;
        }
        
        delay(50);
        end_timer = millis();
    }
    
    Serial.println("(end of cycle)");
}


// Check if the `button` is pressed. If it is, toggle the
// lights `gl` override switch.
int checkButtonForLight(int button, GrowLight *gl) {
    int buttonState = digitalRead(button);
    if (buttonState == LOW) {
            // Serial.print("button pressed: ");
            // Serial.println(button);
            DateTime now = rtc.now();
            gl->overrideLights(now.hour());
        }
    return buttonState;
}
