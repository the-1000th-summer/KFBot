
#ifndef _KFBOT_KFMOUSE_
#define _KFBOT_KFMOUSE_

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "GeneralMouse.h"

class KFMouse: public GeneralMouse {
    private:
        
    public:
        LiquidCrystal lcdd;

        KFMouse(LiquidCrystal lcddd);
        ~KFMouse();

        void write2ndRow(String rowStr);
        void clickSyutsuGeki();    // 出撃
        void attack(byte i);
        void swipeToSupportPage();
        void selectOrb(byte i);
        void selectMySupport(byte i);
        void selectCancel();
        void selectOK();
        void selectOrbChar(byte i);
        void combatAgain();
};



#endif