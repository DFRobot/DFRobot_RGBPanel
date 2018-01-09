#include <DFRobot_RGBPanel.h>
#include <Wire.h>
#include <Arduino.h>
DFRobot_RGBPanel::DFRobot_RGBPanel(){
  Wire.begin();
}

void DFRobot_RGBPanel::clear(){
  int i = 0;
  buf[0] = 0x1;
  for(i = 1;i < SIZE;i++){
    buf[i] = 0;
  }
  setReg(0x02,buf,SIZE);
  delay(100);
}

void DFRobot_RGBPanel::scroll(unsigned char dir){
  if((dir != None)&&(dir != Right)&&(dir != Left)){
    return;
  }
  if(dir == None){
    buf[0] &= (~(0x01<<2));
  }
  else if(dir == Right){
    buf[0] |= (0x01<<2)|(0x01<<1);
  }
  else if(dir == Left){
    buf[0] |= (0x01<<2);
    buf[0] &= (~(0x01<<1));
  }
  else
    return;
}

void DFRobot_RGBPanel::display(unsigned char picIndex,unsigned char color){
  
  buf[0] = (buf[0] & (0xe6)) | (0x02 << 3);
  buf[1] = color;
  buf[4] = picIndex;
  setReg(0x02,buf,SIZE);
  delay(100);
}

void DFRobot_RGBPanel::print(int val,unsigned char color){
  String s = String(val);
  print(s,color);
}

void DFRobot_RGBPanel::print(String s,unsigned char color){
  unsigned char i = 0;
  int len = s.length();
  
  if(len > 40){
    return;
  }
  buf[0] = (buf[0] & (0xe6))| (0x03 << 3) ;
  buf[1] = color;
  for(i = 0;i <= len;i++){
    buf[5+i] = s[i];
  }
  setReg(0x02,buf,SIZE);
  delay(100);
}

void DFRobot_RGBPanel::pixel(unsigned char x,unsigned char y,unsigned char color){
  buf[0] = (buf[0] & (0xe6)) | (0x01 << 3);
  buf[1] = color;
  buf[2] = x;
  buf[3] = y;
  setReg(0x02,buf,SIZE);
 // delay(5);
}

void DFRobot_RGBPanel::fillScreen(unsigned char color){
  buf[0] = 0x1;
  buf[0] = buf[0] = (buf[0] & (0xe7)) | (0x01 << 3);
  buf[1] = color;
  buf[2] = 0;
  buf[3] = 0;
  setReg(0x02,buf,SIZE);
  delay(100);
}


void DFRobot_RGBPanel::setReg(unsigned char Reg ,unsigned char *pdata, unsigned char datalen )
{
   Wire.beginTransmission(_RGBAddr); // transmit to device #8
   Wire.write(Reg);              // sends one byte
  
   for(uint8_t i = 0; i < datalen; i++){
      Wire.write(*pdata); 
      pdata++;
    }
 
   Wire.endTransmission();    // stop transmitting
}

int * DFRobot_RGBPanel::readReg(uint8_t addr,uint8_t num){
  static int result[64];
  int i = 0;
  Wire.beginTransmission(_RGBAddr); //Start transmission to device 
  Wire.write(addr); //Sends register address to read rom
  Wire.endTransmission(false); //End transmission
  
  Wire.requestFrom((uint8_t)_RGBAddr, num);//Send data n-bytes read
   while (Wire.available())   // slave may send less than requested
  {
    result[i++] = Wire.read(); // print the character
  }
//  Serial.println(result[0]);
  return result;
}
