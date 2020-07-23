
#ifndef _KFBOT_KFMOUSE_
#define _KFBOT_KFMOUSE_

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "GeneralMouse.h"

class KFMouse: public GeneralMouse {
    private:
        static KFMouse *instance;
    public:
        LiquidCrystal lcdd;

        KFMouse(LiquidCrystal lcddd);
        ~KFMouse();
        static void enterISR();

        void write2ndRow(String rowStr);
        void clickSyutsuGeki();    // 出撃
        void attack(byte skill_i);
        void tapSkill(byte skill_i);
        void swipeToSupportPage();
        void selectOrb(byte orb_i);
        void selectMySupport(byte spter_i);
        void selectCancel();
        void selectOK();
        void selectOrbChar(byte orbChar_i);
        void combatAgain();
        void selectEnemy(byte enemy_i);
        void selectAlly(byte ally_i);
        void selectTotteOki(byte char_i);
        void moveToNoBtnPlace();

        void attackAndWait(byte skill_i, byte waitSec);
        void useOrb(byte orb_i, bool shouldSelectChar, byte char_i);
        void getMySupport(byte spter_i);
        void clickRptAndCombatAgain();
};

#endif
