#include <REGX52.H>
#include "timer0.h"
#include "Key.h"
#include <INTRINS.H>

unsigned char KeyNum,LEDMode;

void main()
{
	 P2=0xFE;
	 Timer_Init();
   while(1)
	 {
		 KeyNum = Key();
		 if(KeyNum)
		 {
			 if(KeyNum==1)
			 {
				 LEDMode++;
				 if(LEDMode >= 2) LEDMode = 0;
			 }
		 }
	 }
}


int Count;
void Timer0_Routine() interrupt 1
{
	Count++;
	TH0 = 64535/256;
	TL0 = 64535%256;
	if (Count >= 500)
	{
		Count = 0;
		if(LEDMode == 0)
		{
			P2=_crol_(P2,1);
		}
		if(LEDMode == 1)
		{
			P2=_cror_(P2,1);
		}
	}
	
}