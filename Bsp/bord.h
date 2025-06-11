#ifndef BORD_H
#define BORD_H

#include "gd32l23x.h"

#define VREF_ADC_CHANNEL             ADC_CHANNEL_17
#define BAT_ADC_CHANNEL              ADC_CHANNEL_0

#define MCU_TO_BLE_COM               USART0
#define MCU_TO_DEBUG_COM             USART1

#define MCU_TO_BLE_CHA               DMA_CH1
#define MCU_TO_OLED_CHA              DMA_CH0

#define UART_IIC_CONV_COM            LPUART0
#define OLED_I2C_X                   I2C1

#define XFLASH_SPI_X                 SPI0


void bsp_nvic_init(void);

void _bord_init(void);

void D_P(uint8_t levl, const char *fmt, ...);
void uart_send(uint32_t usart_periph, uint8_t* data, uint16_t len);
#endif

