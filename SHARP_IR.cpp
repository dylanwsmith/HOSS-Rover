/*************************************
* Author:        Alec Selfridge
* Filename:      SHARP_IR.cpp
* Date Created:  11/03/2016
* Last Modified: 12/10/2016
* Device:        LPC1768 (mbed LPC1768)
 *************************************/
#include "SHARP_IR.h"
#include "LPC1768regmap.h"

SHARP_IR::SHARP_IR(unsigned short channel)
{
  ADCchannel     = channel;
  unit           = METRIC;
  alertDistance  = 5.0;
  objectDistance = 0.0; 
  rawReading     = 0;
}

void SHARP_IR::init()
{
  // configure the pin
  configADC();
}

void SHARP_IR::init(float AD)
{
  alertDistance = AD;   // assign the given alert distance
  // configure the pin
  configADC();
}

void SHARP_IR::configADC()
{
  PCONP   |= (1 << 12u);               // power on ADC
  AD0CR   |= ((1 << 21u) | (2 << 8u)); // power on ADC0 @ 12MHz
  switch(ADCchannel)
  {
    // P0.23
    case 0: PINSEL1 |= (1 << 14u);
            break;
    // P0.24
    case 1: PINSEL1 |= (1 << 16u);
            break;
    // P0.25
    case 2: PINSEL1 |= (1 << 18u);
            break;
    // P0.26
    case 3: PINSEL1 |= (1 << 20u);
            break;
    // P1.30
    case 4: PINSEL3 |= (3u << 28u);
            break;
    // P1.31
    case 5: PINSEL3 |= (3u << 30u);
            break;
    default:
            // uses ADC0.0 by default
            PINSEL1 |= (1 << 14u);
            break;
  }
}

// starts the conversion and saves the 12-bit result
void SHARP_IR::readADC()
{
  // start conversion
  AD0CR |= (1u << 24u); 
  // wait for conversion to finish
  while((AD0GDR & (1u << 31u)) == 0);
  rawReading = (AD0GDR >> 4u) & 0xFFF;
}

// polls the chosen ADC pin and runs a conversion routine on the data
// NOTE: data is taken from the GLOBAl ADC register, not the channel itself
// this should be of no consequence in most cases
void SHARP_IR::update()
{
  // start ADC 
  switch(ADCchannel)
  {
    // P0.23
    case 0: AD0CR |= 1;
            break;
    // P0.24
    case 1: AD0CR |= 2;
            break;
    // P0.25
    case 2: AD0CR |= 4;
            break;
    // P0.26
    case 3: AD0CR |= 8;
            break;
    // P1.30
    case 4: AD0CR |= 16;
            break;
    // P1.31
    case 5: AD0CR |= 32;
            break;
    default:
            // uses ADC0.0 by default
            AD0CR |= 1;
            break;
  }
  readADC();
  // anything above 2.3V (2854) is out-of-spec, thus re-read the sensor
  if(rawReading >= 2854)
    readADC();
  fitData(); // implements a best-fit polynomial
}

// y = a0 + a1*x + a2*x^2 + a3x^3
void SHARP_IR::fitData()
{
  float x = (float)rawReading / ADCRES * ADCV;
  float y = a0 + (a1*x) + (a2*x*x) + (a3*x*x*x);
  if(unit == IMPERIAL)
    objectDistance = y / CMTOIN;
  else
    objectDistance = y;
}

float SHARP_IR::getDistance()
{
  return objectDistance;
}

/* 
 *  Returns true if the measured distance
 *  is less than the specified boundary.
 */
bool SHARP_IR::objectDetected()
{
  if(objectDistance <= alertDistance)
    return true;
  else
    return false;
}

void SHARP_IR::setAlertDistance(float distance)
{
  alertDistance = distance;
}

void SHARP_IR::setImperial()
{
  unit = IMPERIAL;
}

void SHARP_IR::setMetric()
{
  unit = METRIC;
}
