
#include "multiCameraIrControl.h"
int ledPin = 13;   // LED 连接到数字端口13
int sensor = 10;    //传感器连接到数字端口2
//红外热释电运动传感器发出高电平，则被触发
//发出低电平，则其处于休眠状态
int val = 0; //存储传感器输出的数字量
Nikon D5000(13);
void setup()
{
  
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  pinMode(sensor, INPUT);       // sets the digital pin as input
  digitalWrite(ledPin,HIGH);    //初始化熄灭灯
  Serial.begin(9600);//设置串行通信的波特率
}
 
void loop()
{
  
  val = digitalRead(sensor);   // read the input pin
  //如果红外热释电运动传感器被触发，将保持高电平一段时间
  if(HIGH == val)
  {
    //Serial.print(1,BYTE);//向Processing发出传感器被触发标志
     D5000.shutterNow();
     delay(1000);
   
  }
  
}
