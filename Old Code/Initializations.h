/*
	Header file that contains all the function prototypes for the 
	 initialization functions
*/
#ifndef INCLUSION_GUARD_INITIALIZATIONS_H
#define INCLUSION_GUARD_INITIALIZATIONS_H


#define CYCLE_RUN_TIME  5
#define LOW_BATTERY_THRESHOLD   512

#define PUSHBUTTON      PORTAbits.RA3
#define AD_INPUT        PORTAbits.RA2
#define GREEN_LED       PORTAbits.RA1
#define RED_LED         PORTAbits.RA0
#define OZAP            PORTAbits.RA5



void interrupt_init(void);
void timer0_init(void);
void timer1_init(void);
void timer1_reset(void);
void timer2_init(void);
void AD_init(void);
void port_init(void);
void LCD_init(void);
void custom_characters(void);
void oscillator_init(void);
void SPI_init(void);

#endif
