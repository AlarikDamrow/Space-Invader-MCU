#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "Switches.h"


// Initialize the onboard two switches.
void Switch_Init(void){
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020;       //activate clock for Port F
  while((SYSCTL_RCGC2_R&0x20) == 0){};
  GPIO_PORTF_LOCK_R = 0x4C4F434B;     //unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x11;                        //allow changes for PF4 and PF0 
  GPIO_PORTF_DIR_R &= ~0x11;        //make onboard buttons PF4 and PF0 inputs
  GPIO_PORTF_DEN_R |= 0x11;         //enable digital I/0 on PF4,0
  GPIO_PORTF_PCTL_R &= ~0x000F000F; //configure as GPIO
  GPIO_PORTF_AMSEL_R &= ~0x11;      //disable analog functionality on PF4,0
  GPIO_PORTF_PUR_R |= 0x11;             //enable weak pull-up on PF4,0
  GPIO_PORTF_IS_R &= ~0x11;             //PF4,PF0 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x11;            //PF4,PF0 is not both edges
  GPIO_PORTF_IEV_R &= ~0x11;            //PF4,PF0 falling edge event
  GPIO_PORTF_ICR_R = 0x11;              //clear flags 4,0
  GPIO_PORTF_IM_R |= 0x11;              //arm interrupt on PF4,PF0
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF1FFFFF)|0x00400000; //set priority to 2
  NVIC_EN0_R = 0x40000000;              //enable interrupt 30 in NVIC     
}