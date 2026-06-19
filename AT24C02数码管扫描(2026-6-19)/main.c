#include <REGX52.H>
#include "Timer0.h"
#include "Nixie.h"
#include "Key.h"
#include "Delay.h"

unsigned char KeyNum;
unsigned char Min,Sec,MiniSec;

void main()
{
	 Timer0_Init();
   while(1)
	 {
		 KeyNum = Key();
		 if(KeyNum)
		 {
			 
		 }
		 Nixie_SetBuf(1,Min/10);
		 Nixie_SetBuf(2,Min%10);
		 Nixie_SetBuf(3,11);
		 
		 Nixie_SetBuf(4,Sec/10);
		 Nixie_SetBuf(5,Sec%10);
		 Nixie_SetBuf(6,11);
		 
		 Nixie_SetBuf(7,MiniSec/10);
		 Nixie_SetBuf(8,MiniSec%10);
	 }
}

void Sec_Loop(void)
{
	MiniSec++;
	if(MiniSec >= 100)
	{
		MiniSec = 0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{
				Min=0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1,T0Count2,T0Count3;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		Key_Loop();
	}
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Nixie_Loop();
	}
	T0Count3++;
	if(T0Count3>10)
	{
		T0Count3=0;
		Sec_Loop();
	}
}
