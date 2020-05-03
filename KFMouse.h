#ifndef _KFBOT_KFMOUSE_
#define _KFBOT_KFMOUSE_

#include <Arduino.h>
#include <SoftwareSerial.h>

class KFMouse {
    private:
        SoftwareSerial bTserial = SoftwareSerial(2, 3);
        bool isPressing = false;
        byte nowX = 0;
        byte nowY = 0;
        void generalAction(byte x, byte y, bool pressing);
        // void moveBy
    public:
        KFMouse();
        ~KFMouse();
        void moveByXYSteps(int x, int y);
        void moveByXYOneStep(byte x, byte y);
        void moveToXYSteps(int x, int y);
        void click();
        void press();
        void release();
        void returnToO();
        void clickSyutsuGeki();    // 出撃
        void attack_1();
};


#endif
