#include "stm32f103c6t6/gpio.h"

void ConfigRCC(GPIO_TypeDef *GPIOx){
  if(GPIOx==GPIOA)  RCC->APB2ENR |=(1<<2);
   if(GPIOx==GPIOB)  RCC->APB2ENR |=(1<<3);
    if(GPIOx==GPIOC)  RCC->APB2ENR |=(1<<4);
};

void ConfigOutput(
    GPIO_TypeDef *GPIOx,
    uint8_t pin
){
volatile uint32_t *config;

if(pin<8){
    config=&GPIOx->CRL;
}else{

        config=&GPIOx->CRH;
        pin-=8;
    }

    *config &= ~(0xF<<(pin*4));

*config |= (0x2<<(pin*4));


};


void Write(
    GPIO_TypeDef *GPIOx,
    uint8_t pin,
    uint8_t state
){

    if(state){
        GPIOx->BSRR = (1UL << pin);
    }else{
        GPIOx->BSRR = (1UL << (pin + 16));
    }

};

void Toggle(
    GPIO_TypeDef *GPIOx,
    uint8_t pin
){
GPIOx->ODR ^=(1<<pin);
};



void delay(uint32_t ms)
{
    for(uint32_t i = 0; i < (ms * 8000); i++)
    {
        __asm__("nop");
    }
}

void ConfigInput(GPIO_TypeDef *GPIOx, uint8_t pin) {
    volatile uint32_t *config;
    uint8_t localPin = pin;  // don't modify the original pin

    if(localPin < 8) {
        config = &GPIOx->CRL;
    } else {
        config = &GPIOx->CRH;
        localPin -= 8;
    }
*config &= ~(0xF << (localPin * 4));
*config |=  (0x8 << (localPin * 4));  // pull-up/pull-down mode
GPIOx->ODR |= (1 << pin);
}
uint8_t Read(
    GPIO_TypeDef *GPIOx,
    uint8_t pin
){
    return (GPIOx->IDR >> pin) & 1;
};
