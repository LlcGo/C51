#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

#define MATRIX_LED_PORT P0

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER = Byte&(0x80>>i);
	  SCK = 1;
	  SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}

void main()
{
	 SCK = 0;
	 RCK = 0;
   while(1)
	 {
		 MatrixLED_ShowColumn(0,0x3C);
		 MatrixLED_ShowColumn(1,0x42);
		 MatrixLED_ShowColumn(2,0xA9);
		 MatrixLED_ShowColumn(3,0x85);
		 MatrixLED_ShowColumn(4,0x85);
		 MatrixLED_ShowColumn(5,0xA9);
		 MatrixLED_ShowColumn(6,0x42);
		 MatrixLED_ShowColumn(7,0x3C);
	 }
}