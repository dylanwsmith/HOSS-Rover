#include<lpc17xx.h>
#include "SHARP_IR.h"   

SHARP_IR ir1 = SHARP_IR(5); // ADC0.5 aka P1.31

int main()
{
  SystemInit();
  float ir1_dist = 0;
  // set 2in boundary
  ir1.init(2); 
  ir1.setImperial(); 
  while(1)
  {
    ir1.update();
    if(ir1.objectDetected())
      // do stuff
    else
      // do other stuff
  }
}
