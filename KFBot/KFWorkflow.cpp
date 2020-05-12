#include "KFWorkflow.h"

// 此类的构造函数，无默认构造函数
KFWorkflow::KFWorkflow(LiquidCrystal lcddd) : KFMouse(lcddd) {
}

// 此类的析构函数
KFWorkflow::~KFWorkflow() {
}

// 此方法用于完成任务「黄金平原」。
void KFWorkflow::getGold() {
    clickSyutsuGeki();
    selectOK();
    delay(10000);
    while (true) {
        attackAndWait(1, 4);
        attackAndWait(1, 7);
        attackAndWait(2, 4);
        attackAndWait(3, 7);
        useOrb(3, true, 2);

        attackAndWait(1, 3);
        attackAndWait(2, 3);
        getMySupport(1);

        attackAndWait(1, 15);
        clickRptAndCombatAgain();
    }
}

// 此方法用于完成活动任务。
void KFWorkflow::event() {
    clickSyutsuGeki();
    delay(10000);
    while (true) {
        attackAndWait(1, 7);
        attackAndWait(3, 7);
        useOrb(3, true, 2);
        attackAndWait(1, 15);
        clickRptAndCombatAgain();
    }
}

