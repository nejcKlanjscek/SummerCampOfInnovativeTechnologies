/*
 * led_driver.c
 *
 *  Created on: Aug 7, 2021
 *      Author: samo
 */
#include <SI_EFM8UB1_Register_Enums.h>

SI_SBIT(LED1,SFR_P0,5);
SI_SBIT(LED2,SFR_P0,6);
SI_SBIT(LED3,SFR_P0,7);
SI_SBIT(LED4,SFR_P1,0);
SI_SBIT(LED5,SFR_P1,1);
SI_SBIT(LED6,SFR_P1,2);
SI_SBIT(LED7,SFR_P1,3);
SI_SBIT(LED8,SFR_P1,4);
SI_SBIT(LED9,SFR_P1,5);
SI_SBIT(LED10,SFR_P1,6);
int ledState;

void running_leds(){

    switch(ledState)
      {
        case 0:
        LED1=0;
        LED2=0;
        LED3=0;
        LED4=0;
        LED5=0;
        LED6=0;
        LED7=0;
        LED8=0;
        LED9=0;
        LED10=0;
        break;
        case 1:
        LED1=1;
        break;
        case 2:
        LED2=1;
        break;
        case 3:
        LED3=1;
        break;
        case 4:
        LED4=1;
        break;
        case 5:
        LED5=1;
        break;

        case 6:
        LED6=1;
        break;
        case 7:
        LED7=1;
        break;
        case 8:
        LED8=1;
        break;
        case 9:
        LED9=1;
        break;
        case 10:
        LED10=1;
        break;
        default:
        ledState=-1;
      }
    ledState++;

}

/* Indicates which functionality is chosen */
/* 1: RF
 * 2: Wire
 * 3: Moisture
 * 4: Volume
 */
void function_indicator(int function){
  LED1=0;
  LED2=0;
  LED3=0;
  LED4=0;
  LED5=0;
  LED6=0;
  LED7=0;
  LED8=0;
  LED9=0;
  LED10=0;
  switch(function){
    case 1:
      LED1=1;
      break;
    case 2:
      LED2=1;
      break;
    case 3:
      LED3=1;
      break;
    case 4:
      LED4=1;
      break;
    default:
      LED10=1;
  }

}

void switch_power(int power){
  switch(power){
    case 10:
      LED1=1;
      LED2=1;
      LED3=1;
      LED4=1;
      LED5=1;
      LED6=1;
      LED7=1;
      LED8=1;
      LED9=1;
      LED10=1;
      break;
    case 9:
      LED1=1;
              LED2=1;
              LED3=1;
              LED4=1;
              LED5=1;
              LED6=1;
              LED7=1;
              LED8=1;
              LED9=1;
              LED10=0;
              break;
    case 8:
      LED1=1;
              LED2=1;
              LED3=1;
              LED4=1;
              LED5=1;
              LED6=1;
              LED7=1;
              LED8=1;
              LED9=0;
              LED10=0;
              break;
    case 7:
      LED1=1;
              LED2=1;
              LED3=1;
              LED4=1;
              LED5=1;
              LED6=1;
              LED7=1;
              LED8=0;
              LED9=0;
              LED10=0;
              break;
    case 6:
      LED1=1;
              LED2=1;
              LED3=1;
              LED4=1;
              LED5=1;
              LED6=1;
              LED7=0;
              LED8=0;
              LED9=0;
              LED10=0;
              break;
    case 5:
      LED1=1;
      LED2=1;
      LED3=1;
      LED4=1;
      LED5=1;
      LED6=0;
      LED7=0;
      LED8=0;
      LED9=0;
      LED10=0;
      break;

    case 4:
      LED1=1;
      LED2=1;
      LED3=1;
      LED4=1;
      LED5=0;
      LED6=0;
      LED7=0;
      LED8=0;
      LED9=0;
      LED10=0;
      break;

    case 3:
      LED1=1;
      LED2=1;
      LED3=1;
      LED4=0;
      LED5=0;
      LED6=0;
      LED7=0;
      LED8=0;
      LED9=0;
      LED10=0;
      break;

    case 2:
      LED1=1;
      LED2=1;
      LED3=0;
      LED4=0;
      LED5=0;
      LED6=0;
      LED7=0;
      LED8=0;
      LED9=0;
      LED10=0;
      break;

    case 1:
      LED1=1;
      LED2=0;
      LED3=0;
      LED4=0;
      LED5=0;
      LED6=0;
      LED7=0;
      LED8=0;
      LED9=0;
      LED10=0;
      break;
    default:
      LED1=0;
      LED2=0;
      LED3=0;
      LED4=0;
      LED5=0;
      LED6=0;
      LED7=0;
      LED8=0;
      LED9=0;
      LED10=0;

  }
}

void log_led_meter(int pwr){
  unsigned int power,i;
  for(i=10;i>=0;i--){
      if(pwr>>i){
          power=i;
          break;
      }
    }
    switch_power(power);

}


void led_meter(int pwr){

/* there is 1024 values or 10 bits of value. We arrange it linearly into 10 leds */
  unsigned int i, power;

for(i=10;i>=0;i--){
    if((int)(pwr/(i*102))){
        power=i;
        break;
    }
  }
  switch_power(power);
  //power=8;

}


