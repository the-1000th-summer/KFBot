
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
        void attack(byte skill_i);
        void swipeToSupportPage();
        void selectOrb(byte orb_i);
        void selectMySupport(byte spter_i);
        void selectCancel();
        void selectOK();
        void selectOrbChar(byte orbChar_i);
        void combatAgain();

        void attackAndWait(byte skill_i, byte waitSec);
        void useOrb(byte orb_i, bool shouldSelectChar, byte char_i);
        void getMySupport(byte spter_i);
        void clickRptAndCombatAgain();
};



#endif