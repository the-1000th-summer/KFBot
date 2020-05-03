#include "KFMouse.h"

// SoftwareSerial bTserial = SoftwareSerial(2, 3);
KFMouse myMouse = KFMouse();

void setup() {
    Serial.begin(9600);
    // bTserial.begin(9600);
    delay(200);
    Serial.println("start!  ");
    
    // printByteData(-2);
}

void loop() {
    if (Serial.available() > 0) {
        while (Serial.available() > 0 ) {
            Serial.println("available!");
            char serialData = Serial.read();
            switch (serialData) {
            case 'w':
                Serial.println("w!");
                myMouse.moveByXYSteps(0, -10);
                break;
            case 's':
                Serial.println("s!");
                myMouse.moveByXYSteps(0, 10);
                break;
            case 'a':
                Serial.println("a!");
                myMouse.moveByXYSteps(-10, 0);
                break;
            case 'd':
                Serial.println("d!");
                myMouse.moveByXYSteps(10, 0);
                break;
            case 'o':
                Serial.println("return to origin!");
                myMouse.returnToO();
                break;
            case 't':
                myMouse.attack_1();
                break;
            default:
                break;
            }
        }
        Serial.println("End serial input.");
    }
    
}
