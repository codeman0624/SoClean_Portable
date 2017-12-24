/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef VARIABLES_H
#define	VARIABLES_H

#include <xc.h> // include processor files - each processor file is guarded.  



/**************************************************
 * StartupCounter determines how many seconds the
 *  green LED will blink when the unit is first 
 *  turned on
 * Counter is on a 0.25 second time scale, so 
 *  the calculation is:
 * StartupCounter = Desired time in seconds * 4
 * So for 30 seconds:  StartupCounter = 30 * 4 = 120
 **************************************************/
volatile uint8_t StartupCounter = 120;

/***************************************************
 * CycleTime determines how long the cycle runs.  The
 *  time base is 1 second, so simply set CycleTime
 *  equal to the number of seconds you want the
 *  cycle to run
 ***************************************************/
volatile int CycleTime = 390;

/*******************************************************
 * LOW_BATTERY_CODE determines what is the low
 *  battery threshold
 * Calculation is:
 * LOW_BATTERY_CODE = Voltage * 53.86
 * For 9V, LOW_BATTERY_CODE = 9 * 53.86 = 484.74 = 485
 *******************************************************/
#define LOW_BATTERY_CODE        485




uint8_t RunCycle = 0;
uint8_t Counter = 0;



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

