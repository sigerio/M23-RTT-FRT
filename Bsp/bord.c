#include "bord.h"
#include <stdlib.h>
#include "gpio.h"
#include <stdarg.h>
#include "gd32l23x.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*will curten i2c spi adc wdg and so on*/

void bsp_usart_config(void)
{
    /* USART configure */
    usart_deinit(MCU_TO_BLE_COM);
    usart_word_length_set(MCU_TO_BLE_COM, USART_WL_8BIT);
    usart_stop_bit_set(MCU_TO_BLE_COM, USART_STB_1BIT);
    usart_parity_config(MCU_TO_BLE_COM, USART_PM_NONE);
    usart_baudrate_set(MCU_TO_BLE_COM, 115200U);
    usart_receive_config(MCU_TO_BLE_COM, USART_RECEIVE_ENABLE);
    usart_transmit_config(MCU_TO_BLE_COM, USART_TRANSMIT_ENABLE);

    usart_enable(MCU_TO_BLE_COM);

    /* LPUART configure */
    usart_deinit(MCU_TO_DEBUG_COM);
    usart_word_length_set(MCU_TO_DEBUG_COM, USART_WL_8BIT);
    usart_stop_bit_set(MCU_TO_DEBUG_COM, USART_STB_1BIT);
    usart_parity_config(MCU_TO_DEBUG_COM, USART_PM_NONE);
    usart_baudrate_set(MCU_TO_DEBUG_COM, 115200U);
    usart_receive_config(MCU_TO_DEBUG_COM, USART_RECEIVE_ENABLE);
    usart_transmit_config(MCU_TO_DEBUG_COM, USART_TRANSMIT_ENABLE);

    usart_enable(MCU_TO_DEBUG_COM);



    
    lpuart_deinit(UART_IIC_CONV_COM);
    lpuart_word_length_set(UART_IIC_CONV_COM, LPUART_WL_8BIT);
    lpuart_stop_bit_set(UART_IIC_CONV_COM, LPUART_STB_1BIT);
    lpuart_parity_config(UART_IIC_CONV_COM, LPUART_PM_NONE);
    lpuart_baudrate_set(UART_IIC_CONV_COM, 115200U);
    lpuart_receive_config(UART_IIC_CONV_COM, LPUART_RECEIVE_ENABLE);
    lpuart_transmit_config(UART_IIC_CONV_COM, LPUART_TRANSMIT_ENABLE);

    lpuart_enable(UART_IIC_CONV_COM);

}




void bsp_nvic_init(void)
{
    nvic_irq_enable(LPTIMER_IRQn, 0U);
    nvic_irq_enable(USART0_IRQn, 0);
    nvic_irq_enable(USART1_IRQn, 1);
    
}



void _bord_init(void)
{
    bsp_gpio_init();
    bsp_usart_config();  
    
    bsp_nvic_init();
    
}








int fputc(int ch, FILE *f)
{
  usart_data_transmit(MCU_TO_DEBUG_COM, (uint8_t)ch);
  while (RESET == usart_flag_get(MCU_TO_DEBUG_COM, USART_FLAG_TBE))
  {
  }

  return ch;
}
uint8_t P_LEVL = 0;
void D_P(uint8_t levl, const char *fmt, ...)
{

  uint16_t i = 0;
  uint8_t buf[512] = {0};
  if (P_LEVL != levl)
    return;
  va_list args;
  va_start(args, fmt);
  vsprintf((char *)buf, fmt, args);
  va_end(args);
  i = strlen((const char *)buf);
  for (int q = 0; q < i; q++)
  {
    usart_data_transmit(MCU_TO_DEBUG_COM, buf[q]);
    while (RESET == usart_flag_get(MCU_TO_DEBUG_COM, USART_FLAG_TBE))
    {
    }
  }

}


void uart_send(uint32_t usart_periph, uint8_t* data, uint16_t len)
{
    for (int q = 0; q < len; q++)
    {
        usart_data_transmit(usart_periph, data[q]);
        while (RESET == usart_flag_get(usart_periph, USART_FLAG_TBE));
    }
}


