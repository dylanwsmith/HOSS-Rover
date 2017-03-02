/*
 * AUTHOR:        Alec Selfridge
 * FILENAME:      main.cpp
 * VERSION:       1.0
 * PROJECT:       HOSS Rover
 * DATE CREATED:  02/02/2017
 * LAST MODIFIED: 02/10/2017
 */
#include <LPC17xx.h>
#include "LPC1768regmap.h"
#include "SPLC780D.h"
//#include "SHARP_IR.h"
#include <math.h>
//#include <stdlib.h>

// buttons & debouncing parameters
#define BTN1_PIN           6
#define BTN2_PIN           7
#define BTN3_PIN           0
#define DEBOUNCE_MS        5			// 4ms * 5 times = 20ms debounce
#define SYSTICK_LOAD_VALUE 399996 // 4ms
#define SYSTICK_ENABLE     0
#define SYSTICK_INT        1
#define SYSTICK_CLOCK      2
// UART parameters
#define UART2_PWR          24
#define FIFO_EN            0
#define FIFO_TX_CLR        2
#define WORD_LEN_SEL       0
#define DLAB_EN            7
#define PCLK_UART2         16
#define UART_THRE          5

void initGPIO(void);
void initSysTick(void);
void initUART2(unsigned long baud);
void initLCD(void);
void putchar(unsigned char c);
void putstring(const char *s, unsigned char start, unsigned char end);
void menuDisplay(void);
void feetToMeters(void);
void metersToFeet(void);
void startOperation(void);
void displayInt(void);

//SHARP_IR ir1 = SHARP_IR(5); // IR sensor on ADC0.5

int btn1state   = 0;
int btn2state   = 0;
int btn3state   = 0;
int btn4state   = 0;
int btn1counter = 0;
int btn2counter = 0;
int btn3counter = 0;
int btn4counter = 0;
int btn1pressed = 0;
int btn2pressed = 0;
int btn3pressed = 0;
int btn4pressed = 0;
int distance = 5;
bool menuState = false;
bool feet = true;
char str[3];

int main(void)
{
  //float ir1_dist = 0;
  
  // initializations
  SystemInit();
  initGPIO();
  initUART2(9600);
  initLCD();
  //ir1.init();
  //ir1.setImperial();
  initSysTick();
  
  while(1)
  {
    // read IR sensor
    //ir1.update();
    //ir1_dist = ir1.getDistance();
    
    if(btn4pressed == 1) {
			btn4pressed = 0;
			if(menuState) {
				if(feet) {
					feetToMeters();
					feet = false;
					menuDisplay();
				}
				else {
					metersToFeet();
					feet = true;
					menuDisplay();
				}
			}
		}
		
    if(btn1pressed == 1) {	//middle button
      btn1pressed = 0;
			if(menuState){
				distance -= 1;
				menuDisplay();
			}
    }
		
    if(btn2pressed == 1) { //left button
      btn2pressed = 0;
			if(menuState) {
				startOperation();
			}
			else {
				menuDisplay();
				menuState = true;
			}
    }
		
		if(btn3pressed == 1) { //right button
			btn3pressed = 0;
			if(menuState){
				distance += 1;
				menuDisplay();
			}
		}
  }
}

char* itoa(int value, char* result, int base) 
{
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
}

void initGPIO(void)
{
  // configure pin as GPIO
  PINSEL0 = 0;
  // configure buttons as inputs
  FIO0DIR0 |= (0<<BTN1_PIN);
  FIO0DIR0 |= (0<<BTN2_PIN);
	FIO0DIR0 |= (0<<BTN3_PIN);
}

void initSysTick(void)
{
  // load tick register  
  STRELOAD = SYSTICK_LOAD_VALUE;
  // enable systick, interrupts, and core clock
  STCTRL |= (1<<SYSTICK_ENABLE) | (1<<SYSTICK_INT) | (1<<SYSTICK_CLOCK);
}

