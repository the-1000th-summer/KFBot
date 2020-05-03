#include "KFMouse.h"

KFMouse myMouse = KFMouse();

void setup() {
    Serial.begin(9600);

    delay(200);
    Serial.println("start!  ");
    
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
            case 'r':
                myMouse.clickSyutsuGeki();
                break;
            case 't':
                myMouse.attack(1);
                break;
            case 'y':
                myMouse.attack(2);
                break;
            case 'u':
                myMouse.attack(3);
                break;
            case 'i':
                myMouse.attack(4);
                break;
            case 'g':
                myMouse.swipeToSupportPage();
                break;
            case 'h':
                myMouse.selectOrb(3);
                break;
            case 'j':
                myMouse.selectCancel();
                break;
            case 'k':
                myMouse.selectOK();
                break;
            case 'b':
                myMouse.selectOrbChar(1);
                break;
            case 'n':
                myMouse.selectOrbChar(2);
                break;
            case 'm':
                myMouse.selectOrbChar(3);
                break;
            case 'p':
                myMouse.combatAgain();
                break;
            default:
                break;
            }
        }
        Serial.println("End serial input.");
    }
    
}
