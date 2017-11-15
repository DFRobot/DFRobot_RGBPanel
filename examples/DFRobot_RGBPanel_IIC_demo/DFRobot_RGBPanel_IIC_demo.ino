#include <DFRobot_RGBPanel.h>
DFRobot_RGBPanel panel;

void setup(){
  Serial.begin(9600);
}

void loop(){
  String s = "abc";
  panel.clear();
  panel.print(0x02,BLUE);
  delay(3000);
  
  panel.clear();
  panel.scroll(L);
  panel.print(s,0x01);
  delay(3000);
  
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
while(1);
}