// initializes UART2 to a specified baud rate, 8N1
void initUART2(unsigned long baud)
{
  unsigned int pclksel, pclkval, dlvalue;
  // power on and enable TXD2
  PCONP |= (1<<UART2_PWR);
  PINSEL0 |= 0x00100000;
  
  // enable FIFO and clear tx buffer
  U2FCR |= (1<<FIFO_EN) | (1<<FIFO_TX_CLR);
  // 8N1  
  U2LCR |= (0x03<<WORD_LEN_SEL) | (1<<DLAB_EN);
  
  // read PCLK value for UART2
  pclksel = (PCLKSEL1 >> PCLK_UART2) & 0x03;
  // determine the actual PCLK value
  switch(pclksel)
  {
  case 0x00:
    pclkval = SystemCoreClock / 4;
    break;
  case 0x01:
    pclkval = SystemCoreClock;
    break; 
  case 0x02:
    pclkval = SystemCoreClock / 2;
    break; 
  case 0x03:
    pclkval = SystemCoreClock / 8;
    break;
  // default case is reset
  default:
    pclkval = SystemCoreClock / 4;
  }
  
  // baud rate calculation as per the datasheet
  dlvalue = (pclkval / (16 * baud)); 
  U2DLL =  dlvalue & 0xFF;
  U2DLM = (dlvalue >> 8) & 0xFF;
  
  // clear DLAB
  U2LCR &= ~(1<<DLAB_EN);
}

void initLCD(void)
{
  // clear screen
  putchar(LCD_CMD_PREFIX);
  putchar(LCD_CLR);
  putstring("HOSS Rover V1.0", 0, 15);
}

void putchar(unsigned char c)
{
  // wait for tx ready flag
  while((U2LSR & (1<<UART_THRE)) == 0);
  // load character
  U2THR = c;   
}

// prints characters from start up to, not including, end
void putstring(const char *s, unsigned char start, unsigned char end)
{
  if(start >= end)
    return;
  
  for(int i = start; i < end; i++)
    putchar(s[i]);
}

void menuDisplay(void)
{
	itoa(distance, str, 10);
	putchar(LCD_CMD_PREFIX);
  putchar(LCD_CLR);
	putstring("SET DISTANCE - +", 0, 16);
	putchar(LCD_CMD_PREFIX);
	putchar(LCD_CURR_SET);
	putchar(0x40);
	if(feet) 
		putstring("Feet: ", 0, 6);
	else
		putstring("Meters: ", 0, 8);
	putstring(str,0,3);
}

void feetToMeters(void)
{
	distance = ceil(distance*0.3048);
}

void metersToFeet(void)
{
	distance = ceil(distance/0.3048);
}

void startOperation(void)
{
	putchar(LCD_CMD_PREFIX);
  putchar(LCD_CLR);
	putstring("Running. . .", 0, 12);
}

void displayInt(void)
{
	
}

// ISR for button timer
extern "C" {
  void SysTick_Handler(void)
  {
    // read button states
    btn1state = (FIO0PIN0>>BTN1_PIN) & 0x01;
    btn2state = (FIO0PIN0>>BTN2_PIN) & 0x01;
		btn3state = (FIO0PIN0>>BTN3_PIN) & 0x01;
		
		if(btn1state == 0 || btn3state == 0) {
      btn4counter = 0;
      btn4pressed = 0;
    }
    else 
      btn4counter++;
		
		if((btn1counter == DEBOUNCE_MS) &&(btn3counter == DEBOUNCE_MS)){
			btn4pressed = 1;
		}
    
    // debounce button 1
    if(btn1state == 0) {
      btn1counter = 0;
      btn1pressed = 0;
    }
    else 
      btn1counter++;
    if(btn1counter == DEBOUNCE_MS)
      btn1pressed = 1;
    
    // debounce button 2
    if(btn2state == 0) {
      btn2counter = 0;
      btn2pressed = 0;
    }
    else 
      btn2counter++;
    if(btn2counter == DEBOUNCE_MS)
      btn2pressed = 1;
		
		// debounce button 3
    if(btn3state == 0) {
      btn3counter = 0;
      btn3pressed = 0;
    }
    else 
      btn3counter++;
    if(btn3counter == DEBOUNCE_MS)
      btn3pressed = 1;
  }
}