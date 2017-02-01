#include<lpc17xx.h>
#include "SHARP_IR.h"   

SHARP_IR ir1 = SHARP_IR(5); // ADC0.5 aka P1.31

int main()
{
  SystemInit();
  float ir1_dist = 0;
  ir1.init();
  ir1.setImperial();
  while(1)
  {
    ir1.update();
    ir1_dist = ir1.getDistance();
  }
}
