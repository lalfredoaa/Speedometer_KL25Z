
#include "MKL25Z4.h"
#include "lcd.h"
#include "common.h"

#define RS 1    /* BIT0 mask */
#define RW 2    /* BIT1 mask */
#define EN 4    /* BIT2 mask */



void LCD_init(void)
{
	SIM->SCGC5 |= 0x1000;       /* enable clock to Port D */
	PORTD->PCR[0] = 0x100;      /* make PTD0 pin as GPIO */
	PORTD->PCR[1] = 0x100;      /* make PTD1 pin as GPIO */
	PORTD->PCR[2] = 0x100;      /* make PTD2 pin as GPIO */
	PORTD->PCR[4] = 0x100;      /* make PTD4 pin as GPIO */
	PORTD->PCR[5] = 0x100;      /* make PTD5 pin as GPIO */
	PORTD->PCR[6] = 0x100;      /* make PTD6 pin as GPIO */
	PORTD->PCR[7] = 0x100;      /* make PTD7 pin as GPIO */
	
	GPIOD->PDDR |= 0xF7;        /* make PTD7-4, 2, 1, 0 as output pins */
	delayMs(30);                /* initialization sequence */
	LCD_nibble_write(0x30, 0);
	delayMs(10);
	LCD_nibble_write(0x30, 0);
	delayMs(1);
	LCD_nibble_write(0x30, 0);
	delayMs(1);
	LCD_nibble_write(0x20, 0);  /* use 4-bit data mode */
	delayMs(1);
	LCD_command(0x28);          /* set 4-bit data, 2-line, 5x7 font */
	LCD_command(0x06);          /* move cursor right */
	LCD_command(0x01);          /* clear screen, move cursor to home */
	LCD_command(0x0F);          /* turn on display, cursor blinking */
	LCD_command(0x0c);
}




void LCD_nibble_write(unsigned char data, unsigned char control)
{
	data &= 0xF0;       /* clear lower nibble for control */
	control &= 0x0F;    /* clear upper nibble for data */
	GPIOD->PDOR = data | control;       /* RS = 0, R/W = 0 */
	GPIOD->PDOR = data | control | EN;  /* pulse E */
	delayMs(0);
	GPIOD->PDOR = data;
	GPIOD->PDOR = 0;
}


void LCD_command(unsigned char command)
{
	LCD_nibble_write(command & 0xF0, 0);   /* upper nibble first */
	LCD_nibble_write(command << 4, 0);     /* then lower nibble */
	if (command < 4)
		delayMs(4);         /* commands 1 and 2 need up to 1.64ms */
	else
		delayMs(1);         /* all others 40 us */
}
  
void LCD_data(unsigned char data)
{
	LCD_nibble_write(data & 0xF0, RS);    /* upper nibble first */
	LCD_nibble_write(data << 4, RS);      /* then lower nibble  */
	delayMs(1);
}


/* Delay n milliseconds
* The CPU core clock is set to MCGFLLCLK at 41.94 MHz in SystemInit().
*/
void delayMs(int n) {
	int i;
	int j;
	for(i = 0 ; i < n; i++){
		for(j = 0 ; j < 7000; j++) { }
	}
}



//print a number
void printChar(int k){
	int digits = 0;
	int copy = k;
	
	while(copy!=0){
		copy/= 10;
		digits++;
	}
	
	int digitsArray[digits];
	int w;
	for(w=0;w<digits;w++){
		digitsArray[w] = k%10;
		k = k/10;
	}
	
	LCD_command(0x80); //first line
	
	int z;
	for(z=digits-1;z>-1;z--){
		switch(digitsArray[z]){
		case 1:
			LCD_data('1');
			break;
		case 2:
			LCD_data('2');
			break;
		case 3:
			LCD_data('3');
			break;
		case 4:
			LCD_data('4');
			break;
		case 5:
			LCD_data('5');
			break;
		case 6:
			LCD_data('6');
			break;
		case 7:
			LCD_data('7');
			break;
		case 8:
			LCD_data('8');
			break;
		case 9:
			LCD_data('9');
			break;
		case 0:
			LCD_data('0');
			break;
		}
	}
	LCD_data('r');
	LCD_data('p');
	LCD_data('m');
	LCD_data(' ');
	LCD_data(' ');
	LCD_data(' ');
}

