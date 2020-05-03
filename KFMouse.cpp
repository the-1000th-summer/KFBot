#include "KFMouse.h"

// 此类的构造函数，创建实例时光标会移回原点。
KFMouse::KFMouse() {
    Serial.println("Led CREATED.");
    bTserial.begin(9600);
    delay(200);
    
    returnToO();
}
// 此类的析构函数，结束实例生命周期时打印提示信息。
KFMouse::~KFMouse() {
    Serial.println("Led DELETED.");
}

// 此方法移动
void KFMouse::moveByXYSteps(int xSteps, int ySteps) {
    byte stepLength = 10;
    byte xpm = xSteps < 0 ? -1 : 1;           // x plus or minus
    byte ypm = ySteps < 0 ? -1 : 1;           // y plus or minus
    
    for (int xStep = 0; xStep < abs(xSteps); xStep++) {
        moveByXYOneStep(stepLength * xpm, 0);
        delay(20);
    }
    for (int yStep = 0; yStep < abs(ySteps); yStep++) {
        moveByXYOneStep(0, stepLength * ypm);
        delay(20);
    }

    Serial.println("move completed.");
}

// 此方法约定为移动一个单位距离的光标
// 最少有一个参数为0
// Args:
//     x (byte): x方向上移动的“距离”，此工程默认为10。
//     y (byte): y方向上移动的“距离”，此工程默认为10。
void KFMouse::moveByXYOneStep(byte x, byte y) {
    generalAction(x, y, isPressing);
}

void KFMouse::moveToXYSteps(int x, int y) {

}

// 此方法执行鼠标点击左键的操作。
void KFMouse::click() {
    generalAction(0, 0, true);
    generalAction(0, 0, false);
}

// 此方法按下鼠标左键并且不放开。
void KFMouse::press() {
    generalAction(0, 0, true);
}

// 此方法释放左键。
void KFMouse::release() {
    generalAction(0, 0, false);
}

// 此方法使光标返回原点。
void KFMouse::returnToO() {
    for (byte i = 0; i < 5; i++) {
        generalAction(-100, -100, false);
    }
    nowX = nowY = 0;
}

// 此方法点击“出撃”按钮。
void KFMouse::clickSyutsuGeki() {
    returnToO();
    moveByXYSteps(75, 42);
    click();
}
// 
void KFMouse::attack_1() {
    returnToO();
    moveByXYSteps(37, 40);
    click();
    delay(200);
    click();
}
// 此方法执行一般的鼠标操作。
void KFMouse::generalAction(byte x, byte y, bool pressing) {
    byte byte5 = pressing ? 0x01 : (byte)0x00;
    bTserial.write(0x08);          //BYTE1
    bTserial.write((byte)0x00);    //BYTE2
    bTserial.write(0xA1);          //BYTE3
    bTserial.write(0x02);          //BYTE4
    bTserial.write(byte5);    //BYTE5, Button (1, 2, 3)
    bTserial.write(x);             //BYTE6, X-Axis (-127~127)
    bTserial.write(y);             //BYTE7, Y-Axis (-127~127)
    bTserial.write((byte)0);       //BYTE8, Wheel

    isPressing = pressing;
}
