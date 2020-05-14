#include "KFMouse.h"

// 此类的构造函数，无默认构造函数
KFMouse::KFMouse(LiquidCrystal lcddd) : lcdd(lcddd) {
}

// 此类的析构函数
KFMouse::~KFMouse() {}

// 此方法清空液晶屏第二行并写入新字符串
// Args:
//     rowStr (String): 要写入的字符串
// Notes:
// 此方法暂时无用
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
//     skill_i (byte): 左起第skill_i个技能按钮
void KFMouse::attack(byte skill_i) {
    // 注释掉的代码的方法会导致Arduino直接重启，原因未知
    // 以下方法中注释掉的代码同理
    // char sNStr[1];
    // itoa(i, sNStr, 10);
    // write2ndRow("Attack_" + (String)sNStr);
    switch (skill_i) {
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

// 此方法只选中技能按钮但不释放技能，在补血等情况使用此方法
// Args:
//    skill_i (byte): 左起第skill_i个技能按钮
void KFMouse::tapSkill(byte skill_i) {
    switch (skill_i) {
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
    click();
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
void KFMouse::selectOrb(byte orb_i) {
    // char sNStr[1];
    // write2ndRow("select Orb " + (String)itoa(i, sNStr, 10));
    // write2ndRow("select Orb ");

    switch (orb_i) {
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

// 此方法点击琪拉拉宝珠界面指定的的supporter。
// Args:
//    spter_i (byte): 从上往下数第spter_i个supporter
void KFMouse::selectMySupport(byte spter_i) {
    // char sNStr[1];
    // write2ndRow("Select spter " + (String)itoa(i, sNStr, 10));

    switch (spter_i) {
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
//     orbChar_i (byte): 从左往右数第orbChar_i个角色
void KFMouse::selectOrbChar(byte orbChar_i) {
    // char sNStr[1];
    // write2ndRow("Select OrbChar " + (String)itoa(i, sNStr, 10));

    switch (orbChar_i) {
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

// 此方法点击「もう一度挑戦する」按钮
void KFMouse::combatAgain() {
    write2ndRow("Combat again!");
    moveToXYSteps(30, 43);
    click();
}

// 此方法选中某个敌人使其成为攻击对象
// Args:
//     enemy_i (byte): 左起第enemy_i个敌人
void KFMouse::selectEnemy(byte enemy_i) {
    switch (enemy_i) {
    case 1:
        moveToXYSteps(7, 23);
        break;
    case 2:
        moveToXYSteps(20, 23);
        break;
    case 3:
        moveToXYSteps(30, 23);
        break;
    default:
        break;
    }
    click();
}

// 此方法选中某个同伴
// Args:
//     ally_i (byte): 左起第ally_i个人物
void KFMouse::selectAlly(byte ally_i) {
    switch (ally_i) {
    case 1:
        moveToXYSteps(54, 20);
        break;
    case 2:
        moveToXYSteps(65, 20);
        break;
    case 3:
        moveToXYSteps(77, 20);
        break;
    default:
        break;
    }
    click();
}

// 此方法执行とっておき技能
// Args:
//     char_i (byte): 从上往下数第char_i个人物
void KFMouse::selectTotteOki(byte char_i) {
    moveToXYSteps(27, 40);
    click();
    moveToXYSteps(70, 8);
    click();
    moveToXYSteps(70, 42);
    click();
    delay(5000);
    click();
    delay(4000);
}

// 此方法执行组合动作：攻击并等待一定的时间（单位：秒）
// Args:
//     skill_i (byte): 左起第skill_i个技能按钮
//     waitSec (byte): 等待的秒数
void KFMouse::attackAndWait(byte skill_i, byte waitSec) {
    attack(skill_i);
    delay(waitSec * 1000);
}

// 此方法执行组合动作：使用オーブ
// Args:
//     orbNum (byte): 使用第几个orb
//     shouldSelectChar (bool): 是否需要选择orb作用的人物
//     charNum (byte): orb作用的人物（从左往右数第charNum个）
void KFMouse::useOrb(byte orb_i, bool shouldSelectChar, byte char_i) {
    swipeToSupportPage();
    delay(1000);
    selectOrb(orb_i);
    delay(500);
    selectOK();
    if (shouldSelectChar) {
        delay(1000);
        selectOrbChar(char_i);
    }
    delay(3000);
}

// 此方法执行组合动作：替换场上选中的任务为指定的supporter
// Args:
//    spter_i (byte): 从上往下数第spter_i个supporter
void KFMouse::getMySupport(byte spter_i) {
    swipeToSupportPage();
    delay(1000);
    selectMySupport(spter_i);
    delay(3000);
}

// 此方法执行组合动作：点击报告然后点击再次战斗按钮
void KFMouse::clickRptAndCombatAgain() {
    click();
    delay(5000);
    click();
    delay(1000);
    click();
    delay(1000);
    combatAgain();
    delay(10000);
}
