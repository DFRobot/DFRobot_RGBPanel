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
  if((dir != N)&&(dir != R)&&(dir != L)){
    return;
  }
  if(dir == N){
    buf[0] &= (~(0x01<<2));
  }
  else if(dir == R){
    buf[0] |= (0x01<<2)|(0x01<<1);
  }
  else if(dir == L){
    Serial.println("L");
    buf[0] |= (0x01<<2);
    buf[0] &= (~(0x01<<1));
  }
  else
    return;
}

void DFRobot_RGBPanel::print(unsigned char pic,unsigned char col){
  
  buf[0] = (buf[0] & (0xe6)) | (0x02 << 3);
  buf[1] = col;
  buf[4] = pic;
  setReg(0x02,buf,SIZE);
  delay(100);
}

void DFRobot_RGBPanel::print(String s,unsigned char col){
  unsigned char i = 0;
  int len = s.length();
  
  if(len > 40){
    return;
  }
  buf[0] = (buf[0] & (0xe6))| (0x03 << 3) ;
  buf[1] = col;
  for(i = 0;i <= len;i++){
    buf[5+i] = s[i];
  }
  setReg(0x02,buf,SIZE);
  delay(100);
}

void DFRobot_RGBPanel::pixel(unsigned char x,unsigned char y,unsigned char col){
  buf[0] = (buf[0] & (0xe6)) | (0x01 << 3);
  buf[1] = col;
  buf[2] = x;
  buf[3] = y;
  setReg(0x02,buf,SIZE);
  delay(100);
}

void DFRobot_RGBPanel::fillScreen(unsigned char col){
  buf[0] = 0x1;
  buf[0] = buf[0] = (buf[0] & (0xe7)) | (0x01 << 3);
  buf[1] = col;
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

uint8_t DFRobot_RGBPanel::readReg(uint8_t addr){
  uint8_t result;

  Wire.beginTransmission(_RGBAddr); //Start transmission to device 
  Wire.write(addr); //Sends register address to read rom
  Wire.endTransmission(false); //End transmission
  
  Wire.requestFrom((uint8_t)_RGBAddr, (uint8_t)2);//Send data n-bytes read
  result = Wire.read(); //Receive DATA
  return result;
}