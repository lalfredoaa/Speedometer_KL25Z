
#include "MKL25Z4.h"
#include "common.h"
#include "lcd.h"

unsigned short time1 = 0;
unsigned short time2 = 0;
unsigned short cycles = 0;
int revs = 0;

/*
 * Initializes the needed registers to use TMP0 and its channel 1.
 * It will be used through pin PTC2.
 */
void inputCapture_init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;     //enable clock to Port C    
	PORTC->PCR[2] |= PORT_PCR_MUX(4); 		//set PTC2 pin for TPM0CH1
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;   	//enable clock to TPM0
	//SIM->SOPT2 |= SIM_SOPT2_TPMSRC(3);		//use MCGIRCLK as timer counter clock 
	//MCG->C1 |= MCG_C1_IRCLKEN_MASK;			//enable MCGIRCLK
		
	TPM0->SC = 0;               										//disable timer to configure
	TPM0->MOD = 0xFFFF;         										//max modulo value: for it to keep on counting, comparison won't be done with this register
	TPM0->CONTROLS[1].CnSC |= TPM_CnSC_ELSA_MASK;  						//input capture on rising edge
	
	TPM0->CONTROLS[1].CnSC |= 		TPM_CnSC_CHIE_MASK;					//enable interrupt
	NVIC->ISER |= (1<<17);												//interruption
	
	TPM0->CONTROLS[1].CnSC |= TPM_CnSC_CHF_MASK; 						//clear flag CHF
	TPM0->SC |= TPM_SC_CMOD(1);           								//enable timer
}	

/*
 * To handle TPM0 interrupt
 */
void FTM0_IRQHandler(void){
	time1 = time2;
	time2 = TPM0->CONTROLS[1].CnV;										//value is stored here
	cycles = time2-time1;
	revs = (1966080/cycles);
	TPM0->CONTROLS[1].CnSC |= TPM_CnSC_CHF_MASK; 						//clear flag CHF
	printChar(revs);
}
