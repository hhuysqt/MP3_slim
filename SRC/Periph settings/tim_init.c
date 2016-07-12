#include "tim_init.h"
#include <stm32f10x.h>
#include <stm32f10x_tim.h>	

void tim_init(void)
{
	TIM_TimeBaseInitTypeDef initstruct;
	initstruct.TIM_Period 			= 	TIM1_PERIOD;
	initstruct.TIM_ClockDivision	=	TIM_CKD_DIV1;
	initstruct.TIM_CounterMode		=	TIM_CounterMode_Down;
	initstruct.TIM_Prescaler		=	0x0000;
	
	TIM_TimeBaseInit(TIM1,&initstruct);
}

