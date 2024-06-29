#include "tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "PLL.h"
#include <stdint.h>
void SysTick_Handler(void){
  time_to_draw = 1;
}