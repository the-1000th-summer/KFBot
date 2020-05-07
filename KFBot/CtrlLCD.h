#ifndef _KFBOT_CTRLLCD_H_
#define _KFBOT_CTRLLCD_H_

#include <arduino.h>
#include <LiquidCrystal.h>
#include "KFWorkflow.h"

class CtrlLCD {
private:
    /* data */
    LiquidCrystal lcd = LiquidCrystal(7,6,5,4,3,2);
public:
    CtrlLCD();
    ~CtrlLCD();
    void bootTest();
    void controlWorkflow();
};



#endif