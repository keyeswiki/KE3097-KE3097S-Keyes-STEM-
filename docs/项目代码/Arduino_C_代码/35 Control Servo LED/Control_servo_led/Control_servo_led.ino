/*
 * 名称   : Control_servo_led
 * 功能   : 控制舵机转动和LED
 * 作者   : http://www.keyes-robot.com/ 
*/
#include <Servo.h>

Servo myservo;  //创建舵机对象来控制舵机
int servoPin = 5;  // 定义舵机引脚D5

int ledPin = 3; // 定义LED的引脚为D3

#define PIN_BUTTON  2  //将自锁按键的引脚连接到D2
#define PIN_ANALOG_IN  A2  //电位器传感器的引脚定义为A2

int val1 = 0;   //用于存储键值
int val2 = 0;   //设置val2为0

void setup() {
  Serial.begin(9600);   //波特率设置为9600
  pinMode(PIN_ANALOG_IN, INPUT);    //将电位器的引脚设置为输入模式
  pinMode(PIN_BUTTON, INPUT);    //将自锁按键模块的引脚设置为输入模式
  pinMode(ledPin, OUTPUT);// 设置led引脚为输出模式
  myservo.attach(servoPin);  //选择舵机引脚D5
  myservo.write(0); // 舵机转动0°
  delay(500); // 等待500ms
}

void loop() {
  val1 = digitalRead(PIN_BUTTON);  //读取自锁按键的值并将其赋值给变量val1
  if (val1 == 0) {       //按下自锁按键时读取到低电平
    digitalWrite(ledPin, HIGH); // 点亮LED
  }
  else {
    digitalWrite(ledPin, LOW); // 熄灭LED
  }  
  val2 = analogRead(PIN_ANALOG_IN);    //读取电位器的模拟信号
  myservo.write((map(val2, 0, 1023, 0, 180)));   // 电位器的模拟值映射到舵机的位置
  delay(10);   // 等待10ms让舵机到达对应的位置
}
