


// PIC16F73 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = RC        // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bit (Code protection off)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include<xc.h>


#define outputPort PORTC            //Port To Display the Number in BCD Format
#define portToConfig TRISC          //Data Direction Setting of the Port

//Function To Initialize The Require Ports
void init_port(void);

//Customized Function To Break and Send Number in BCD Format
void send_number(unsigned char);

//Function To Provide A Delay
void custom_delay(unsigned int);
