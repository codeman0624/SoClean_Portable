#include <pic12f1501.h>
#include <stdlib.h>
#include <string.h>
#include "Initializations.h"
#include "Delays.h"



//--------------------------------------------------------------------------
//		Initializations
//--------------------------------------------------------------------------


/* Initializes the oscillator to the proper oscillator selection and system clock */
void oscillator_init(void)
{
	OSCCONbits.IRCF = 0b0111;       //500kHz internal oscillator select
        OSCCONbits.SCS = 0b00;          //Primary clock determined by FOSC

        
        WDTCONbits.SWDTEN = 0;          //WDT is turned off

	return;
}




/* Set up the desired interrupts and priority levels */
void interrupt_init(void)
{
    INTCONbits.PEIE = 1;     //Enables all active peripheral interrupts
    INTCONbits.TMR0IE = 0;  //Disable Timer0 interrupt
    INTCONbits.INTE = 0;    //Disables the INT external interrupt
    INTCONbits.IOCIE = 0;   //Disables the interrups on change

    PIE1bits.TMR1GIE = 0;   //Disable the Timer1 Gate Acquisition interrupt
    PIE1bits.TMR2IE = 0;    //Disable the Timer2 to PR2 match interrupt
    PIE1bits.TMR1IE = 1;    //Enables the Timer1 overflow interrupt
    PIE1bits.ADIE = 1;      //Enable the ADC interrupt

    PIE2bits.C1IE = 0;      //Disables the comparator C1 interrupt
    PIE2bits.NCO1IE = 0;    //Disables the Numerically Controlled Oscillator interrupt

    PIE3bits.CLC2IE = 0;    //Disables the Configurable Logic Block 2 interrupt
    PIE3bits.CLC1IE = 0;    //Disables the Configurable Logic Block 1 interrupt

    PIR1 = 0;               //Clear all interrupt flags in PIR1
    PIR2 = 0;               //Clear all interrupt flags in PIR2
    PIR3 = 0;               //Clear all interrupt flags in PIR3

    INTCONbits.GIE = 1;     //Enables all active interrupts

    return;
}


/* Timer 0 generates an interrupt every 5 seconds */
void timer0_init(void)
{


        
	return;
}

/* Timer 1 generates an interrupt every 1 second */
void timer1_init(void)
{
    T1GCONbits.TMR1GE = 0;          //When timer is on, timer 1 counts regardless of
                                    //  gate function.  (Don't get my counter)


    T1CONbits.TMR1CS = 0b00;        //clock source is the instruction clock (Fosc/4)
                                    //  125kHz = 8uS

    T1CONbits.T1CKPS = 0b01;        //Set the prescaler to 2

    /*  Prescaler = 2, counter incrementing every 2*8uS = 16uS
        16-bit counter, will overflow when count = 65536
        So will overflow every ~1.05 seconds
        Which is perfect for my 1 second timer
     No pre-setting of the counter registers is necessary, just
       let it free-run    */

    T1CONbits.TMR1ON = 1;   //Turn the timer on now (might put this somewhere else later)
    
    return;
}


void timer1_reset(void)
{
	//TMR1H = 0x0B;				//Need this count to generate a 0.25 second interrupt
	//TMR1L = 0xDB;
	return;
}


void timer2_init(void)
{

    return;
}


/* Sets the I/O port directions for each pin */
void port_init(void)
{
        ANSELA = 0x00;          //Set all pins to be digital I/O functions
        ANSELAbits.ANSA2 = 1;   //set RA2 to be an analog input

        TRISA = 0x00;           //Set everything to output at first
        TRISAbits.TRISA2 = 1;   //RA2 will be the A/D input

        PORTA = 0;              //Make sure to set the output to 0

        WPUA = 0x00;            //Disable weak pull-ups

        ADCON0 = 0x00;			//Turn off the A/D converter so it doesnt use my digital I/O pins!
	ADCON1 = 0x00;                  
        ADCON2 = 0x00;

        CM1CON0 = 0x00;






	return;
}


/* Sets up the A/D converter */
void AD_init(void)
{
    /* I thought the fixed voltage reference would be used as the reference
       for the A/D, but I was wrong.  So the positive reference of the A/D
       is just the +5V rail
     */
    FVRCONbits.FVREN = 0;       //Disable the internal fixed voltage reference
    FVRCONbits.ADFVR = 0b10;    //Set the ADC reference to 2.048V

    ADCON0bits.CHS = 0b00010;   //Select AN2 as the MUX channel
    ADCON1bits.ADFM = 1;        //Right justified result (significant bits of
                                //  ADRESH are set to 0)
    ADCON1bits.ADCS = 0b000;    //Conversion clock = Fosc/2
                                //  Tad must be greater than 1us, and less than 9us
                                //  Fosc = 500kHz, so Fosc/2 => 4us
    ADCON1bits.ADPREF = 0;      //A/D positive voltage references is connected to VDD

    ADCON2bits.TRIGSEL = 0b0100;    //auto-conversion on Timer1 overflow (every 1 second)

    ADCON0bits.ADON = 1;        //Turn on the ADC

    return;
}



