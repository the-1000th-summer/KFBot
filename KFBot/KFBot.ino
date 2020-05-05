#include "KFWorkflow.h"

KFWorkflow myWorkflow = KFWorkflow();

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
                myWorkflow.moveByXYSteps(0, -10);
                break;
            case 's':
                Serial.println("s!");
                myWorkflow.moveByXYSteps(0, 10);
                break;
            case 'a':
                Serial.println("a!");
                myWorkflow.moveByXYSteps(-10, 0);
                break;
            case 'd':
                Serial.println("d!");
                myWorkflow.moveByXYSteps(10, 0);
                break;
            case 'o':
                Serial.println("return to origin!");
                myWorkflow.returnToO();
                break;
            case 'r':
                myWorkflow.clickSyutsuGeki();
                break;
            case 't':
                myWorkflow.attack(1);
                break;
            case 'y':
                myWorkflow.attack(2);
                break;
            case 'u':
                myWorkflow.attack(3);
                break;
            case 'i':
                myWorkflow.attack(4);
                break;
            case 'g':
                myWorkflow.swipeToSupportPage();
                break;
            case 'h':
                myWorkflow.selectOrb(3);
                break;
            case 'j':
                myWorkflow.selectCancel();
                break;
            case 'k':
                myWorkflow.selectOK();
                break;
            case 'b':
                myWorkflow.selectOrbChar(1);
                break;
            case 'n':
                myWorkflow.selectOrbChar(2);
                break;
            case 'm':
                myWorkflow.selectOrbChar(3);
                break;
            case 'p':
                myWorkflow.combatAgain();
                break;
            case 'l':
                myWorkflow.getGold();
                
                break;
            default:
                break;
            }
        }
        Serial.println("End serial input.");
    }
    
}
