#include <stdio.h>

#define update_time 0.5
#define POT_MAX_VALUE 4000
#define POT_TO_PERCENTAGE 40


void logErrors (int condition, char* errorStr);
static double getTimeToNextCar_seconds();
static double calculateTimeFromPercentage(int percentage);

/*
 * calculates the time between cars by percentage of traffic
 */
static double getTimeToNextCar_seconds() {
  // get the potentiometer value
  ADC_SoftwareStartConv(ADC1);
  while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0){
    printf("got 0 - restarting conversion and continuing :)\n");
  }
  int potentiometerVal = ADC_GetConversionValue(ADC1);

  logErrors(potentiometerVal >= 0, "negative potentiometer value");
  logErrors(potentiometerVal <= POT_MAX_VALUE, "potentiometer value above 4000");
  int percentage = potentiometerVal / POT_TO_PERCENTAGE;
  return calculateTimeFromPercentage(percentage);
}

/*
 * calculates the time between cars by percentage of traffic
 */
static double calculateTimeFromPercentage(int percentage) {
  logErrors(percentage >= 0, "negative traffic value");
  logErrors(percentage <= 100, "Traffic value above 100");

  if(percentage <= 20){
    return 5 * update_time;
  } else if (percentage > 21 && percentage <= 40) { 
    return 4 * update_time;
  } else if (percentage > 41 && percentage <= 60) {
    return 3 * update_time;
  } else if (percentage > 61 && percentage <= 80) {
    return 2 * update_time;
  } else {
    // percentage > 80
    return 1 * update_time;
  }
}

/*
 * logs the error string if the condition is false
 */
void logErrors (int condition, char* errorStr) {
  if (!condition) {
    printf("ERROR: %s\n", errorStr);
  } 
} 

