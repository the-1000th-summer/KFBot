#ifndef _KFBOT_GENERALMOUSE_H_
#define _KFBOT_GENERALMOUSE_H_

#include <Arduino.h>
#include <SoftwareSerial.h>

class GeneralMouse {
    private:
        SoftwareSerial bTserial = SoftwareSerial(10, 11);     // RX, TX
        bool isPressing = false;
        byte nowXc = 0;
        byte nowYc = 0;
        void generalAction(byte x, byte y, bool pressing);
        void moveByXYOneStep(byte x, byte y);
    public:
        GeneralMouse();
        ~GeneralMouse();

        void moveByXYSteps(int x, int y);
        void moveToXYSteps(int x, int y);
        void click();
        void doubleClick();
        void press();
        void release();
        void returnToO();
        void wait(byte waitSec);


};


#endif
