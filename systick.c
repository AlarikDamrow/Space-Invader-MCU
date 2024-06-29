#include "tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "PLL.h"
#include <stdint.h>
void SysTick_Init(void){      NVIC_ST_CTRL_R = 0;                                    // disable SysTick during setup
    NVIC_ST_RELOAD_R = (8000000) - 1;            // number of counts to wait 40hz (assuming 80MHz clock)
    NVIC_ST_CURRENT_R = 0;                            // any write to CURRENT clears
    NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x1FFFFFFF)|0x20000000;    // priority 1
    NVIC_ST_CTRL_R = 0x07;
}