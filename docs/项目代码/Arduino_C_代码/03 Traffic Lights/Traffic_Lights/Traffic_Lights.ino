/*
 * 名称   : Traffic_Lights
 * 功能   : 模拟交通灯
 * 作者   : http://www.keyes-robot.com/ 
*/
int redled = 3;  // 红色LED连接到数字管脚D3.
int yellowled = A2;  // 黄色LED连接到数字管脚A2.
int greenled = 2;  // 绿色LED连接数字管脚D2.

void setup() {
  pinMode(redled, OUTPUT);  // 将红色LED引脚设置为输出模式
  pinMode(yellowled, OUTPUT);  // 将黄色LED引脚设置为输出模式
  pinMode(greenled, OUTPUT);  // 将绿色LED的引脚设置为输出模式
}

void loop(){
  digitalWrite(greenled, HIGH); // 点亮绿色LED
  delay(5000); // 延时5秒
  digitalWrite(greenled, LOW); // 熄灭绿色LED
  for(int i=0;i<3;i++){// 闪烁3次
    digitalWrite(yellowled, HIGH); //点亮黄色LED
    delay(500); // 延时0.5秒
    digitalWrite(yellowled, LOW); // 熄灭黄色LED
    delay(500); // 延时0.5秒
  } 
  digitalWrite(redled, HIGH); // 点亮红色LED
  delay(5000); // 延时5秒
  digitalWrite(redled, LOW); // 熄灭红色LED
}
