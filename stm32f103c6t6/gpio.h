#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;

}GPIO_TypeDef;

/*
 * Struct defines register layout.
 * Offsets are computed automatically by compiler (order + alignment).
 * Used for memory-mapped peripheral mapping (base address + struct = registers).
 */

typedef struct{
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
}RCC_TypeDef;

//


#define GPIOA ((GPIO_TypeDef*)0x40010800)
#define GPIOB ((GPIO_TypeDef*)0x40010C00)
#define GPIOC ((GPIO_TypeDef*)0x40011000)

#define RCC ((RCC_TypeDef*)0x40021000)


//fn
void ConfigRCC(GPIO_TypeDef *GPIOx);
void ConfigOutput(
    GPIO_TypeDef *GPIOx,
    uint8_t pin
);

void Write(
    GPIO_TypeDef *GPIOx,
    uint8_t pin,
    uint8_t state
);

void Toggle(
    GPIO_TypeDef *GPIOx,
    uint8_t pin
);


void delay(uint32_t ms);





//
#endif
