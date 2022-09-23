

#include "PORT.h"


static const PORT_CFG * Port_PortChannels 		= 	NULL_PTR;

static  volatile unsigned long  * PORT_DIR		=		NULL_PTR;

static  volatile unsigned long  * PORT_DATA		=		NULL_PTR;

static  volatile unsigned long  * PORT_AFSEL	=		NULL_PTR;

static  volatile unsigned long  * PORT_PUR		=		NULL_PTR;

static  volatile unsigned long  * PORT_PDR		=		NULL_PTR;

static  volatile unsigned long  * PORT_DEN		=		NULL_PTR;

static  volatile unsigned long  * PORT_LOCK		=		NULL_PTR;

static  volatile unsigned long  * PORT_CR			=		NULL_PTR;

static  volatile unsigned long  * PORT_AMSEL	=		NULL_PTR; 

static  volatile unsigned long  * PORT_PCTL		=		NULL_PTR;


void Initialize_Port(const Port_ConfigType* configptr)
{
	volatile unsigned long delay=0;
	
  SYSCTL_REGCGC2_REG|=0x3F;
	
  delay=SYSCTL_REGCGC2_REG;
	Port_PortChannels=configptr->channels;
	int Port;
	int pin_number;
	int index=0;
	
	for(index;index<ConfiguredChannels;index++)
	{
		Port	=	Port_PortChannels[index].PortNumber;
		pin_number		=	Port_PortChannels[index].PinNumber;
		if(Port_PortChannels[index].PortNumber==PORT_def_PORTC)
		{
			continue; /* preventing any bad miss with JTAG*/
		}
		
		switch(Port_PortChannels[index].PortNumber)
		{
			case PORT_def_PORTA:
				PORT_DIR   	=&		GPIO_PORTA_DIR_REG		;
				PORT_DATA  	=&		GPIO_PORTA_DATA_REG		;
				PORT_AFSEL	=&		GPIO_PORTA_AFSEL_REG	;
				PORT_PUR		=& 		GPIO_PORTA_PUR_REG		;
				PORT_PDR		=&		GPIO_PORTA_PDR_REG		;
				PORT_DEN		=&		GPIO_PORTA_DEN_REG		;
				PORT_LOCK		=&		GPIO_PORTA_LOCK_REG		;
				PORT_CR			=&		GPIO_PORTA_CR_REG			;
				PORT_AMSEL	=&		GPIO_PORTA_AMSEL_REG	;
				PORT_PCTL		=&		GPIO_PORTA_PCTL_REG		;
				break;
			
			case PORT_def_PORTB:
				PORT_DIR   	=&		GPIO_PORTB_DIR_REG		;
				PORT_DATA  	=&		GPIO_PORTB_DATA_REG		;
				PORT_AFSEL	=&		GPIO_PORTB_AFSEL_REG	;
				PORT_PUR		=& 		GPIO_PORTB_PUR_REG		;
				PORT_PDR		=&		GPIO_PORTB_PDR_REG		;
				PORT_DEN		=&		GPIO_PORTB_DEN_REG		;
				PORT_LOCK		=&		GPIO_PORTB_LOCK_REG		;
				PORT_CR			=&		GPIO_PORTB_CR_REG			;
				PORT_AMSEL	=&		GPIO_PORTB_AMSEL_REG	;
				PORT_PCTL		=&		GPIO_PORTB_PCTL_REG		;		
				break;
			case PORT_def_PORTC:
				PORT_DIR   	=&		GPIO_PORTC_DIR_REG		;
				PORT_DATA  	=&		GPIO_PORTC_DATA_REG		;
				PORT_AFSEL	=&		GPIO_PORTC_AFSEL_REG	;
				PORT_PUR		=& 		GPIO_PORTC_PUR_REG		;
				PORT_PDR		=&		GPIO_PORTC_PDR_REG		;
				PORT_DEN		=&		GPIO_PORTC_DEN_REG		;
				PORT_LOCK		=&		GPIO_PORTC_LOCK_REG		;
				PORT_CR			=&		GPIO_PORTC_CR_REG			;
				PORT_AMSEL	=&		GPIO_PORTC_AMSEL_REG	;
				PORT_PCTL		=&		GPIO_PORTC_PCTL_REG		;		
				break;
			
			case PORT_def_PORTD:
				PORT_DIR   	=&		GPIO_PORTD_DIR_REG		;
				PORT_DATA  	=&		GPIO_PORTD_DATA_REG		;
				PORT_AFSEL	=&		GPIO_PORTD_AFSEL_REG	;
				PORT_PUR		=& 		GPIO_PORTD_PUR_REG		;
				PORT_PDR		=&		GPIO_PORTD_PDR_REG		;
				PORT_DEN		=&		GPIO_PORTD_DEN_REG		;
				PORT_LOCK		=&		GPIO_PORTD_LOCK_REG		;
				PORT_CR			=&		GPIO_PORTD_CR_REG			;
				PORT_AMSEL	=&		GPIO_PORTD_AMSEL_REG	;
				PORT_PCTL		=&		GPIO_PORTD_PCTL_REG		;		
				break;
			case PORT_def_PORTE:
				PORT_DIR   	=&		GPIO_PORTE_DIR_REG		;
				PORT_DATA  	=&		GPIO_PORTE_DATA_REG		;
				PORT_AFSEL	=&		GPIO_PORTE_AFSEL_REG	;
				PORT_PUR		=&	 	GPIO_PORTE_PUR_REG		;
				PORT_PDR		=&		GPIO_PORTE_PDR_REG		;
				PORT_DEN		=&		GPIO_PORTE_DEN_REG		;
				PORT_LOCK		=&		GPIO_PORTE_LOCK_REG		;
				PORT_CR			=&		GPIO_PORTE_CR_REG			;
				PORT_AMSEL	=&		GPIO_PORTE_AMSEL_REG	;
				PORT_PCTL		=&		GPIO_PORTE_PCTL_REG		;		
				break;
			case PORT_def_PORTF:
				PORT_DIR   	=&		GPIO_PORTF_DIR_REG		;
				PORT_DATA  	=&		GPIO_PORTF_DATA_REG		;
				PORT_AFSEL	=&		GPIO_PORTF_AFSEL_REG	;
				PORT_PUR		=& 		GPIO_PORTF_PUR_REG		;
				PORT_PDR		=&		GPIO_PORTF_PDR_REG		;
				PORT_DEN		=&		GPIO_PORTF_DEN_REG		;
				PORT_LOCK		=&		GPIO_PORTF_LOCK_REG		;
				PORT_CR			=&		GPIO_PORTF_CR_REG			;
				PORT_AMSEL	=&		GPIO_PORTF_AMSEL_REG	;
				PORT_PCTL		=&		GPIO_PORTF_PCTL_REG		;		
				break;
		} //end of switch of port number
		
		if((Port_PortChannels[index].PinNumber==PORT_def_Pin7 && Port_PortChannels[index].PortNumber==PORT_def_PORTD)||(Port_PortChannels[index].PinNumber==PORT_def_Pin0 && Port_PortChannels[index].PortNumber==PORT_def_PORTF))
		{
		PORT_LOCK=0x4C4F434B;
		SET_BIT				(*(volatile uint32 *)((volatile uint8 *)PORT_CR),Port_PortChannels[index].PinNumber)		;
		}
		
		switch(Port_PortChannels[index].dir)
		{
			case INPUT	:
				CLEAR_BIT	(*(volatile uint32 *)((volatile uint8 *)PORT_DIR),Port_PortChannels[index].PinNumber)	;
			break;
			case OUTPUT	:
				SET_BIT		(*(volatile uint32 *)((volatile uint8 *)PORT_DIR),Port_PortChannels[index].PinNumber)	;
		}//end of switch of direction
		
		switch(Port_PortChannels[index].value)
		{
			case LOW	:
				CLEAR_BIT	(*(volatile uint32 *)((volatile uint8 *)PORT_DATA),Port_PortChannels[index].PinNumber)	;
			break;
			case HIGH	:
				SET_BIT		(*(volatile uint32 *)((volatile uint8 *)PORT_DATA),Port_PortChannels[index].PinNumber)	;
		}// end of switch of initial values
		
		switch(Port_PortChannels[index].resistance)
		{
			case PULL_UP	:
				SET_BIT		(*(volatile uint32 *)((volatile uint8 *)PORT_PUR),Port_PortChannels[index].PinNumber)	;
				break;
			case PULL_DOWN:
				SET_BIT		(*(volatile uint32 *)((volatile uint8 *)PORT_PDR),Port_PortChannels[index].PinNumber)	;
				break;
			case OFF			:
				CLEAR_BIT	(*(volatile uint32 *)((volatile uint8 *)PORT_PDR),Port_PortChannels[index].PinNumber)	;
				CLEAR_BIT	(*(volatile uint32 *)((volatile uint8 *)PORT_PUR),Port_PortChannels[index].PinNumber)	;
			
	}//end of switch of internal resistance options
		

	if(Port_PortChannels[index].mode==Port_def_Mode_ADC)
	{
		SET_BIT				(*(volatile uint32 *)((volatile uint8 *)PORT_AMSEL),Port_PortChannels[index].PinNumber);
		CLEAR_BIT			(*(volatile uint32 *)((volatile uint8 *)PORT_DEN),Port_PortChannels[index].PinNumber)	;
	}
	if(Port_PortChannels[index].mode!=Port_def_Mode_ADC)
	{
		SET_BIT				(*(volatile uint32 *)((volatile uint8 *)PORT_DEN),Port_PortChannels[index].PinNumber)	;
		CLEAR_BIT			(*(volatile uint32 *)((volatile uint8 *)PORT_AMSEL),Port_PortChannels[index].PinNumber);
	}
	
	
	switch (Port_PortChannels[index].mode)
	{
		case Port_def_Mode_ADC	:
			CLEAR_BIT		(*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
			break;
		case Port_def_Mode_DIO	:
			CLEAR_BIT		(*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
			break;
		case Port_def_Mode_UART	:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
			*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_UART<<pin_number*4;
			break;
		case Port_def_Mode_SSI	:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_SSI<<pin_number*4;
			break;
		case Port_def_Mode_I2C 	:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_I2C<<pin_number*4;
			break;			
		case Port_def_Mode_M0PWM:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_M0PWM<<pin_number*4;
			break;				
		case Port_def_Mode_M1PWM:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_M1PWM<<pin_number*4;
			break;						
		case Port_def_Mode_IDX:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_IDX<<pin_number*4;
			break;
		case Port_def_Mode_TIMER:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_TIMER<<pin_number*4;
			break;
		case Port_def_Mode_USB:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_USB<<pin_number*4;
			break;
		case Port_def_Mode_CAN:
			SET_BIT		  (*(volatile uint32 *)((volatile uint8 *)PORT_AFSEL),Port_PortChannels[index].PinNumber);
				if(Port==PORT_def_PORTF && (pin_number==0 || pin_number==3))
				{
					*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_I2C<<pin_number*4;
				}
				else
				{
					*(volatile uint32 *)(volatile uint8 *)PORT_PCTL|=(uint32)Port_def_Mode_USB<<pin_number*4;
				}
				
			break;
			
	}
	
	
	
}
	}
	