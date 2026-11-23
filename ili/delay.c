#include "stm32f10x.h"                  // Device header
#include "delay.h"

static u32 fac_us = 0;	// 微秒倍乘因子
static u32 fac_ms = 0;	// 毫秒倍乘因子

// 初始化SysTick，HCLK=72MHz
void delay_init(void)
{
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
    fac_us = SystemCoreClock / 8000000;	// 72M/8 =9M， 1us =9个时钟
    fac_ms = fac_us * 1000;
}

// 延时 nus 微秒
void delay_us(u32 nus)
{
    u32 temp;
    SysTick->LOAD = nus * fac_us;
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
        temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16)));
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0x00;
}

// 延时 nms 毫秒
void delay_ms(u32 nms)
{
    u32 temp;
    SysTick->LOAD = nms * fac_ms;
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
        temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16)));
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0x00;
}

// 延时 ns 秒
void delay_s(u32 ns)
{
    while(ns--)
    {
        delay_ms(1000);
    }
}
