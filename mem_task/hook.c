#include <stdio.h>
#include "FreeRTOS.h"


#include "gpio.h"
#include "bord.h"
#include "gd32l23x.h"


void vApplicationIdleHook(void )
{
    //printf("idle hook\n");
}


void vApplicationTickHook(void )
{
    //printf("tick hook\n");
}


void vApplicationMallocFailedHook(void)
{
    printf("malloc hook\n");
}


void vApplicationDaemonTaskStartupHook(void)
{
    
	rcu_periph_clock_enable(RCU_GPIOB);
	rcu_periph_clock_enable(RCU_GPIOA);
	rcu_periph_clock_enable(RCU_GPIOC);
	rcu_periph_clock_enable(RCU_GPIOD);

    rcu_periph_clock_enable(RCU_USART0);
    rcu_periph_clock_enable(RCU_USART1);
    rcu_periph_clock_enable(RCU_LPUART);




    RCU_RSTSCK |= RCU_RSTSCK_IRC32KEN;
    rcu_osci_stab_wait(RCU_IRC32K);


    /* configure the CK_IRC16M as LPUART clock */
    rcu_lpuart_clock_config(RCU_LPUARTSRC_IRC16MDIV);
    
    rcu_periph_clock_enable(RCU_SYSCFG);
    _bord_init();

    

    printf("Daemon hook\n");
}