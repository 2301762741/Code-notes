//#inclue "System.h"
#include "stm32f4xx.h"   

void GPIO_LED2int()
{
	RCC->AHB1ENR=RCC->AHB1ENR|1;//打开GPIOA的时钟，以开始操作寄存器，配置GPIO口
	GPIOA->MODER=GPIOA->MODER&~(3<<10);//配置寄存器，但是寄存器状态不稳定，所以需要先清零。查表可知，PA5口在MODER5（&~保证其他位1、0状态不变）
	GPIOA->MODER=GPIOA->MODER|(1<<10);//点灯需要打开通用输出模式，对应寄存器状态查表可知，01为通用输出模式
	GPIOA->OTYPER=GPIOA->OTYPER&~(1<<5);//将输出类型寄存器设置为推挽模式，此时只需要把寄存器清零
	GPIOA->OSPEEDR=GPIOA->OSPEEDR&~(3<<10);//清零
	GPIOA->OSPEEDR=GPIOA->OSPEEDR|(2<<10);//一般来说，输出状态常用高速
	GPIOA->PUPDR=GPIOA->PUPDR&~(3<<10);//这里需要的是浮空模式，直接清零就好
	GPIOA->ODR=GPIOA->ODR|(1<<5);//一般设置为1时输出高电平，灯灭
	
	GPIOA->MODER=GPIOA->MODER&~(3);//配置寄存器，但是寄存器状态不稳定，所以需要先清零。查表可知，PA5口在MODER5（&~保证其他位1、0状态不变）
	GPIOA->MODER=GPIOA->MODER|1;//点灯需要打开通用输出模式，对应寄存器状态查表可知，01为通用输出模�
	GPIOA->OTYPER=GPIOA->OTYPER&0;//将输出类型寄存器设置为推挽模式，此时只需要把寄存器清零
	GPIOA->OSPEEDR=GPIOA->OSPEEDR&~(3);//清零
	GPIOA->OSPEEDR=GPIOA->OSPEEDR|(2);//一般来说，输出状态常用高速
	GPIOA->PUPDR=GPIOA->PUPDR&~(3);//这里需要的是浮空模式，直接清零就好
	GPIOA->ODR=GPIOA->ODR|(1);//一般设置为1时输出高电平，灯灭
}

void LED_ON(void)
{
	GPIOA->ODR=GPIOA->ODR|(1<<5);//一般设置为1时输出高电平，灯灭
}

void LED_OFF(void)
{
	GPIOA->ODR=GPIOA->ODR&~(1<<5);//清零，设置为0，低电平，灯亮(前面有~，反码，变0需要用1）
}
