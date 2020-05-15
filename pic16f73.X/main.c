


/* Week-1 Experiment-1: I/O programming using 8 bit PIC MCU
 *
 * @author     Abhishek Shukla
 * @date       2020/05/12
 *
 * \subsection Aim
 * To get started with the Embedded C Programming using PIC 8 bit MCU
 * writing a simple program to Display the count in decimal format in seven Segment Display.
 *
 * \subsection Connections
 * Seven Segment display 1    :   PORTC(0-3)		
 * Seven Segment display 2    :   PORTC(4-8)			
	
 *
 * \MCU Used : PIC16F73
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Simple Program To Count /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------- HEADER FILES -----------------------------------------------------

#include "utility.h"

//---------------------------------- MAIN -------------------------------------------------------------

void main(void){
    init_port();            //initializing the required port
    unsigned int z = 0;
    do{
        custom_delay(5);    //providing a small delay
        send_number(z);     // sending number to the port
        z++;    
    }while(z  < 100);
    while(1);
}
//---------------------------------- FUNCTIONS ----------------------------------------------------------

void init_port(){
    portToConfig = 0;              // Setting Port C as Output 
}
void send_number(unsigned char number){
    unsigned char unit,tenth;
    // Split The Number in require BCD format
    unit = number % 10;
    tenth = number /10;
    outputPort = (0xF0 & (tenth << 4)) | (0x0F & unit);
}
void custom_delay(unsigned int range){
    unsigned int count;
    for(count = 0; count < 100*range ; count++);
}

