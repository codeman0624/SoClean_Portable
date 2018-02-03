#include <p18f25k20.h>
#include "Delays.h"
#include <stdlib.h>

//test edit

//--------------------------------------------------------------------------
//		Timing delays
//--------------------------------------------------------------------------


/**********************************************************
	  All of these delays are based on an 500kHz clock
**********************************************************/





/* 
	INPUT: Number from 0 to 255
	OUTPUT: Generates a delay equal to 0.1s * input
*/
void tenth_seconds(char num)
{
        milliseconds(num*100);

	return;
}



/*
	INPUT: Number from 0 to 255
	OUTPUT: Generates a delay equal to 0.001seconds * num
*/
void milliseconds(int num)
{
	int i;

	while(num--)
	{
		for(i = 0; i<5; i++);
	}
	

	return;
}




void delay_100us(void)
{

    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");

    return;
}

/*
void delay_50uS(void)
{
	char i;
	for(i=0; i<4; i++)
	{
		_asm
			nop
			nop
			nop
			nop
		_endasm

	}

	return;
}
*/
