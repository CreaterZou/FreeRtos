#include "stm32f10x.h"                  // Device header
#include "FreeRTOS.h"
#include "task.h"
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;//结构体变量
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;//上拉输入
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_11;//端口选择
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_50MHz;//速度选择
	GPIO_Init(GPIOB,&GPIO_InitStructure);//初始化
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)//读取B1端口值
	{
		//Delay_ms(20);
		vTaskDelay(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0);//卡在这里，直到松手
		//Delay_ms(20);//消抖
		vTaskDelay(20);
		KeyNum=1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)//读取B11端口值
	{
		//Delay_ms(20);
		vTaskDelay(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0);//卡在这里，直到松手
		//Delay_ms(20);//消抖
		vTaskDelay(20);
		KeyNum=2;
	}
	
	return KeyNum;
}
