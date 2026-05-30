#ifndef PWM_H
#define PWM_H
#include "gpio.h"
typedef struct{
    volatile uint32_t CR1;      // 0x00
    volatile uint32_t CR2;      // 0x04
    volatile uint32_t SMCR;     // 0x08
    volatile uint32_t DIER;     // 0x0C
    volatile uint32_t SR;       // 0x10
    volatile uint32_t EGR;      // 0x14
    volatile uint32_t CCMR1;    // 0x18
    volatile uint32_t CCMR2;    // 0x1C
    volatile uint32_t CCER;     // 0x20
    volatile uint32_t CNT;      // 0x24
    volatile uint32_t PSC;      // 0x28
    volatile uint32_t ARR;      // 0x2C
    volatile uint32_t RCR;      // 0x30 (advanced timers only)
    volatile uint32_t CCR1;     // 0x34
    volatile uint32_t CCR2;     // 0x38
    volatile uint32_t CCR3;     // 0x3C
    volatile uint32_t CCR4;     // 0x40
    volatile uint32_t BDTR;     // 0x44
    volatile uint32_t DCR;      // 0x48
    volatile uint32_t DMAR;     // 0x4C
} TIM_TypeDef;

#define TIM1 ((TIM_TypeDef*)0x40012C00)
#define TIM2 ((TIM_TypeDef*)0x40000000)
#define TIM3 ((TIM_TypeDef*)0x40000400)
#define TIM4 ((TIM_TypeDef*)0x40000800)


void pwm_init(int i);
void timx(TIM_TypeDef *TIMx, int prescaler, int count, uint16_t duty);
#endif