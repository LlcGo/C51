#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms){
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	  xms--;
	}
}
unsigned char LEDNum = 0;

void main(){
	P2 = ~0x01;
  while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LEDNum++;
			if (LEDNum >= 8)
			{
				 LEDNum = 0;
			}
			P2 = ~ (0x01 << LEDNum);
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			
			if (LEDNum == 0)
			{
				 LEDNum = 7;
			}
			LEDNum--;
			P2 = ~ (0x01 << LEDNum);
			
		}
	
	}
}


#if 0

void main(){
	unsigned char LEDNum = 0;
  while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LEDNum++;
			P2 = ~LEDNum;
		}
	
	}
}

void main(){
  while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			P2_0 = ~P2_0;
		}
	
	}
}

void main()
{
	P2_0 = 0;
	while(1)
	{
		if(P3_1==0 && P3_0 == 0)
		{
			P2_0 = 0;
		}
		else
		{
			P2_0 = 1;
		}
	}
}
#endif