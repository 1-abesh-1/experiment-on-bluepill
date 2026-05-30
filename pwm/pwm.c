#include "stm32f103c6t6/pwm.h"


// Enable clock for timer peripheral on APB1 bus
// i = bit position in RCC->APB1ENR
void pwm_init(int i){
    RCC->APB1ENR |= (0x1 << i);
}


/*
 * Generic timer PWM configuration function
 * TIMx    → pointer to timer (TIM2, TIM3, etc.)
 * prescaler → divides timer clock speed
 * count     → initial counter value
 * duty      → CCR2 value (duty cycle for channel 2)
 */
void timx(TIM_TypeDef *TIMx, int prescaler, int count, uint16_t duty){

    // Set prescaler (controls timer tick frequency)
    TIMx->PSC = prescaler;

    // Set counter initial value
    TIMx->CNT = count;

    // Set auto-reload value (PWM period)
    TIMx->ARR = 1000;

    // Set duty cycle for channel 2
    TIMx->CCR2 = duty;

   TIMx->CCMR1 &= ~(0b111 << 12);
TIMx->CCMR1 |=  (0b110 << 12);   // PWM1
TIMx->CCMR1 |=  (1 << 11);       // OC2PE (FIX)

    // Enable channel 2 output (CC2E bit in CCER)
    TIMx->CCER |= (1 << 4);

    // Generate update event → loads PSC/ARR/CCR buffers into active registers
    TIMx->EGR |= 1;

    // Enable auto-reload preload (ARR buffering)
    TIMx->CR1 |= (1 << 7);

    // Force update event again (ensures synchronization before start)
    TIMx->EGR |= (1 << 0);

    // Start timer counter (PWM begins)
    TIMx->CR1 |= (1 << 0);
}