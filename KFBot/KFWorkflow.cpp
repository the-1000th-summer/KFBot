#include "KFWorkflow.h"

// 此类的构造函数
KFWorkflow::KFWorkflow() {
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
        attack(1);
        delay(4000);
        attack(1);
        delay(7000);
        attack(2);
        delay(4000);
        attack(3);
        delay(7000);
        swipeToSupportPage();
        delay(1000);
        selectOrb(3);
        delay(500);
        selectOK();
        delay(1000);
        selectOrbChar(2);
        delay(3000);
        attack(1);
        delay(3000);
        attack(2);
        delay(3000);
        swipeToSupportPage();
        delay(1000);
        selectMySupport(1);
        delay(3000);
        attack(1);
        delay(15000);
        click();
        delay(5000);
        click();
        delay(1000);
        click();
        delay(1000);
        combatAgain();
        delay(10000);
    }
}

