/*  
 * 名称   : Corridor_sensing_light
 * 功能   : 声音传感器和光敏传感器控制LED模拟楼道感应灯
 * 作者   : http://www.keyes-robot.com/ 
*/
int microPin = A7;  //定义声音传感器的控制引脚为A7
int PhotosensorPin = A2;  //定义光敏传感器的控制引脚为A2
int ledPin = 3;  //定义LED的引脚为D3

void setup() {
  Serial.begin(9600); //波特率设置为9600
  pinMode(microPin, INPUT);  //设置声音传感器的引脚为输入模式
  pinMode(PhotosensorPin, INPUT);  //设置光敏传感器的引脚为输入模式  
  pinMode(ledPin, OUTPUT);// 设置led引脚为输出模式
}

void loop() {
  int val1 = analogRead(PhotosensorPin); //读取光敏传感器的模拟值
  int val2 = analogRead(microPin); //读取声音传感器的模拟值
  Serial.print("Photosensor: ");  // 串口打印Photosensor:
  Serial.print(val1);  // 串口打印val1
  Serial.print("  ");  // 串口打印
  Serial.print("microphone: "); // 串口打印microphone:
  Serial.print(val2);  // 串口打印val2
  if(val1 < 200){ //光照模拟值低于阈值200
    if(val2 > 150){ //声音强度超过阈值150
      digitalWrite(ledPin, HIGH); // 点亮LED
      Serial.println("  led on"); 
      delay(5000);
    }else{ //否则
      digitalWrite(ledPin, LOW); // 熄灭LED
      Serial.println("  led off");
      delay(50);
    }
  }else{ //否则
      digitalWrite(ledPin, LOW); // 熄灭LED 
      Serial.println("  led off");
      delay(50); 
  }
  delay(100);
}