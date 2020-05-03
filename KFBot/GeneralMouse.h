#ifndef _KFBOT_GENERALMOUSE_
#define _KFBOT_GENERALMOUSE_

#include <Arduino.h>
#include <SoftwareSerial.h>

class GeneralMouse {
    private:
        SoftwareSerial bTserial = SoftwareSerial(2, 3);
        bool isPressing = false;
        byte nowXc = 0;
        byte nowYc = 0;
        void generalAction(byte x, byte y, bool pressing);

    public:
        GeneralMouse();
        ~GeneralMouse();
        void moveByXYSteps(int x, int y);
        void moveByXYOneStep(byte x, byte y);
        void moveToXYSteps(int x, int y);
        void click();
        void doubleClick();
        void press();
        void release();
        void returnToO();

};


#endif
