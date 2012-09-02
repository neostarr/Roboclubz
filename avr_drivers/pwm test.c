/*
 * PWM_TEST.c
 *
 * Created: 01-sept-12 7:30:00 PM
 *  Author: Padmanaban surya
 */ 
  
 /*
 DESCRIPTION :
 
 A PWM code using Timer/Counter 0 of Atmega32
 The output of the PWM is at PORTB.3(that is the 3rd pin of PORTB)
 The duty cycle of the PWM varies with time
 An led connected to the PWM pin will glow with varrying brightness
 
 HARDWARES USED:  ATMEGA32+DEVELOPMENT BOARD
 PROGRAMMER:  AVR USBASP PROGRAMMER
 LED for indication purpose
 
 SOFTWARES USED: AVR STUDIO 4
				 EXTREME BURNER
				 
TIMER USED: Timer/Counter 0
PWM MODE: Non inverting Fast PWM mode
PRESCALAR: 1(NO PRESCALAR)
OUTPUT PIN: PORTB.3(OCR0)
 */ 
 
/*header file*/
#include <avr/io.h>	

/*crystal oscillator frequency*/
#define F_CPU 16000000UL
	
/* used to include delay function*/
#include<util/delay.h>	

/*special function register*/
#include <avr/sfr_defs.h>

/*getting into main function*/
int main(void)	
{   	
	//initializing a varial 'i'                                                                   
	uint8_t i;	
	
	 /*(1<<WGM01)|(1<<WGM00):  selects the fast pwm mode*/
	 /*(1<<COM01): selects the output as non-inverting pwm mode/*
	 /*(1<<CS00): selects the prescalar as 1(clock pulse division factor)*/
	TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);       

	/*configuring the 3 pin in the port B as output which is the pwm pin*/
	DDRB |= (1<<PB3);	
	
	/*infinite loop*/
	while(1)	
    {
		/*the value of 'i' starting from 0 to mamium range of pwm value(255)*/
        for(i=0;i<255;i++)		
		{
			/*OCR0 is the pin where i can get the pwm output- the output value depends on 'i'*/
			OCR0 = i;
			
			/*a loop function to give a delay for next iteration*/
_			_delay_loop_2(10000);	
		}
		
		/*the value of 'i' starting from the maximum value to minimum value*/
		for(i=255;i>0;i--)	
		{
			/* for this loop the pwm value starts decreasing*/
			OCR0 = i;	
			
			/*same as in the previous loop*/
			_delay_loop_2(10000);	
		}
	}
}
