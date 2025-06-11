#include "rtconfig.h"
#include <rthw.h>
#include <rtthread.h>
#include "bord.h"
#include "gpio.h"
#include <stdio.h>

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)       
#define RT_HEAP_SIZE 1024
/* 从内部SRAM里面分配一部分静态内存来作为rtt的堆空间，这里配置为4KB */
static uint32_t rt_heap[RT_HEAP_SIZE];
rt_weak void *rt_heap_begin_get(void)
{
    return rt_heap;
}

rt_weak void *rt_heap_end_get(void)
{
    return rt_heap + RT_HEAP_SIZE;
}
#endif


/** System Clock Configuration
*/
void SystemClock_Config(void)
{
    SysTick_Config(SystemCoreClock / RT_TICK_PER_SECOND);
    NVIC_SetPriority(SysTick_IRQn, 0);
}


void SysTick_Handler(void)
{
    /* 进入中断 */
    rt_interrupt_enter();                 

    /* 更新时基 */
    rt_tick_increase();                   

    /* 离开中断 */
    rt_interrupt_leave();                 
}



void rt_hw_console_output(const char *str)
{
    /* 进入临界段 */
    rt_enter_critical();

    /* 直到字符串结束 */
    while (*str!='\0')
    {
        /* 换行 */

        {
            usart_data_transmit(MCU_TO_DEBUG_COM, *str++);
            while (RESET == usart_flag_get(MCU_TO_DEBUG_COM, USART_FLAG_TBE))
            {
            }
        }
        
    }

    /* 退出临界段 */
    rt_exit_critical();
}




void rt_hw_board_init(void)
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
	//GPIO_TG(DEBUG_LED_GPIO_PORT) = DEBUG_LED_GPIO_PIN;
	

	SystemCoreClockUpdate();
	SystemClock_Config();
	printf("123\n");
	
	
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();

#endif

#if defined(RT_USING_CONSOLE) && defined(RT_USING_DEVICE)
        rt_console_set_device(RT_CONSOLE_DEVICE_NAME);

#endif

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
        rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get());

#endif
	//SysTick_Handler();
}