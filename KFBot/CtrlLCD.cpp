#include "CtrlLCD.h"

// 此类的构造函数
CtrlLCD::CtrlLCD() {
    lcd.begin(16, 2);      // 每行16个字符，共2行
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    Serial.println("lcd created.");
}

// 此类的析构函数
CtrlLCD::~CtrlLCD() {
    Serial.println("lcd deleted.");
}

// 此方法用于开机测试：在所有字符格子中显示笑脸
void CtrlLCD::bootTest() {
    byte smiley[8] = {    // 1表示亮，0表示不亮
        B00000,
        B10001,
        B00000,
        B00000,
        B10001,
        B01110,
        B00000,
    };
    
    int x = 0;
    lcd.createChar(x, smiley);            // 创建自定义字符

    for (byte row = 0; row < 2; row++) {
        lcd.setCursor(0,row);
        for (byte i = 0; i < 16; i++) {
            lcd.write(x);
            delay(20);
        }
    }
    Serial.print("boot succeed.");
    delay(500);
    lcd.clear();
    delay(500);
}

// 此方法用于读取按钮的输入以控制进行哪个workflow
void CtrlLCD::controlWorkflow() {

    String strs[] = {"getGold", "event", "event2", "mainQuest"};
    int wfSize = sizeof(strs) / sizeof(strs[0]);    // strs数组的长度

    byte hlNum = 0;     // 目前光标所处的工作流序号 - 1
    bool cursorAt1stLine = true;        // 目前光标是否在液晶屏的第一行
    char sNStr[1];      // serial number

    // 显示前两个workflow的序号和名称
    for (byte i = 0; i < 2; i++) {
        lcd.setCursor(0, i);
        lcd.write(itoa(i+1, sNStr, 10));
        lcd.print(" " + strs[i]);
    }
    // 光标放回第一格并令其闪烁
    lcd.setCursor(0, hlNum);
    lcd.blink();

    // 进入选择工作流的界面，持续监测三个按钮是否被按下
    while (true) {
        // 如果第一个按钮被按下，光标移动到上一个工作流的序号上
        if (digitalRead(A0) == LOW) {

            hlNum = (hlNum == 0) ? hlNum : hlNum - 1;

            if (cursorAt1stLine) {
                lcd.clear();
                lcd.write(itoa(hlNum+1, sNStr, 10));
                lcd.print(" " + strs[hlNum]);
                lcd.setCursor(0, 1);
                lcd.write(itoa(hlNum+2, sNStr, 10));
                lcd.print(" " + strs[hlNum + 1]);
            }
            cursorAt1stLine = true;
            lcd.setCursor(0, 0);

            // 如果此按钮被长按，每半秒选到下一个工作流，
            // 使用变量threshold和一个较短时间的延迟（10ms）保证
            // 短时间重复按下按钮多次可以起作用，下面按第二个按钮的代码同理
            byte threshold = 0;
            while (digitalRead(A0) == LOW) {
                threshold += 1;
                delay(10);
                if (threshold == 50) {
                    hlNum = (hlNum == 0) ? hlNum : hlNum - 1;

                    if (cursorAt1stLine) {
                        lcd.clear();
                        lcd.write(itoa(hlNum+1, sNStr, 10));
                        lcd.print(" " + strs[hlNum]);
                        lcd.setCursor(0, 1);
                        lcd.write(itoa(hlNum+2, sNStr, 10));
                        lcd.print(" " + strs[hlNum + 1]);
                    }

                    lcd.setCursor(0, 0);
                    threshold = 0;
                }
            }

        }

        // 如果第二个按钮被按下，光标移动到下一个工作流的序号上
        if (digitalRead(A1) == LOW) {

            hlNum = (hlNum == wfSize - 1) ? hlNum : hlNum + 1;

            if (!cursorAt1stLine) {
                lcd.clear();
                lcd.write(itoa(hlNum, sNStr, 10));
                lcd.print(" " + strs[hlNum - 1]);
                lcd.setCursor(0, 1);
                lcd.write(itoa(hlNum+1, sNStr, 10));
                lcd.print(" " + strs[hlNum]);
            }

            cursorAt1stLine = false;
            lcd.setCursor(0, 1);

            byte threshold = 0;
            while (digitalRead(A1) == LOW) {
                threshold += 1;
                delay(10);
                if (threshold == 50) {
                    hlNum = (hlNum == wfSize - 1) ? hlNum : hlNum + 1;

                    if (!cursorAt1stLine) {
                        lcd.clear();
                        lcd.write(itoa(hlNum, sNStr, 10));
                        lcd.print(" " + strs[hlNum - 1]);
                        lcd.setCursor(0, 1);
                        lcd.write(itoa(hlNum+1, sNStr, 10));
                        lcd.print(" " + strs[hlNum]);
                    }

                    lcd.setCursor(0, 1);
                    threshold = 0;
                }
            }
        }
        
        // 如果第三个按钮被按下，进入是否执行此工作流的确认界面
        if (digitalRead(A2) == LOW) {
            while (digitalRead(A2) == LOW) {}     // 处理掉长按，松手才继续执行

            // 显示确认信息
            lcd.clear();
            lcd.write(itoa(hlNum+1, sNStr, 10));
            lcd.print(" " + strs[hlNum]);
            lcd.setCursor(5, 1);
            lcd.print("start?");

            while (true) {
                // 如果再次按下确认按钮，则开始执行相应的工作流
                bool breakOutLoop = false;
                if (digitalRead(A2) == LOW) {
                    while (digitalRead(A2) == LOW) {}     // 处理掉长按，松手才继续执行
                    lcd.setCursor(5, 1);
                    lcd.print("start!");
                    switch (hlNum) {
                    case 0:
                        myWorkflow.getGold();
                        break;
                    case 1:
                        myWorkflow.event();
                        break;
                    case 2:
                        myWorkflow.event2();
                        break;
                    case 3:
                        myWorkflow.mainQuest();
                    default:
                        breakOutLoop = true;
                        break;
                    }
                }
                if (breakOutLoop) break;
            }
        }
    }
    
}

// 此方法用于使用电脑键盘发送串行信息用于调试代码
void CtrlLCD::debugUsingKeyboard() {

    while (true) {
        if (Serial.available() > 0) {
            while (Serial.available() > 0) {
                Serial.print("serial port has data: ");
                char serialData = Serial.read();
                switch (serialData) {
                case 'w':
                    Serial.println("w!");
                    myWorkflow.moveByXYSteps(0, -10);
                    break;
                case 's':
                    Serial.println("s!");
                    myWorkflow.moveByXYSteps(0, 10);
                    break;
                case 'a':
                    Serial.println("a!");
                    myWorkflow.moveByXYSteps(-10, 0);
                    break;
                case 'd':
                    Serial.println("d!");
                    myWorkflow.moveByXYSteps(10, 0);
                    break;
                case 'o':
                    Serial.println("return to origin!");
                    myWorkflow.returnToO();
                    break;
                
                default:
                    break;
                }
            }
            Serial.println("End serial input.");
        }
    }
    
    
}
