#include "CtrlLCD.h"

// 此类的构造函数
CtrlLCD::CtrlLCD() {
    lcd.begin(16, 2);
    pinMode(A0, INPUT);
    Serial.println("lcd created.");
}

// 此类的析构函数
CtrlLCD::~CtrlLCD() {
    Serial.println("lcd deleted.");
}

// 此方法用于开机测试
void CtrlLCD::bootTest() {
    byte smiley[8] = {    //1表示亮，0表示不亮，此例显示一个笑脸
        B00000,
        B10001,
        B00000,
        B00000,
        B10001,
        B01110,
        B00000,
    };
    
    int x = 0;
    lcd.createChar(x, smiley);

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
    KFWorkflow myWorkflow = KFWorkflow(lcd);

    String strs[2] = {"getGold", "bar"};

    byte hlNum = 0;
    char sNStr[1];      // serial number

    for (byte i = 0; i < 2; i++) {
        lcd.setCursor(0, i);
        lcd.write(itoa(i+1, sNStr, 10));
        lcd.print(" " + strs[i]);
    }
    
    lcd.setCursor(0, hlNum);
    lcd.blink();

    while (true) {
        if (digitalRead(A0) == LOW) {
            hlNum = (hlNum == 1) ? hlNum : hlNum + 1;
            // lcd.write(itoa(hlNum, sNStr, 10));
            lcd.setCursor(0, hlNum);

            byte aa = 0;
            while (digitalRead(A0) == LOW) {
                aa += 1;
                delay(10);
                if (aa == 50) {
                    hlNum = (hlNum == 9) ? hlNum : hlNum + 1;
                    // lcd.write(itoa(hlNum, sNStr, 10));
                    lcd.setCursor(0, hlNum);
                    aa = 0;
                }
            }
        }
        if (digitalRead(A1) == LOW) {
            hlNum = (hlNum == 0) ? hlNum : hlNum - 1;
            // lcd.write(itoa(hlNum, sNStr, 10));
            lcd.setCursor(0, hlNum);

            byte aa = 0;
            while (digitalRead(A1) == LOW) {
                aa += 1;
                delay(10);
                if (aa == 50) {
                    hlNum = (hlNum == 0) ? hlNum : hlNum - 1;
                    // lcd.write(itoa(hlNum, sNStr, 10));
                    lcd.setCursor(0, hlNum);
                    aa = 0;
                }
            }
        }
        if (digitalRead(A2) == LOW) {
            while (digitalRead(A2) == LOW) {}
            
            lcd.clear();
            lcd.write(itoa(hlNum+1, sNStr, 10));
            lcd.print(" " + strs[hlNum]);
            lcd.setCursor(5, 1);
            lcd.print("start?");

            while (true) {
                if (digitalRead(A2) == LOW) {
                    while (digitalRead(A2) == LOW) {}
                    lcd.setCursor(5, 1);
                    lcd.print("start!");
                    switch (hlNum) {
                    case 0:
                        myWorkflow.getGold();
                        break;
                    case 1:
                        myWorkflow.event();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        // Serial.println(digitalRead(A0));
        
    }
    
}
