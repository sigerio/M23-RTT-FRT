/*!
    \file    gd32l23x_it.c
    \brief   interrupt service routines

    \version 2025-02-10, V2.2.0, firmware for GD32L23x, add support for GD32L235
*/

/*
    Copyright (c) 2025, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#include "gd32l23x_it.h"
#include "bord.h"
#include "gpio.h"
#include "gd32l23x.h"


#ifdef GD32L235
#define SRAM_ECC_ERROR_HANDLE(s)    do{}while(1)
#endif /* GD32L235 */
/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
#ifdef GD32L235
    if(SET == syscfg_flag_get(SYSCFG_FLAG_SRAM_PCEF)) {
        SRAM_ECC_ERROR_HANDLE("SRAM parity check error\r\n");
    }else{
#endif /* GD32L235 */
        /* if NMI exception occurs, go to infinite loop */
        /* HXTAL clock monitor NMI error or NMI pin error */
        while(1) {
        }
#ifdef GD32L235
    }
#endif /* GD32L235 */
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
// void HardFault_Handler(void)
// {
//    /* if Hard Fault exception occurs, go to infinite loop */
//    while(1) {
//    }
// }







/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
// void SVC_Handler(void)
// {
//     /* if SVC exception occurs, go to infinite loop */
//     while(1) {
//     }
// }



/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
// void PendSV_Handler(void)
// {
//     /* if PendSV exception occurs, go to infinite loop */
//     while(1) {
//     }
// }

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
/**
* @brief  SysTick中断服务函数
* @param  无
* @retval 无
*
* @attention
* SysTick中断服务函数在固件库文件stm32f10x_it.c中也定义了，而现在
* 在board.c中又定义一次，那么编译的时候会出现重复定义的错误，解决
* 方法是可以把stm32f10x_it.c中的注释或者删除即可。
*/

// void SysTick_Handler(void)
// {
               
// }


/*!
    \brief      this function handles LPTIMER exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
#ifdef GD32L233
void LPTIMER_IRQHandler()
#else
void LPTIMER0_IRQHandler()
#endif
{
    if(RESET != lptimer_interrupt_flag_get(LPTIMER, LPTIMER_INT_FLAG_CARM)) {
        // lptimer_interrupt_flag_clear(LPTIMER, LPTIMER_INT_FLAG_CARM);
        LPTIMER_INTC(LPTIMER) |= LPTIMER_INT_FLAG_CARM;

    }
}


/*!
    \brief      this function handles USART RBNE interrupt request and TBE interrupt request
    \param[in]  none
    \param[out] none
    \retval     none
*/
void USART0_IRQHandler(void)
{


}


void USART1_IRQHandler(void)
{

    if(RESET != usart_interrupt_flag_get(MCU_TO_DEBUG_COM, USART_INT_FLAG_RBNE)) {
        int rec = usart_data_receive(MCU_TO_DEBUG_COM);
		rec = 0;
        GPIO_TG(DEBUG_LED_GPIO_PORT) = DEBUG_LED_GPIO_PIN;
    }

}

void LPUART_IRQHandler(void)
{
    
    
}


/*!\n    \brief      this function handles RTC wakeup timer interrupt request\n    \param[in]  none\n    \param[out] none\n    \retval     none\n*/
void RTC_WKUP_IRQHandler(void)
{
    if(RESET != rtc_flag_get(RTC_FLAG_WT)) {
        /* 清除RTC唤醒标志 */
        rtc_flag_clear(RTC_FLAG_WT);
        exti_flag_clear(EXTI_20);
        /* 示例：打印信息 */
        // GPIO_TG(DEBUG_LED_GPIO_PORT) = DEBUG_LED_GPIO_PIN;
    }
}


