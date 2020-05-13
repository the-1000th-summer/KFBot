# KFBot

此仓库代码配合蓝牙HID鼠标模块，应用于Kirara Fantasia (きらファン) 手游的自动挂机。

## 所需硬件参考

1. Arduino Uno；
2. BTKM-05（DEMO板，内含的蓝牙鼠标模块星号为XM-04-HID-M）；
3. 10kΩ电阻2个、20kΩ电阻1个、220Ω电阻一个；
4. 导线若干；
5. LCD1602液晶屏幕、电位器2个。

## 开发用测试机型

iPhone 6s (iOS 13.4)

## 模块连接方法

蓝牙HID模块：见我制作的[视频](https://www.bilibili.com/video/BV1de411s7tc)；

LCD1602模块：[http://m.elecfans.com/article/687697.html](http://m.elecfans.com/article/687697.html)

## 代码使用方法

1. 根据蓝牙模块连接情况，修改`GeneralMouse.h`文件中的第一个私有属性bTserial的代表RX和TX的引脚号；
2. 根据LCD模块连接情况，修改`CtrlLCD.h`文件中的私有属性lcd的引脚号；
3. 根据自身情况，在`KFWorkflow.cpp`文件内建立不同的鼠标工作流；
4. 编译上传。