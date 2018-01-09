# RGBPanel Library for Arduino
This is a Library for RGBPanel,the function is control LED display image, string, set pixel and fill screen with one color.

## Table of Contents

* [Summary](#summary)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


<snippet>
<content>

## Summary
This is Library for RGBPanle,You can make it display the image, string, set pixel and fill screen with one color.

## Methods

```C++

#include <DFRobot_RGBPanel.h>
/*
 * @brief The constructor
 */
DFRobot_RGBPanel();

/*
 * @brief Set the direction of scroll
 *
 * @param dir the direction
 *            Left: left
 *            Right: right
 *            None: stop scroll
 */
void scroll(unsigned char dir);

/*
 * @brief Clear screen
 */
void clear();

/*
 * @brief display string
 *
 * @param s String,and the length of string is no more than 40
 * @param col The color of LED
 *             QUENCH  quench LED
 *             RED     red
 *             GREEN   green
 *             YELLOW  yellow
 *             BLUE    blue
 *             PURPLE  purple
 *             CYAN    cyan
 *             WHITE   white
 */
void print(String s,unsigned char color);

/*
 * @brief display value
 *
 * @param val value
 * @param col The color of LED
 *             QUENCH  quench LED
 *             RED     red
 *             GREEN   green
 *             YELLOW  yellow
 *             BLUE    blue
 *             PURPLE  purple
 *             CYAN    cyan
 *             WHITE   white
 */
void print(int val,unsigned char color);

/*
 * @brief Display a bitmap
 *
 * @param picIndex the number of picture,range(0,23)
 * @param col The color of LED
 *             QUENCH  quench LED
 *             RED     red
 *             GREEN   green
 *             YELLOW  yellow
 *             BLUE    blue
 *             PURPLE  purple
 *             CYAN    cyan
 *             WHITE   white
 */
void display(unsigned char picIndex,unsigned char color);

/*
 * @brief set pixel
 *
 * @param x Horizontal coordinate, range(0,15)
 * @param y Vertical coordinate, range(0,7)
 * @param col The color of LED
 *             QUENCH  quench LED
 *             RED     red
 *             GREEN   green
 *             YELLOW  yellow
 *             BLUE    blue
 *             PURPLE  purple
 *             CYAN    cyan
 *             WHITE   white
 */
void pixel(unsigned char x,unsigned char y,unsigned char color); 

/*
 * @brief Fill screen with one color
 *
 * @param col Vertical coordinate, range(0,29)
 *             QUENCH  quench LED
 *             RED     red
 *             GREEN   green
 *             YELLOW  yellow
 *             BLUE    blue
 *             PURPLE  purple
 *             CYAN    cyan
 *             WHITE   white
 */
void fillScreen(unsigned char color); 

```


## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Leonardo |      √       |             |            | 
Arduino Uno |      √       |             |            | 
FireBeetle-Board328P |             |      √       |            | 
FireBeetle-ESP32 |             |       √      |            | 
FireBeetle-ESP8266 |             |      √       |            | 

## History

- data 2017-11-15
- version V1.0


## Credits

- author [Luyuhao  <yuhao.lu@dfrobot.com>]
