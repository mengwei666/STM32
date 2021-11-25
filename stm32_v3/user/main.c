#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "misc.h"
#include "delay.h"
#include "usart.h"

int main(void)
{		
 	u8 t=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 	  
	uart_init(115200);	 
  	while(1)
	{
		printf("t:%d\r\n",t);
		delay_ms(500);
		t++;
	}	 
} 

