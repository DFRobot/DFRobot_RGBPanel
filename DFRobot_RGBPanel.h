#ifndef __DFRobot_RGB_H__
#define __DFRobot_RGB_H__

#include <Wire.h>

#define _RGBAddr 0x10
#define FUNC 0x02
#define COLOR 0x03
#define PIX_X 0x04
#define PIX_Y 0x05
#define BITMAP 0x06
#define STR 0x07

#define UNCLEAR 0x0
#define CLEAR 0x1
#define Left (0x0 << 1)
#define Right (0x1 << 1)
#define None (0x11)
#define UNSCROLL (0x0 << 2)
#define SCROLL (0x1 <<2)
#define PIX_ENABLE (0x01 << 3)
#define BITMAP_ENABLE (0x10 << 3)
#define STR_ENABLE (0x11 << 3)

#define QUENCH 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define PURPLE 5
#define CYAN 6
#define WHITE 7

#define SIZE 50

class DFRobot_RGBPanel
{
public:
  DFRobot_RGBPanel();
  void scroll(unsigned char dir);
  void display(unsigned char picIndex,unsigned char color);
  void print(String s,unsigned char color);
  void pixel(unsigned char x,unsigned char y,unsigned char color);
  void fillScreen(unsigned char color);
  void clear();
  unsigned char buf[SIZE] = {0};
  int * readReg(uint8_t addr,uint8_t num);
  void print(int val,unsigned char color);
private:
  void setReg(unsigned char Reg ,unsigned char *pdata, unsigned char datalen );
//  uint8_t readReg(uint8_t addr,uint8_t num);
  
};

#endif