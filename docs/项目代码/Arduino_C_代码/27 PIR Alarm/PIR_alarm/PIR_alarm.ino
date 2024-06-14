/*  
 * 名称   : PIR alarm
 * 功能   : PIR控制蜂鸣器和LED模拟入侵检测报警器
 * 作者   : http://www.keyes-robot.com/ 
*/
#define ledPin  3  // 定义LED的引脚为D3
#define PIR_PIN  2  //PIR运动传感器控制引脚为D2
#define BUZZER_PIN  A2  //定义有源蜂鸣器控制引脚为A2

int item = 0;

void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  pinMode(PIR_PIN, INPUT);  //设置PIR运动传感器的引脚为输入模式
  pinMode(BUZZER_PIN, OUTPUT); //设置有源蜂鸣器的引脚为输出模式
  pinMode(ledPin, OUTPUT);// 设置led引脚为输出模式
}

void loop() {
  item = digitalRead(PIR_PIN);//读取红外热释传感器输出的数字信号
  Serial.println(item);          //打印变量item的值
  if (item == 1) {  //运动检测
    digitalWrite(BUZZER_PIN, HIGH); //打开蜂鸣器
    digitalWrite(ledPin, HIGH); // 点亮LED
    delay(200);//延迟 200ms
    digitalWrite(BUZZER_PIN, LOW); //关掉蜂鸣器
    digitalWrite(ledPin, LOW); // 熄灭LED
    delay(200);//延迟 200ms
  } else {  //没有检测到任何信号或数据
    digitalWrite(BUZZER_PIN, LOW); //关掉蜂鸣器
    digitalWrite(ledPin, LOW); // 熄灭LED
  }
}