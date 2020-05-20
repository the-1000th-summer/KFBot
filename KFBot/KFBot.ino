#include "CtrlLCD.h"

CtrlLCD myLCD = CtrlLCD();
// int a = 0;
void setup() {
    Serial.begin(9600);
    delay(200);
    myLCD.bootTest();
    
    Serial.println("start!  ");
    attachInterrupt(1, tryInt, FALLING);          // int.1，代表引脚3

    
}

void loop() {
    myLCD.controlWorkflow();

    // myLCD.debugUsingKeyboard();

}

void tryInt() {
    Serial.println("Interrupt");
    while (true) {
        while (digitalRead(3) == LOW) {}  // 处理掉长按，松手才继续执行，防止同时按下退出中断按钮
        // 不可用中断的引脚按钮跳出循环继续代码
        // 若这么做，按下这个第二次按钮后无任何反应，
        // 按下第三次按钮后会退出中断，但紧接着进入第二次中断
        // 按下第四次按钮后退出第二次中断，紧接着进入第三次中断，以此类推
        if (digitalRead(A2) == LOW) {
            Serial.println("enter!");
            while (digitalRead(A2) == LOW) {}   // 处理掉长按，松手才继续执行，退出中断
            Serial.println("release");
            break;
        }
    }
    Serial.println("Continue");
}

