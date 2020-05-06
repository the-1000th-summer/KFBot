#ifndef _KFBOT_KFWORKFLOW_H_
#define _KFBOT_KFWORKFLOW_H_

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
