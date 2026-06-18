#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer=P2^5;

void main()
{
	 Timer0Init(void);
   while(1)
	 {
		 
	 }
}



void Timer0_Routine() interrupt 1
{
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	Buzzer=!Buzzer;
}

