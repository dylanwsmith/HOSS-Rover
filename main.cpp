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
#include "SHARP_IR.h"

#define BTN1_PIN           6
#define BTN2_PIN           7
#define DEBOUNCE_MS        20
#define SYSTICK_LOAD_VALUE 99999 // 1ms
#define SYSTICK_ENABLE     0
#define SYSTICK_INT        1
#define SYSTICK_CLOCK      2

void initGPIO(void);
void initSysTick(void);

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
  
  SystemInit();
  initGPIO();
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
