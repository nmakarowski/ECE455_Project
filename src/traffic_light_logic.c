#include <stdio.h>

#define update_time 0.5
#define POT_MAX_VALUE 4000
#define POT_TO_PERCENTAGE 40
#define AMBER_TIME_SEC 1

#define RED = 0
#define AMBER = 1
#define GREEN = 2



static int getPotentiometerValue();
void logErrors (int condition, char* errorStr);


static double getTimeLight (int light) {
  int greenTime = 0;
  int potValue = getPotentiometerValue();
  //todo
}




static int getPotentiometerValue() {
  ADC_SoftwareStartConv(ADC1);
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0){
    printf("got 0 - restarting conversion and continuing :)\n");
  }
  return potentiometerVal = ADC_GetConversionValue(ADC1);
}

