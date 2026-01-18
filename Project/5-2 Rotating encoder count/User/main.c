#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"

int16_t num;

int main(void)
{
	/*模块初始化*/
	OLED_Init();			//OLED初始化
	Encoder_Init();		//计数传感器初始化
	
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "num:");	//1行1列显示字符串Count:
	
	while (1)
	{
		num += EncouderCount_Get();
		OLED_ShowSignedNum(1, 5, num, 5);		//OLED不断刷新显示CountSensor_Get的返回值
	}
}
