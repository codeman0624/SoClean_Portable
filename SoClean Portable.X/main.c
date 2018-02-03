/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.55
        Device            :  PIC12F1501
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "Variables.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    
    GREEN_LED_SetLow();
    RED_LED_SetLow();
    OZAP_ON_SetLow();
    
    //give a little startup time
    Counter = 10;
    while(Counter--)
    {
        __delay_ms(50);
    }
 
    
    //If the battery is measured as less than 9V, then set the Red LED
    //  high, and then just sleep
    if(ADC_GetConversion(ADC_Input) < LOW_BATTERY_CODE)
    {
        RED_LED_SetHigh();
        SLEEP();
    }
    //If the battery is fine, then start looking at the button to start a cycle
    else
    {
        while(1)
        {   
            RunCycle = 0;
            //Wait here while the pushbutton value is still high (button not pushed)
            while(PUSHBUTTON_GetValue())
            {
                //If the counter has run out, then just sleep
                if(StartupCounter == 0)
                {
                    SLEEP();
                }
            }
            __delay_ms(50);  //debounce
            //if button is still pressed after 50ms, then break the loop
            if(!PUSHBUTTON_GetValue())  
            {
                break;
            }
        }
        INTCONbits.TMR0IE = 0;  //Turn off timer 0 interrupt, since that was just for the
                                //  green LED toggling at startup
        
        //Tell the timer that the cycle wants to be running now
        RunCycle = 1;
        
        //Run the cycle for the given cycle time
        while(CycleTime > 0)
        {
            //Set the green LED high while the cycle is on
            GREEN_LED_SetHigh();
            //turn on the ozone and pump
            OZAP_ON_SetHigh();
        }
        
        //Turn off the green LED and ozone and pump after the cycle is done
        GREEN_LED_SetLow();
        OZAP_ON_SetLow();
        
        //Check the battery again, if it is low now then 
        // turn on the red LED
        if(ADC_GetConversion(ADC_Input) < LOW_BATTERY_CODE)
        {
            RED_LED_SetHigh();
        }

        //Everything is done now, so just go to sleep
        SLEEP();
        
        
    }
    
    
    
    
}
/**
 End of File
*/