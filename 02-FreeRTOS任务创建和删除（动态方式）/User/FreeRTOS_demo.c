#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "LED.h"
#include "KEY.h"

/*
	KEY.h中的延时消抖需要进行修改
*/

uint8_t KeyNum;

#define START_TASK_PRIO         1   	//任务优先级
#define START_TASK_STACK_SIZE   128		//任务堆栈大小	
TaskHandle_t    start_task_handler;		//任务句柄
void start_task( void * pvParameters );	//任务函数


#define TASK1_PRIO         2		//任务优先级
#define TASK1_STACK_SIZE   50		//任务堆栈大小	
TaskHandle_t    task1_handler;		//任务句柄
void task1( void * pvParameters );	//任务函数

#define TASK2_PRIO         3		//任务优先级
#define TASK2_STACK_SIZE   50		//任务堆栈大小	
TaskHandle_t    task2_handler;		//任务句柄
void task2( void * pvParameters );	//任务函数

#define TASK3_PRIO         4		//任务优先级
#define TASK3_STACK_SIZE   50		//任务堆栈大小	
TaskHandle_t    task3_handler;		//任务句柄
void task3( void * pvParameters );	//任务函数


void freertos_demo(void)
{    
    xTaskCreate((TaskFunction_t         )   start_task,                //任务函数
                (char *                 )   "start_task",              //任务名称
                (uint16_t )                 START_TASK_STACK_SIZE,	   //任务堆栈大小
                (void *                 )   NULL,			           //传递给任务函数的参数
                (UBaseType_t            )   START_TASK_PRIO,	       //任务优先级
                (TaskHandle_t *         )   &start_task_handler );	   //任务句柄   
				
    vTaskStartScheduler();          //开启任务调度
}


void start_task( void * pvParameters )
{
    taskENTER_CRITICAL();               /* 进入临界区 */
	
    xTaskCreate((TaskFunction_t         )   task1,				//任务函数
                (char *                 )   "task1",            //任务名称
                (uint16_t )                 TASK1_STACK_SIZE,   //任务堆栈大小
                (void *                 )   NULL,               //传递给任务函数的参数
                (UBaseType_t            )   TASK1_PRIO,         //任务优先级
                (TaskHandle_t *         )   &task1_handler );   //任务句柄   
                
    xTaskCreate((TaskFunction_t         )   task2,				//任务函数
                (char *                 )   "task2",            //任务名称
                (uint16_t )                 TASK2_STACK_SIZE,   //任务堆栈大小
                (void *                 )   NULL,               //传递给任务函数的参数
                (UBaseType_t            )   TASK2_PRIO,         //任务优先级
                (TaskHandle_t *         )   &task2_handler );   //任务句柄   
                
    xTaskCreate((TaskFunction_t         )   task3,				//任务函数
                (char *                 )   "task3",            //任务名称
                (uint16_t )                 TASK3_STACK_SIZE,   //任务堆栈大小
                (void *                 )   NULL,               //传递给任务函数的参数
                (UBaseType_t            )   TASK3_PRIO,         //任务优先级
                (TaskHandle_t *         )   &task3_handler );   //任务句柄   
				
    vTaskDelete(start_task_handler); //删除开始任务			
    taskEXIT_CRITICAL();                /* 退出临界区 */
}

/* 任务一，实现LED1每500ms翻转一次 */
void task1( void * pvParameters )
{
    while(1)
    {
        
        LED1_ON();
        vTaskDelay(500);
        LED1_OFF();
        vTaskDelay(500);
    }
}

/* 任务二，实现LED2每500ms翻转一次 */
void task2( void * pvParameters )
{
    while(1)
    {
        LED2_ON();
        vTaskDelay(500);
        LED2_OFF();
        vTaskDelay(500);
    }
}

/* 任务三，判断按键KEY1，按下KEY1删除task1 */
void task3( void * pvParameters )
{
   
    while(1)
    {
        
        KeyNum = Key_GetNum();
        if(KeyNum == 1)
        {
            if(task1_handler != NULL)
            {
                
                vTaskDelete(task1_handler);//按下KEY1删除task1 
                task1_handler = NULL;
            }

        }
        vTaskDelay(10);
    }
}
