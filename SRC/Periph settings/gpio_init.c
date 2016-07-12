#include "gpio_init.h"
#include <stm32f10x.h>
#include <stm32f10x_gpio.h>

void gpio_sdio_init(void)
{
	GPIO_InitTypeDef initstruct;
	initstruct.GPIO_Mode =	GPIO_Mode_Out_PP;
	initstruct.GPIO_Speed=	GPIO_Speed_50MHz;
	
	initstruct.GPIO_Pin  =	GPIO_Pin_6|	GPIO_Pin_7|
							GPIO_Pin_8|	GPIO_Pin_9|
							GPIO_Pin_10|GPIO_Pin_11|
							GPIO_Pin_12;
	GPIO_Init(GPIOC,&initstruct);
	initstruct.GPIO_Pin	 = 	GPIO_Pin_2;
	GPIO_Init(GPIOD,&initstruct);
	initstruct.GPIO_Pin  =	GPIO_Pin_8|GPIO_Pin_9;
	GPIO_Init(GPIOB,&initstruct);
	
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA|
													RCC_APB2Periph_GPIOB|
													RCC_APB2Periph_GPIOC|
												RCC_APB2Periph_GPIOD,ENABLE);
	
}
