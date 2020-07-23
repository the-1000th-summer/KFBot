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
    wait(10);
    while (true) {
        attackAndWait(1, 4);
        attackAndWait(1, 6);
        
        useOrb(3, true, 3);
        attackAndWait(1, 4);
        getMySupport(1);
        attackAndWait(1, 4);
        attackAndWait(1, 6);

        attackAndWait(3, 4);
        attackAndWait(2, 4);
        selectTotteOki(1);

        wait(12);
        clickRptAndCombatAgain();
    }
}

// 此方法用于完成活动任务。
void KFWorkflow::event() {
    clickSyutsuGeki();
    wait(10);
    while (true) {
        attackAndWait(1, 4);
        attackAndWait(1, 4);
        attackAndWait(1, 6);

        attackAndWait(3, 6);
        
        attackAndWait(4, 6);
        attackAndWait(2, 4);
        useOrb(3, true, 3);
        attackAndWait(1, 4);
        attackAndWait(4, 4);

        wait(12);
        clickRptAndCombatAgain();
    }
}

// 此方法用于完成活动极强敌任务
void KFWorkflow::event2() {
    clickSyutsuGeki();
    selectOK();
    wait(10);
    while (true) {
        attackAndWait(1, 5);
        attackAndWait(1, 6);
        attackAndWait(3, 6);
        attackAndWait(2, 4);
        attackAndWait(2, 5);
        attackAndWait(3, 4);

        wait(12);
        clickRptAndCombatAgain();
    }
}

void KFWorkflow::mainQuest() {
    clickSyutsuGeki();
    selectOK();
    wait(10);
    while (true) {
        attackAndWait(1, 4);
        attackAndWait(1, 6);

        attackAndWait(2, 4);
        attackAndWait(3, 6);

        attackAndWait(4, 4);
        useOrb(3, true, 1);
        attackAndWait(1, 4);
        attackAndWait(3, 2);

        wait(12);
        clickRptAndCombatAgain();
    }
}
