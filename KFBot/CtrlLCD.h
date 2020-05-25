#ifndef _KFBOT_CTRLLCD_H_
#define _KFBOT_CTRLLCD_H_

#include <arduino.h>
#include <LiquidCrystal.h>
#include "KFWorkflow.h"

class CtrlLCD {
private:
    // static CtrlLCD *instance;
public:
    LiquidCrystal lcd = LiquidCrystal(9,8,7,6,5,4);
    KFWorkflow myWorkflow = KFWorkflow(lcd);
    CtrlLCD();
    ~CtrlLCD();
    void bootTest();
    void controlWorkflow();
    void debugUsingKeyboard();
};

#endif
