/* 
 * File:   globals.h
 * Author: Cody
 *
 * Created on December 29, 2012, 9:46 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H


#define DEBOUNCE_TIME           50
#define CLOCK_24H_SHIFT         5
#define START_TIME_24H_SHIFT    8

extern unsigned char current_y_addr;
extern unsigned char current_x_addr;
extern unsigned char current_hours_count;
extern int current_time_minutes;
extern int start_time_minutes_global;
extern int filter_minutes_count;
extern unsigned char runtime_minutes_global;

extern unsigned char current_seconds;
extern unsigned char current_minutes;
extern unsigned char current_ten_minutes;
extern unsigned char current_hours;
extern unsigned char current_ten_hours;

extern unsigned char start_minutes;
extern unsigned char start_ten_minutes;
extern unsigned char start_hours;
extern unsigned char start_ten_hours;


extern bit am_pm;
extern bit update;
extern bit first_time;
extern unsigned char hours_24;
extern bit start_am_pm;

extern bit start_cycle;
extern bit cycle_finished;

extern unsigned char run_minutes_counter;
extern unsigned char leds_time_counter;
extern unsigned char backlight_seconds_counter;
extern unsigned char backlight_seconds_count;


extern unsigned char LCD_contrast;
extern unsigned char LCD_invert;
extern unsigned char LCD_bias_system;
extern unsigned char LCD_tempco;


#endif	/* GLOBALS_H */

