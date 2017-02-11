/*************************************
* Author:        Alec Selfridge
* Filename:      SPLC780D.h
* Date Created:  02/10/2017
* Last Modified: 02/10/2017
* Device:        SPLC780D controller
**************************************/
#ifndef SPLC780D_H
#define SPLC780D_H

// commands
#define LCD_CMD_PREFIX    0xFE // sent prior to sending commands
#define LCD_DISP_ON       0x41 // display on
#define LCD_DISP_OFF      0x42 // display off
#define LCD_CURR_SET      0x45 // set cursor
#define LCD_CURR_HOME     0x46 // cursor home
#define LCD_UNDERLINE_ON  0x47 // underline cursor on
#define LCD_UNDERLINE_OFF 0x48 // underline cursor off
#define LCD_MOV_CUR_L     0x49 // move cursor left one place
#define LCD_MOV_CUR_R     0x4A // move cursor right one place
#define LCD_CUR_BLINK_ON  0x4B // blinking cursor on
#define LCD_CUR_BLINK_OFF 0x4C // blinking cursor off
#define LCD_BACKSPACE     0x4E // backspace
#define LCD_CLR           0x51 // clear screen
#define LCD_CONTRAST      0x52 // set contrast
#define LCD_BRIGHTNESS    0x53 // set backlight brightness
#define LCD_LD_CHAR       0x54 // load custom character
#define LCD_MOV_DISP_L    0x55 // move display one place to the left
#define LCD_MOV_DISP_R    0x56 // move display one place to the right
#define LCD_CHG_BAUD      0x61 // change RS232 BAUD rate 232
#define LCD_CHG_I2C_ADDR  0x62 // change I2C address
#define LCD_DISP_FW       0x70 // display firmware version number
#define LCD_DISP_BAUD     0x71 // display RS232 BAUD rate
#define LCD_DISP_I2C_ADDR 0x72 // display I2C address
// baud codes
#define LCD_BAUD_300   1 // 300
#define LCD_BAUD_1200  2 // 1200
#define LCD_BAUD_2400  3 // 2400
#define LCD_BAUD_9600  4 // 9600
#define LCD_BAUD_14K4  5 // 14400
#define LCD_BAUD_19K2  6 // 19200
#define LCD_BAUD_57K6  7 // 57600
#define LCD_BAUD_115K2 8 // 115200

#endif
