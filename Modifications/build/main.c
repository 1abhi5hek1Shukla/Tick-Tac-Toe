/* Week-1 Experiment-1: I/O programming using 16 bit PIC MCU
 *
 * @author     Abhishek Shukla
 * @date       2020/05/12
 *
 * \subsection Aim
 * To get started with the Embedded C Programming using PIC 16 bit MCU
 * writing a simple to control the motor speed using push button such that:
 *          1. When button 1 is pushed on motor runs on full speed.
 *
 * \subsection Connections
 * Button   :   RA0			
 * Buzzer   :   RB0
 *
 * \MCU Used : PIC24FJ64GA004
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Simple Program To Turn on the Buzzer/LED .///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

//---------------------------------- HEADER FILES -----------------------------------------------------
#include"utility.h"

//---------------------------------- MAIN -------------------------------------------------------------
void main(void){
    init_ports();
    unsigned char count = 0;
    while(1){
        if(button != 0){
            buzzz();
        }
    }
}
//---------------------------------- FUNCTIONS ----------------------------------------------------------
void init_ports(void){
    
    AD1PCFGbits.PCFG0 = 1;      //Diabling Analog features on PIN A0    

    TRISAbits.TRISA0 = 1;       //setting pin A0 as Input
    TRISBbits.TRISB0 = 0;       //Setting Pin B0 as output              
}

void custom_delay(unsigned int range){
    unsigned int count;
    for(count = 0; count < 1000*range ; count++);
}

void buzzz(){
   buzzer = 1;
   custom_delay(100);
   buzzer = 0;
}
