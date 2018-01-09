 /*!
  * file DFRobot_RGBPanel_IIC_demo.ino
  *
  * connect RGBPanel and Arduino ,then download this example
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2017-11-15
  */
#include<Wire.h>
#include <DFRobot_RGBPanel.h>
DFRobot_RGBPanel panel;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int *p = panel.readReg(0x00,2);
  int i = 0;
  for(i = 0;i<2;i++){
    Serial.println(p[i],HEX);
  }
  int a=12;
  String s = "DFRobot";
  panel.clear();
  panel.display(2,BLUE);
  delay(3000);
  
  panel.clear();
  panel.scroll(Left);
  panel.print(s,RED);
  delay(8000);
  
  panel.clear();
  panel.pixel(2,2,QUENCH);
  panel.pixel(3,2,RED);
  panel.pixel(4,2,GREEN);
  panel.pixel(5,2,YELLOW);
  panel.pixel(6,2,BLUE);
  panel.pixel(7,2,PURPLE);
  panel.pixel(8,2,CYAN);
  panel.pixel(9,2,WHITE);
  delay(3000);
  
  panel.clear();
  panel.fillScreen(BLUE);
  delay(3000);
  
  panel.clear();
  panel.scroll(Left);
  panel.print(a, BLUE);
  delay(3000);
}