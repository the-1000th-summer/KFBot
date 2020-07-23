#ifndef _KFBOT_KFWORKFLOW_H_
#define _KFBOT_KFWORKFLOW_H_

#include <arduino.h>
#include "KFMouse.h"

class KFWorkflow: public KFMouse {
private:
    /**/
public:
    KFWorkflow(LiquidCrystal lcddd);
    ~KFWorkflow();
    
    void getGold();
    void event();
    void event2();
    void mainQuest();
};



#endif
