#include "CtrlLCD.h"

CtrlLCD myLCD = CtrlLCD();

void setup() {
    Serial.begin(9600);
    delay(200);
    myLCD.bootTest();
    
    Serial.println("start!  ");

}

void loop() {
    myLCD.controlWorkflow();

    // myLCD.debugUsingKeyboard();

}
