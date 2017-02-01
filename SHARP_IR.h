/*************************************
* Author:        Alec Selfridge
* Filename:      SHARP_IR.h
* Date Created:  11/03/2016
* Last Modified: 12/10/2016
* Device:        LPC1768 (mbed LPC1768)
 *************************************/
#ifndef SHARP_IR_H
#define SHARP_IR_H

// units
#define METRIC   0
#define IMPERIAL 1
// polynomial coefficients
#define a0       26.67034
#define a1      -40.01913
#define a2       23.33686
#define a3       -4.800871
#define ADCRES 4095.0
#define ADCV      3.3
#define CMTOIN    2.54

class SHARP_IR
{
  private:
    unsigned short ADCchannel;     // which ADC to use (0-5)
    float          objectDistance; 
    unsigned short rawReading; 
    float          alertDistance;
    bool           unit;           // 0 = metric (cm), 1 = imperial (in) (metric default)
  
    void  configADC();
    void  readADC();
    void  fitData();
  
  public:
    SHARP_IR(unsigned short channel);
    void  init();
    void  init(float AD);
    void  update();
    float getDistance();
    void  setAlertDistance(float distance);
    bool  objectDetected();
    void  setImperial();
    void  setMetric();
};
 
#endif
