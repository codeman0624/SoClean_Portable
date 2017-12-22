/* 
 * File:   SoClean Main.c
 * Author: Cody
 *
 * Created on December 31, 2012, 12:59 PM
 */

#include <pic12f1501.h>
#include <stdio.h>
#include <stdlib.h>
#include "Delays.h"
#include "Initializations.h"





#pragma config CLKOUTEN = 1         //Clockout function is disabled, I/O function on CLKOUT pin
//#pragma config CLKOUTEN = 0         //Clockout function is enabled
#pragma config FOSC = 0b00          //INTOSC oscillator, I/O function on CLKIN pin
#pragma config BOREN = OFF          //No brown out reset
//#pragma config MCLRE = ON           //MCLR is enabled
#pragma config MCLRE = OFF           //MCLR is disabled
#pragma config PWRTE = 1           //Power up timer disabled
#pragma config WDTE = 0b00          //No Watchdog Timer
#pragma config LVP = OFF            //No low voltage programming!!!!
#pragma config WRT = 0b11           //Write protection off








/* Function prototypes */
int main(void);
void interrupt interrupt_handler(void);


/* Global variables for Main */
bit cycle_running = 0;
int cycle_timer = CYCLE_RUN_TIME;
int ADC_result = 0;
unsigned char low_battery_counter = 0;



/*
 * 
 */
int main(void) {

    oscillator_init();
    port_init();

    timer1_init();  //Timer1 gives an interrupt every second

    AD_init();

    //Wait a start up delay time
    milliseconds(500);

    //As soon as the unit is powered on, check the battery level, because
    //  if it is below 9.5V, then the unit should not run
    /*
    ADCON0bits.ADGO = 1;
    while(ADCON0bits.ADGO);
    ADC_result = ADRESL + (ADRESH << 8);
    if(ADC_result < LOW_BATTERY_THRESHOLD)
    {
        //if the result shows the batteries are low, then
        //  turn on the red LED and stay there forever
        RED_LED = 1;
        while(1);
    }
*/

    interrupt_init();
    
    //timer0_init();
   
    


    while(1)
    {
        while(PUSHBUTTON);

        while(!PUSHBUTTON);

        cycle_running = 1;

        while(1)
        {
            if(cycle_timer == 0)
            {
                cycle_timer = CYCLE_RUN_TIME;
                //TOGGLE_PIN = !TOGGLE_PIN;
            }
        }
        

    }  //end while(1)
    




    return;
}








void interrupt interrupt_handler(void)
{

    


    if(PIE1bits.TMR1IE && PIR1bits.TMR1IF)
    {
        //ADCON0bits.ADGO = 1;
        if(cycle_running)
        {
            cycle_timer--;
        }

        PIR1bits.TMR1IF = 0;    //be sure to clear the interrupt flag!!
    } //end if(PIE1bits.TMR1IE && PIR1bits.TMR1IF)

    if(PIE1bits.ADIE && PIR1bits.ADIF)
    {
        ADC_result = ADRESL + (ADRESH << 8);

        //If the A/D input is less than 2.5V, then increment the low battery counter
        //  Otherwise reset the counter
        if(ADC_result < 512)
        {
            low_battery_counter++;
        }
        else
        {
            low_battery_counter = 0;
        }

        PIR1bits.ADIF = 0;      //be sure to clear the interrupt flag!!
    }

        


        


    
    return;


}


