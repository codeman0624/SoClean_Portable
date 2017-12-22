
/*
 In this C file, include all the variables that want to be available
 through all other files.
 In the globals.h header file, include the variable with the extern
 qualifier, then include that header file in any other file that needs
 access to these variables
*/


unsigned char current_y_addr;
unsigned char current_x_addr;

unsigned char current_hours_count = 0;
int current_time_minutes = 0;           //stores the current time of day, in minutes
int start_time_minutes_global = 600;               //stores the time to start the cycle, in minutes
int filter_minutes_count = 0;           //stores the number of minutes the cycles have run for
unsigned char runtime_minutes_global = 7;     //stores the cycle run time

unsigned char current_seconds = 0;      //keeps track of the current seconds
unsigned char current_minutes = 0;     //keeps track of the minutes to display
unsigned char current_ten_minutes = 0;
unsigned char current_hours = 2;        //keeps track of the hours to display
unsigned char current_ten_hours = 1;

unsigned char start_minutes = 0;
unsigned char start_ten_minutes = 0;
unsigned char start_hours = 0;
unsigned char start_ten_hours = 1;



bit update = 0;                  //determines whether to call the update
                                 // clock routine in the ISR
bit am_pm = 0;                   //Stores whether it's AM or PM,
                                 //  AM = 0, PM = 1
bit start_am_pm = 0;             //Stores whether the start time is
                                 //  in AM or PM.  AM = 0, PM = 1;
bit first_time = 0;              //Flag to show that it's the first time into
                                 // the ISR, to be able to update the clock
unsigned char hours_24 = 0;



unsigned char LCD_contrast = 0xBA;  //Variables for LCD state
unsigned char LCD_invert = 0;
unsigned char LCD_bias_system = 4;
unsigned char LCD_tempco = 1;

bit start_cycle = 0;
bit cycle_finished = 0;

unsigned char run_minutes_counter = 0;
unsigned char leds_time_counter = 120;  //two hours for yellow LEDS to be on
unsigned char backlight_seconds_counter = 0;
unsigned char backlight_seconds_count = 5;
