#ifndef _KFBOT_KFWORKFLOW_
#define _KFBOT_KFWORKFLOW_

#include <arduino.h>
#include "KFMouse.h"

class KFWorkflow: public KFMouse {
private:
    /* data */
public:
    KFWorkflow();
    ~KFWorkflow();
    
    void getGold();
};



#endif
