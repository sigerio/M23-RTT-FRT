#ifndef GPIO_H
#define GPIO_H


#define BAT_ADC_GPIO_PORT            GPIOA
#define BAT_ADC_GPIO_PIN             GPIO_PIN_0


#define KEY_GPIO_PORT                GPIOB
#define KEY_GPIO_PIN                 GPIO_PIN_10

#define POWER_KEEP_GPIO_PORT              GPIOB
#define POWER_KEEP_GPIO_PIN               GPIO_PIN_11



#define HY31x_SCL_GPIO_PORT            GPIOD
#define HY31x_SCL_GPIO_PIN             GPIO_PIN_5 
#define HY31x_SDA_GPIO_PORT            GPIOD
#define HY31x_SDA_GPIO_PIN             GPIO_PIN_4


#define STSx_SCL_GPIO_PORT            GPIOB
#define STSx_SCL_GPIO_PIN             GPIO_PIN_12
#define STSx_SDA_GPIO_PORT            GPIOB
#define STSx_SDA_GPIO_PIN             GPIO_PIN_13


#define OLED_SCL_GPIO_PORT            GPIOB
#define OLED_SCL_GPIO_PIN             GPIO_PIN_8
#define OLED_SDA_GPIO_PORT            GPIOB
#define OLED_SDA_GPIO_PIN             GPIO_PIN_9

#define OLED_RESET_GPIO_PORT          GPIOB
#define OLED_RESET_GPIO_PIN           GPIO_PIN_7


#define MCU_TO_BLE_TX_PORT            GPIOA
#define MCU_TO_BLE_TX_PIN             GPIO_PIN_9
#define MCU_TO_BLE_RX_PORT            GPIOA
#define MCU_TO_BLE_RX_PIN             GPIO_PIN_10



#define UART_IIC_CONV_RXSCL_PORT    GPIOC
#define UART_IIC_CONV_RXSCL_PIN     GPIO_PIN_11
#define UART_IIC_CONV_TXSDA_PORT    GPIOC
#define UART_IIC_CONV_TXSDA_PIN     GPIO_PIN_10

#define XFLASH_SPI_CS_PORT              GPIOA   //NSS
#define XFLASH_SPI_CS_PIN               GPIO_PIN_4
#define XFLASH_SPI_MOSI_PORT            GPIOA
#define XFLASH_SPI_MOSI_PIN             GPIO_PIN_7
#define XFLASH_SPI_MISO_PORT            GPIOA
#define XFLASH_SPI_MISO_PIN             GPIO_PIN_6
#define XFLASH_SPI_SCK_PORT             GPIOA
#define XFLASH_SPI_SCK_PIN              GPIO_PIN_5


#define MCU_TO_DEBUG_TX_PORT            GPIOA
#define MCU_TO_DEBUG_TX_PIN             GPIO_PIN_2
#define MCU_TO_DEBUG_RX_PORT            GPIOA
#define MCU_TO_DEBUG_RX_PIN             GPIO_PIN_3


#define BLE_WHE_CONNECT_SL_PORT          GPIOA
#define BLE_WHE_CONNECT_SL_PIN           GPIO_PIN_8

#define BLE_BE_CONNECT_AS_SL_PORT        GPIOC
#define BLE_BE_CONNECT_AS_SL_PIN         GPIO_PIN_9


#define BLE_POWER_CONTROL_PORT           GPIOC
#define BLE_POWER_CONTROL_PIN            GPIO_PIN_8

#define BLE_SEND_DERICTION_PORT          GPIOC
#define BLE_SEND_DERICTION_PIN           GPIO_PIN_6   


#define RGB_R_GPIO_PORT            GPIOC
#define RGB_R_GPIO_PIN             GPIO_PIN_5
#define RGB_G_GPIO_PORT            GPIOB
#define RGB_G_GPIO_PIN             GPIO_PIN_0
#define RGB_B_GPIO_PORT            GPIOB
#define RGB_B_GPIO_PIN             GPIO_PIN_1

#define DEBUG_LED_GPIO_PORT            GPIOB
#define DEBUG_LED_GPIO_PIN             GPIO_PIN_14


#define TEMP_SCL_GPIO_PORT            GPIOB
#define TEMP_SCL_GPIO_PIN             GPIO_PIN_5
#define TEMP_SDA_GPIO_PORT            GPIOB
#define TEMP_SDA_GPIO_PIN             GPIO_PIN_6


#define OLED_AF                       GPIO_AF_8
#define XFLASH_AF                     GPIO_AF_5
#define MCU_TO_BLE_AF                 GPIO_AF_7
#define MCU_TO_DEBUG_AF               GPIO_AF_7
#define UART_IIC_CONV_AF              GPIO_AF_8
#define RGB_AF                        GPIO_AF_1



void bsp_gpio_init(void);
#endif


