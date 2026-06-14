#include <REGX52.H>
#include "timer0.h"
#include "Key.h"
#include <INTRINS.H>
#include "LCD1602.h"

unsigned char Sec,Min,Hour;
void main()
{
	LCD_Init();
	Timer_Init();
	
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
	
	while(1)
	{
		 LCD_ShowNum(2,1,Hour,2);
		 LCD_ShowNum(2,4,Min,2);
		 LCD_ShowNum(2,7,Sec,2);
	}
}


void Timer0_Routine() interrupt 1
{
	static unsigned int Count;
	Count++;
	TH0 = 64535/256;
	TL0 = 64535%256;
	if (Count >= 1000)
	{
		Count=0;
		Sec++;
		if(Sec >=60)
		{
			Sec = 0;
			Min++;
			if(Min >= 60)
			{
				Min = 0;
				Hour++;
				if(Hour>=24)
				{
					Hour=0;
				}
			}
		}
	}
	
}