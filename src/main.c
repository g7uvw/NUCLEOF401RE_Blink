// Simple GPIO demo, blinking the LED on the ST Nucleo F401RE development board.

#include "stm32f4xx.h"

void ms_delay (int ms)
{
  while (ms-- > 0)
    {
      volatile int x = 500;
      while (x-- > 0)
	__asm ("nop");
    }
}
																					  
int main (void)
{
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST;    // Reset GPIOA 
    RCC->AHB1RSTR = 0;                         // Exit reset state
    
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;       // Enable GPIOA clock
    GPIOA->MODER |= GPIO_MODER_MODER5_0;	   // Enable Output on A5 (LED2 on Nucleo F401RE board)
    
    while (1)
    {
    	GPIOA->ODR ^= (1 << (5));			   // toggle LED
    	ms_delay(800);
    }

  return 0;
}
