#include "rtconfig.h"

#include "rtthread.h"
#include "gpio.h"
#include "bord.h"


static struct rt_thread led1_thread;

/* 定义线程控栈时要求RT_ALIGN_SIZE个字节对齐 */
rt_align(RT_ALIGN_SIZE)
/* 定义线程栈 */
static rt_uint8_t rt_led1_thread_stack[1024];

static void led1_thread_entry(void* parameter);


static void led1_thread_entry(void* parameter)
{
    while (1)
    {
        GPIO_TG(DEBUG_LED_GPIO_PORT) = DEBUG_LED_GPIO_PIN;
        rt_thread_delay(500);   /* 延时500个tick */     
    }
}



  



void demo(void)
{

    rt_thread_init(&led1_thread,                  /* 线程控制块 */     
            "led1",                       /* 线程名字 */           
            led1_thread_entry,            /* 线程入口函数 */       
            RT_NULL,                      /* 线程入口函数参数 */   
            &rt_led1_thread_stack[0],     /* 线程栈起始地址 */     
            sizeof(rt_led1_thread_stack), /* 线程栈大小 */         
            3,                            /* 线程的优先级 */       
            20);   

    rt_thread_startup(&led1_thread);             /* 启动线程，开启调度 */

}


