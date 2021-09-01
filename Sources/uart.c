
#include "MKL25Z4.h"
#include "common.h"




/* 
 * Initializes UART0 to communicate uC and computer via serial connection
 */
void UART0_init(void){
	NVIC->ICPR = 0; 						//Clear pending interrupts
											//We will use more interruptions, but this is the first setup function that is called
	
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK; 					//enable clock to UART0
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); 					//Select FLL as the clock for UART0
	
	UART0->C2 = 0; 											//Disable UART0 to configure
	
	//to generate 115200 baud
	UART0->BDH = 0;
	UART0->BDL = 13; 										//Set SBR to 13
	UART0->C4 = 13;  										//Set OSR to 13
	
	UART0->C1 = 0; 											//8 bit data, no parity, 1 stop bit
	UART0->C2 |= UART0_C2_RE_MASK | UART0_C2_RIE_MASK; 		//Receive and receive interrupt enable
	NVIC->ISER |= (1<<12); 									//interruption
	
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK; 					//Enable clock to PORTA
	PORTA->PCR[1] = PORT_PCR_MUX(2);  						//Configure PTA1 as UART0_Rx pin 
	
	//UART0->C2 |= UART0_C2_TE_MASK;     						//Transmit enable
	//PORTA->PCR[2] = PORT_PCR_MUX(2); 						//Configure PTA2 as UART0_Tx pin 
}

/* 
 * To handle UART0 interrupt.
 */
void UART0_IRQHandler(void){
	char c;
	c = UART0->D;
	TPM1->SC = 0;
	switch(c){	
	case('1'):
			TPM1->CONTROLS[1].CnV = 100;
			break;
	case('2'):
			TPM1->CONTROLS[1].CnV = 200;
			break;
	case('3'):
			TPM1->CONTROLS[1].CnV = 300;
			break;
	case('4'):
			TPM1->CONTROLS[1].CnV = 400;	
			break;
	case('5'):
			TPM1->CONTROLS[1].CnV = 500;	
			break;
	case('6'):
			TPM1->CONTROLS[1].CnV = 600;
			break;
	case('7'):
			TPM1->CONTROLS[1].CnV = 700;
			break;
	case('8'):
			TPM1->CONTROLS[1].CnV = 800;
			break;
	case('9'):
			TPM1->CONTROLS[1].CnV = 900;
			break;
	/*case('0'):
			TPM1->CONTROLS[1].CnV = 1000;
			break;*/
	}
	TPM1->SC |= TPM_SC_CMOD(1); 
}
