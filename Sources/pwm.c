
#include "MKL25Z4.h"
#include "common.h"



void PWM_init(void){
	
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;     //enable clock to Port B    
	PORTB->PCR[1] |= PORT_PCR_MUX(3); 		//set PTB1 pin for TPM1CH1
	SIM->SCGC6 |= SIM_SCGC6_TPM1_MASK;   	//enable clock to TPM1
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(3);		//use MCGIRCLK as timer counter clock
	MCG->SC = 0;
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;			//enable MCGIRCLK
	
	TPM1->SC = 0;               										//disable timer to configure
	TPM1->MOD = 1000;         										//max modulo value: for it to keep on counting, comparison won't be done with this register
	TPM1->CONTROLS[1].CnSC |= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK;  	//pwm mode
	
	
	TPM1->CONTROLS[1].CnV = 500;										//pulse width 
	TPM1->SC |= TPM_SC_CMOD(1);           								//enable timer
}
