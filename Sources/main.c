
#include "lcd.h"
#include "uart.h"
#include "input.h"
#include "pwm.h"
#include "common.h"

int main(void)
{
	common_init();
	LCD_init();
	UART0_init();
	PWM_init();
	inputCapture_init();
	
	for(;;) {	   
	
	}
	
	return 0;
}
