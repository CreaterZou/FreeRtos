#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

//�����ں˵��ȷ�ʽ  1Ϊ��ռʽ  0Ϊ����ʽ(ʱ��Ƭ)
#define configUSE_PREEMPTION		1
//�����Ƿ�ʹ��IDLE���������Ӻ���
#define configUSE_IDLE_HOOK			0
//�����Ƿ�ʹ��TICK�δ������Ӻ���
#define configUSE_TICK_HOOK			0
//����CPU��Ƶ(HZ)
#define configCPU_CLOCK_HZ			( ( unsigned long ) 72000000 )	
//����ϵͳʱ�ӽ�����(HZ)
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 )
//���ù��û�ʹ�õ�������ȼ���
#define configMAX_PRIORITIES		( 5 )
//���ÿ��������ջ��С
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 128 )
//���öѴ�С
#define configTOTAL_HEAP_SIZE		( ( size_t ) ( 10 * 1024 ) )
//���������������ַ���
#define configMAX_TASK_NAME_LEN		( 16 )
//�����Ƿ�ʹ�ÿ��ӻ����ٵ���
#define configUSE_TRACE_FACILITY	0
/*  
ϵͳʱ�ӽ��ļ���ʹ��TickType_t�������Ͷ���ġ�
����û�ʹ���˺궨�� configUSE_16_BIT_TICKS��
��ôTickType_t����ľ���16λ�޷�������
���û��ʹ�ܣ���ôTickType_t����ľ���32λ�޷�������
����32λ�ܹ��Ĵ�������һ��Ҫ��ֹ�˺궨�壬�����ô˺궨����ֵΪ0���ɡ�
��16λ�޷�����������Ҫ����8λ��16λ�ܹ��Ĵ�������
*/
#define configUSE_16_BIT_TICKS		0
/*
�˲�������ʹ�����������ͬ���ȼ�������ֻ������������������ʱ���˲�������Ч����
1.ʹ����ռʽ��������
2.�д������������ͬ���ȼ�������
����Ϊ1���Ϳ���ʹ�ܴ������ˣ�ʵ��Ӧ���в������û�ʹ�ô˹��ܣ���������Ϊ0���ɡ�
*/
#define configIDLE_SHOULD_YIELD		1

/***********************************************************/

//����ʹ��ʱҪ����
#define configUSE_COUNTING_SEMAPHORES 	1

//�����ʱ��ʹ��ʱҪ����
#define configUSE_TIMERS                0
//�����ʱ�������ȼ�
#define configTIMER_TASK_PRIORITY       50
//�����ʱ��ջ��С
#define configTIMER_TASK_STACK_DEPTH    50
//�����ʱ�����д�С
#define configTIMER_QUEUE_LENGTH        50

/***********************************************************/

/* Co-routine definitions. */
//�����Ƿ�ʹ�ܺ���ʽ������غ���
#define configUSE_CO_ROUTINES 		0
//����ɹ��û�ʹ�õ����ĺ���ʽ�������ȼ���
#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

#define INCLUDE_vTaskPrioritySet        1       //�����������ȼ�
#define INCLUDE_uxTaskPriorityGet        1        //��ȡ�������ȼ�
#define INCLUDE_vTaskDelete                1        //ɾ������
#define INCLUDE_vTaskCleanUpResources    0        //����������Դ
#define INCLUDE_vTaskSuspend            1        //��������
#define INCLUDE_vTaskDelayUntil            1        //��ʱֱ��
#define INCLUDE_vTaskDelay                1        //��ʱ

//�����ں��ж����ȼ���
#define configKERNEL_INTERRUPT_PRIORITY 		255

/*
���ڴ����ȼ����жϿ��԰�ȫ����FreeRTOS��API������
���ڴ����ȼ����ж���FreeRTOS���ܽ�ֹ�ģ�
�жϷ�����Ҳ���ܵ���FreeRTOS��API������
����STM32Ϊ��������NVIC���ȼ�����Ϊ4������16����ռ���ȼ���0��ߣ�15��ͣ�
����configMAX_SYSCALL_INTERRUPT_PRIORITYΪ5����
���ȼ�0-4���ᱻFreeRTOS��ֹ���жϲ����Ե���FreeRTOS��API������
���ȼ�5-15���Ե�����FROM_ISR��β��API�������������ǿ����ж�Ƕ�ס�
*/
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	191

/*
���ֵ�ǽ�configMAX_SYSCALL_INTERRUPT_PRIORITY�����㣬
ȡ��оƬ֧�ֵ����ȼ���Чλ���õ���ֵ��
������δʹ�á�ֻ����Ϊ�û�������ռ���ȼ��Ĳο�
*/
#define configLIBRARY_KERNEL_INTERRUPT_PRIORITY	15

#define xPortPendSVHandler PendSV_Handler
#define vPortSVCHandler SVC_Handler
//#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */
