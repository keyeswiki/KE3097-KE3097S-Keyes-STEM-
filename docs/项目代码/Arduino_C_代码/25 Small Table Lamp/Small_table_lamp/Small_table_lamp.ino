/* 
 * 名称   : Small_table_lamp
 * 功能   : 模拟一个小台灯
 * 作者   : http://www.keyes-robot.com/ 
*/
int ledPin = 3; // 定义LED的引脚为D3.
int PIN_BUTTON = 2;  //将自锁按键的引脚连接到D2
int val = 0;            //用于存储键值

void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  pinMode(PIN_BUTTON, INPUT);  //设置自锁按键的引脚为输入模式
  pinMode(ledPin, OUTPUT);// 设置led引脚为输出模式
}

// 循环函数会一直运行下去
void loop() {
  val = digitalRead(PIN_BUTTON);  //读取自锁按键的值并将其赋值给变量val
  Serial.println(val);          //打印变量val的值
  if (val == 0) {             //按下自锁按键时读取到低电平，并打印出相关的信息
    digitalWrite(ledPin, HIGH); // 点亮LED
  }
  else { 
    digitalWrite(ledPin, LOW); // 熄灭LED 
  } 
}
