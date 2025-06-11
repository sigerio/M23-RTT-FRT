#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

#include "gpio.h"
#include "bord.h"
#include "gd32l23x.h"


#define START_TASK_PRIO         10           /* 任务优先级 */
#define START_STK_SIZE          256         /* 任务堆栈大小 */
TaskHandle_t StartTask_Handler;             /* 任务句柄 */

#define led_TASK_PRIO         10           /* 任务优先级 */
#define led_STK_SIZE          256         /* 任务堆栈大小 */
TaskHandle_t led_on_Handler;             /* 任务句柄 */
TaskHandle_t led_off_Handler;             /* 任务句柄 */

void led_on(void *pvParameters)
{
    pvParameters = pvParameters;

    while(1)
    {
        GPIO_BC(DEBUG_LED_GPIO_PORT) = DEBUG_LED_GPIO_PIN;
        vTaskDelay(500);
    }
}



void led_off(void *pvParameters)
{
    pvParameters = pvParameters;

    while(1)
    {
        GPIO_BOP(DEBUG_LED_GPIO_PORT) = DEBUG_LED_GPIO_PIN;
        vTaskDelay(1000);
    }
}



void start_task(void *pvParameters)
{
	pvParameters = pvParameters;
	taskENTER_CRITICAL();           /* 进入临界区 */


    xTaskCreate((TaskFunction_t )led_on,
                (const char *   )"ledon",
                (uint16_t       )led_STK_SIZE,
                (void *         )NULL,
                (UBaseType_t    )led_TASK_PRIO,
                (TaskHandle_t * )&led_on_Handler);

    xTaskCreate((TaskFunction_t )led_off,
                (const char *   )"ledoff",
                (uint16_t       )led_STK_SIZE,
                (void *         )NULL,
                (UBaseType_t    )led_TASK_PRIO,
                (TaskHandle_t * )&led_off_Handler);


    vTaskDelete(StartTask_Handler); /* 删除开始任务 */
    taskEXIT_CRITICAL();            /* 退出临界区 */

}

void demo(void)
{

    xTaskCreate((TaskFunction_t )start_task,
                (const char *   )"start_task",
                (uint16_t       )START_STK_SIZE,
                (void *         )NULL,
                (UBaseType_t    )START_TASK_PRIO,
                (TaskHandle_t * )&StartTask_Handler);
    vTaskStartScheduler(); /* 开启任务调度 */

}


