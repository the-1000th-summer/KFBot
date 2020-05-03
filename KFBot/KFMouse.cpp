#include "KFMouse.h"

// 此类的构造函数
KFMouse::KFMouse() {
}
// 此类的析构函数
KFMouse::~KFMouse() {
}

// 此方法点击“出撃”按钮。
void KFMouse::clickSyutsuGeki() {
    moveToXYSteps(75, 42);
    click();
}
// 此方法点击战斗界面中技能按钮。
// Args:
//     i (byte): 左起第i个技能按钮
void KFMouse::attack(byte i) {
    switch (i) {
    case 1:
        moveToXYSteps(37, 40);
        break;
    case 2:
        moveToXYSteps(46, 40);
        break;
    case 3:
        moveToXYSteps(54, 40);
        break;
    case 4:
        moveToXYSteps(63, 40);
        break;
    
    default:
        return;
    }
    doubleClick();
}
// 此方法执行右滑并进入琪拉拉宝珠使用页面
void KFMouse::swipeToSupportPage() {
    moveToXYSteps(74, 40);
    press();
    moveToXYSteps(82, 40);
    release();
}

// 此方法选择一个琪拉拉宝珠技能。
// Args:
//     i (byte): 从上往下数第i个技能
void KFMouse::selectOrb(byte i) {
    switch (i) {
    case 1:
        moveToXYSteps(45, 20);
        break;
    case 2:
        moveToXYSteps(45, 30);
        break;
    case 3:
        moveToXYSteps(45, 40);
        break;
    default:
        break;
    }
    click();
}

// 此方法点击弹出警告框的左边的按钮（一般为取消按钮）。
void KFMouse::selectCancel() {
    moveToXYSteps(35, 30);
    click();
}

// 此方法点击弹出警告框的右边的按钮（一般为确认按钮）。
void KFMouse::selectOK() {
    moveToXYSteps(50, 30);
    click();
}

// 此方法点击使琪拉拉宝珠技能作用于某角色上
// Args:
//     i (byte): 从左往右数第i个角色
void KFMouse::selectOrbChar(byte i) {
    switch (i) {
    case 1:
        moveToXYSteps(32, 23);
        break;
    case 2:
        moveToXYSteps(42, 23);
        break;
    case 3:
        moveToXYSteps(52, 23);
        break;
    default:
        break;
    }
    click();
}

void KFMouse::combatAgain() {
    moveToXYSteps(30, 43);
    click();
}
