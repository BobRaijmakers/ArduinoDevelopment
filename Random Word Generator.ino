/*
  Arduino Starter Kit example
  Project 11 - Crystal Ball

  This sketch is written to accompany Project 11 in the Arduino Starter Kit

  Parts required:
  - 220 ohm resistor
  - 10 kilohm resistor
  - 10 kilohm potentiometer
  - 16x2 LCD screen
  - tilt switch

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

// include the library codes:
#include <LiquidCrystal.h>
#include <Bridge.h>
#include <HttpClient.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the tilt switch pin
const int switchPin = 6;

// variable to hold the value of the switch pin
int switchState = 0;

// variable to hold previous value of the switch pin
int prevSwitchState = 0;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
  
  // Turn on Serial Monitor
  Serial.begin(9600);

  // set up the switch pin as an input
  pinMode(switchPin, INPUT);
  
  // print to the second line
  lcd.print("Random Word");
  lcd.setCursor(1,1);
  lcd.print("Generator");
}

void loop() {
  HttpClient client;
  String request = "https://random-word-api.herokuapp.com/word?number=1&swear=0";
  client.get(request);
  Serial.println("Get command: " + request);

  Serial.println(client);
  
  while(client.available()){
    String payload = client.readString();
    Serial.println("Payload: " + payload);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print(payload);
  }
  delay(1000);  
}   
//      // choose a saying to print based on the value in reply
//      switch (reply) {
//        case 0:
//          lcd.print("Yes");
//          break;
//
//        case 1:
//          lcd.print("Most likely");
//          break;
//
//        case 2:
//          lcd.print("Certainly");
//          break;
//
//        case 3:
//          lcd.print("Outlook good");
//          break;
//
//        case 4:
//          lcd.print("Unsure");
//          break;
//
//        case 5:
//          lcd.print("Ask again");
//          break;
//
//        case 6:
//          lcd.print("Doubtful");
//          break;
//
//        case 7:
//          lcd.print("No");
//          break;
//      }
//    }
//  }
//  // save the current switch state as the last state
//  prevSwitchState = switchState;
//}
