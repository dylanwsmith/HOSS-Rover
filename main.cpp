/*
 * AUTHOR:        Alec Selfridge
 * FILENAME:      main.cpp
 * VERSION:       1.0
 * PROJECT:       HOSS Rover
 * DATE CREATED:  02/02/2017
 * LAST MODIFIED: 02/02/2017
 */
#include <LPC17xx.h>
#include "LPC1768regmap.h"
#include "SPLC780D.h"
#include "SHARP_IR.h"

// buttons & debouncing parameters
#define BTN1_PIN           6
#define BTN2_PIN           7
#define DEBOUNCE_MS        20
#define SYSTICK_LOAD_VALUE 99999 // 1ms
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

SHARP_IR ir1 = SHARP_IR(5); // IR sensor on ADC0.5

int btn1state   = 0;
int btn2state   = 0;
int btn1counter = 0;
int btn2counter = 0;
int btn1pressed = 0;
int btn2pressed = 0;

int main(void)
{
  int temp = 0;
  float ir1_dist = 0;
  
  // initializations
  SystemInit();
  initGPIO();
  initUART2(9600);
  initLCD();
  ir1.init();
  ir1.setImperial();
  initSysTick();
  
  while(1)
  {
    // read IR sensor
    ir1.update();
    ir1_dist = ir1.getDistance();
    
    // check buttons
    if(btn1pressed == 1) {
      btn1pressed = 0;
      temp++;
    }
    if(btn2pressed == 1) {
      btn2pressed = 0;
      temp--;
    }
  }
}

void initGPIO(void)
{
  // configure pin as GPIO
  PINSEL0 = 0;
  // configure buttons as inputs
  FIO0DIR0 |= (0<<BTN1_PIN);
  FIO0DIR0 |= (0<<BTN2_PIN);
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

// ISR for button timer
extern "C" {
  void SysTick_Handler(void)
  {
    // read button states
    btn1state = (FIO0PIN0>>BTN1_PIN) & 0x01;
    btn2state = (FIO0PIN0>>BTN2_PIN) & 0x01;
    
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
  }
}
