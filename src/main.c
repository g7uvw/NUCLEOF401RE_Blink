// Simple PWM demo, changing the LED brighness on the ST Nucleo F401RE development board.

// The LED pin shares with TIM2_CH1 / TIM2_ETR alternate functions AF01 according to the data sheet

#include "stm32f4xx.h"


int main (void)
{

    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOARST;              // Reset GPIOA
    RCC->AHB1RSTR = 0;                                   // Exit reset state
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;                 // Enable GPIOA clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;                  // Enable Timer Clock
    GPIOA->MODER |= GPIO_MODER_MODER5_1;                 // Set GPIOA.5 to Alternate function (Took some digging to find this!)
    GPIOA->AFR[0]|= 0x100000;                            // Set Alternate function AF01 on pin 5 (defines seem to be missing?)

    TIM2->PSC = 29999;                                   // I think the counter clock is 84Mhz, divide it down a bit. Prescale = PSC +1
    TIM2->ARR = 501;                                     // Auto start at 1 on roll over
    TIM2->CCR1 = 500;                                    // Value to compare with, 500 seems a nice number...
    TIM2->CCMR1 = TIM_CCMR1_OC1M_0 |TIM_CCMR1_OC1M_1;    // Output changes on channel 1 compare match. Also took some finding!
    TIM2->CCER = TIM_CCER_CC1E;                          // Enable compare
    TIM2->CR1 |= TIM_CR1_CEN;    //start timer
    for(;;)
	{}
        return 0;
}
