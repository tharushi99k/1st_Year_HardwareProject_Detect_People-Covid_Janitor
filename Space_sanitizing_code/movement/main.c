#ifndef F_CPU

# define F_CPU 16000000UL // clock speed is 16MHz

#endif



#include<avr/io.h>        // AVR header file

#include<util/delay.h>    // delay header

#include "lcd.h"



//******************LCD PROGRAM STARTS*********************//

#define LCD_DATA PORTB          // port B is selected as LCD data port

#define ctrl PORTD              //  port D is selected as LCD command port

#define en PD7                  // enable signal is connected to port D pin 7

#define rw PD6                  // read/write signal is connected to port D pin 6

#define rs PD5                  // register select signal is connected to port D pin 5



/*void LCD_cmd(unsigned char cmd);

void init_LCD(void);

void LCD_write(unsigned char data);
*/

// led bulb programing start...............//

int main(void)
{
	DDRC = 0xFF;   /* make port as a output port*/
	
	while(1)
	{
		PORTC = 0;              //led off //
		_delay_ms(10);
		PORTC = 0;             //led on //
		_delay_ms(20);
		


		//.........lcd programming start....................



		DDRB=0xFF;              // set LCD data port as output

		DDRD=0xE0;              // set LCD signals (RS, RW, E) as out put

		init_LCD();             // initialize LCD

		_delay_ms(5);         // delay

		

		LCD_cmd(0x0C);          // display on, cursor off

		_delay_ms(5);
		

		LCD_Write_String(" Sanitizing..   ");
		_delay_ms(1000);


		LCD_cmd(0xC0);          // move cursor to the start of 2nd line

		_delay_ms(1000);
		
		LCD_Write_String("  ");    //2nd line display//
		_delay_ms(1000);

		

		

		LCD_cmd(0x01);          // make display ON, cursor ON

		_delay_ms(1000);

		

		return 0;
		
	}
	
	
	

}


