#include <REGX52.H>

void Timer_Init()
{
	// TMOD = 0X01; // 0000 0001
	TMOD = TMOD & 0xF0;
	TMOD = TMOD | 0x01;
	TF0 = 0;
	TR0 = 1;
	TH0 = 64535/256;
	TL0 = 64535%256;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}