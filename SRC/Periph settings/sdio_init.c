#include "sdio_init.h"
#include "gpio_init.h"
#include <stm32f10x.h>
#include <stm32f10x_sdio.h>

SDIO_CmdInitTypeDef sdio_cmd;

void sdio_init(void)
{
	SDIO_InitTypeDef initstruct;
	gpio_sdio_init();
	SDIO_StructInit(&initstruct);
	initstruct.SDIO_BusWide 	=	SDIO_BusWide_4b;
	initstruct.SDIO_ClockBypass	=	SDIO_ClockBypass_Enable;
	initstruct.SDIO_ClockEdge	=	SDIO_ClockEdge_Falling;
	initstruct.SDIO_ClockPowerSave 		= 	SDIO_ClockPowerSave_Disable;
	initstruct.SDIO_HardwareFlowControl	=	SDIO_HardwareFlowControl_Disable;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_SDIO,ENABLE);
	SDIO_Init(&initstruct);
	SDIO_ClockCmd(ENABLE);
}
