
#ifndef _KFBOT_KFMOUSE_
#define _KFBOT_KFMOUSE_

#include <Arduino.h>
#include "GeneralMouse.h"

class KFMouse: public GeneralMouse {
    private:
        /* data */
    public:
        KFMouse(/* args */);
        ~KFMouse();

        void clickSyutsuGeki();    // 出撃
        void attack(byte i);
        void swipeToSupportPage();
        void selectOrb(byte i);
        void selectCancel();
        void selectOK();
        void selectOrbChar(byte i);
        void combatAgain();
};



#endif