#include "stdint.h"
 #define RCC_APB2ENR (*(volatile uint32_t*)(0x40021000+0x18))
  #define GPIOA_CRL (*(volatile uint32_t*)(0x40010800))
#define GPIOB_CRL (*(volatile uint32_t*)(0x40010C00))
#define GPIOC_CRH (*(volatile uint32_t*)(0x40011000+0x04))
#define GPIOA_BSRR (*(volatile uint32_t*)(0x40010800+0x10))
#define GPIOB_BSRR (*(volatile uint32_t*)(0x40010C00+0x10))
#define GPIOC_BSRR (*(volatile uint32_t*)(0x40011000+0x04+0x10))
int main(void){
     RCC_APB2ENR |= (1<<2) | (1<<3) | (1<<4);
  GPIOA_CRL &=~(0xF<<4*1);
  GPIOA_CRL|=(0b0010<<4*1);

GPIOB_CRL &=~(0b1111);
GPIOB_CRL |=(0b0010);

GPIOC_CRH &=~(0xF << 20);
GPIOC_CRH |=(0b0010 << 20);

while(1){
    GPIOA_BSRR |= (1<<1);
    GPIOB_BSRR|=1;
    GPIOC_BSRR |=(1 << 13);
}
}
