/*  
 * 名称   : Night_lamp
 * 功能   : 光敏传感器控制LED模拟夜光灯
 * 作者   : http://www.keyes-robot.com/ 
*/
int Photosensor = A2;  //定义光敏传感器的控制引脚为A2
int ledPin = 3; // 定义LED的引脚为D3

void setup() {
  Serial.begin(9600); //波特率设置为9600
  pinMode(Photosensor, INPUT);  //设置光敏传感器的引脚为输入模式
  pinMode(ledPin, OUTPUT);// 设置led引脚为输出模式
}

void loop() {
  int val = analogRead(Photosensor); //读取模拟值
  Serial.println(val); // 串口打印
  if(val < 200){ //低于阈值
    digitalWrite(ledPin, HIGH); // 点亮LED
  }else{ //否则
    digitalWrite(ledPin, LOW); // 熄灭LED
  }
  delay(100);
}