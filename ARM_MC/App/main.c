#include "main.h"

boolean ON=FALSE;

void ISR(void)
{
	sec++;
}

const Port_ConfigType config[PORT_CONFIGURED_CHANNELS] ={
	PORT_def_PORTF,	PORT_def_Pin0,INPUT		,	Port_def_Mode_DIO		,	OFF	,	_4MA,LOW	,
	PORT_def_PORTF,	PORT_def_Pin1,OUTPUT	,	Port_def_Mode_DIO		,		OFF,	_4MA,LOW	,
	PORT_def_PORTF,	PORT_def_Pin2,OUTPUT	,	Port_def_Mode_DIO		,		OFF,	_4MA,LOW	,
	PORT_def_PORTF,	PORT_def_Pin3,OUTPUT	,	Port_def_Mode_CAN		,	OFF,	_4MA,HIGH	,
	PORT_def_PORTF,	PORT_def_Pin4,INPUT		,	Port_def_Mode_ADC		,	OFF	,	_4MA,LOW	,
	PORT_def_PORTB,	PORT_def_Pin6,OUTPUT	, Port_def_Mode_TIMER	,	OFF,	_4MA,LOW	,

};
int main(void)
{
	
	//initialize the port
	Initialize_Port(&config);
	// initialize the timer
	Initialize_GP_timer(&config_GPT);
	// Enable the notifications
	Allow_notification(GPT_TIMER_A_0_16_32_BIT);
	// GPT timer setting and start
	Start_timer(GPT_TIMER_A_0_16_32_BIT,62500);
	// initialize the Nested vector interrupt controller
	NVIC_init();
	
	while(1)
	{
			if(ON)
				{
					// if seconds are greater than active time .. turn OFF led and reset seconds
					if(sec>=Active)
					{
						sec=0;
						ON=FALSE;
						Dio_WriteChannel(DIO_def_PortF_Pin1_Index,LOGIC_LOW);
					}
				}
				// if seconds are greater than passive time .. turn ON led and reset seconds
				else if(sec>=Passive)
					{	
						sec=0;
						ON=TRUE;
						Dio_WriteChannel(DIO_def_PortF_Pin1_Index,LOGIC_HIGH);
					}
				}
				
}