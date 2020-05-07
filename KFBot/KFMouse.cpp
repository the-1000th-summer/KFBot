#include "KFMouse.h"

// 此类的构造函数，无默认构造函数
KFMouse::KFMouse(LiquidCrystal lcddd) : lcdd(lcddd) {
}

// 此类的析构函数
KFMouse::~KFMouse() {}

// 此方法清空液晶屏第二行并写入新字符串
void KFMouse::write2ndRow(String rowStr) {
    lcdd.setCursor(0, 1);
    for (byte i = 0; i < 16; i++) lcdd.write('\x20');
    lcdd.setCursor(0, 1);
    // lcdd.clear();
    lcdd.print(rowStr);
}

// 此方法点击“出撃”按钮。
void KFMouse::clickSyutsuGeki() {
    write2ndRow("Start attack!");
    moveToXYSteps(75, 42);
    click();
}

// 此方法点击战斗界面中技能按钮。
// Args:
//     i (byte): 左起第i个技能按钮
void KFMouse::attack(byte i) {
    // 注释掉的代码的方法会导致Arduino直接重启，原因未知
    // 以下方法中注释掉的代码同理
    // char sNStr[1];
    // itoa(i, sNStr, 10);
    // write2ndRow("Attack_" + (String)sNStr);
    switch (i) {
    case 1:
        write2ndRow("Attack_1");
        moveToXYSteps(37, 40);
        break;
    case 2:
        write2ndRow("Attack_2");
        moveToXYSteps(46, 40);
        break;
    case 3:
        write2ndRow("Attack_3");
        moveToXYSteps(54, 40);
        break;
    case 4:
        write2ndRow("Attack_4");
        moveToXYSteps(63, 40);
        break;
    default:
        return;
    }
    doubleClick();
}

// 此方法执行右滑并进入琪拉拉宝珠使用页面
void KFMouse::swipeToSupportPage() {
    write2ndRow("Swipe to SptPage");

    moveToXYSteps(74, 40);
    press();
    moveToXYSteps(82, 40);
    release();
}

// 此方法选择一个琪拉拉宝珠技能。
// Args:
//     i (byte): 从上往下数第i个技能
void KFMouse::selectOrb(byte i) {
    // char sNStr[1];
    // write2ndRow("select Orb " + (String)itoa(i, sNStr, 10));
    // write2ndRow("select Orb ");

    switch (i) {
    case 1:
        write2ndRow("select Orb 1");
        moveToXYSteps(45, 20);
        break;
    case 2:
        write2ndRow("select Orb 2");
        moveToXYSteps(45, 30);
        break;
    case 3:
        write2ndRow("select Orb 3");
        moveToXYSteps(45, 40);
        break;
    default:
        break;
    }
    click();
}

void KFMouse::selectMySupport(byte i) {
    // char sNStr[1];
    // write2ndRow("Select spter " + (String)itoa(i, sNStr, 10));

    switch (i) {
    case 1:
        write2ndRow("Select spter 1");
        moveToXYSteps(75, 15);
        break;
    case 2:
        write2ndRow("Select spter 2");
        moveToXYSteps(75, 35);
    default:
        return;
    }
    click();
}

// 此方法点击弹出警告框的左边的按钮（一般为取消按钮）。
void KFMouse::selectCancel() {
    write2ndRow("Select cancel");
    moveToXYSteps(35, 30);
    click();
}

// 此方法点击弹出警告框的右边的按钮（一般为确认按钮）。
void KFMouse::selectOK() {
    write2ndRow("Select OK");
    moveToXYSteps(50, 30);
    click();
}

// 此方法点击使琪拉拉宝珠技能作用于某角色上
// Args:
//     i (byte): 从左往右数第i个角色
void KFMouse::selectOrbChar(byte i) {
    // char sNStr[1];
    // write2ndRow("Select OrbChar " + (String)itoa(i, sNStr, 10));

    switch (i) {
    case 1:
        write2ndRow("Select OrbChar 1");
        moveToXYSteps(32, 23);
        break;
    case 2:
        write2ndRow("Select OrbChar 2");
        moveToXYSteps(42, 23);
        break;
    case 3:
        write2ndRow("Select OrbChar 3");
        moveToXYSteps(52, 23);
        break;
    default:
        break;
    }
    click();
}

void KFMouse::combatAgain() {
    write2ndRow("Combat again!");
    moveToXYSteps(30, 43);
    click();
}
