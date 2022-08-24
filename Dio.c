#include "Dio.h"
#include "common_macros.h"
#include "registers.h"

int pin_number,port_number;

/* function to get the port_number and pin_number number from channelId*/
void Channel_to_pin_port(Dio_ChannelType ChannelId, int* port_number ,  int* pin_number)
{
	Dio_def_PORT port;
	*pin_number=ChannelId%8;
	ChannelId=ChannelId/8;
	switch(ChannelId){
		case 0:
		 port=A;
		*port_number=A;
		break;
		case 1:
		 port=B;
		*port_number=B;
		break;
		case 2:
		 port=C;
		*port_number=C;
		break;
		case 3:
		 port=D;
		*port_number=D;
		break;
		case 4:
		 port=E;
		*port_number=E;
		break;
		case 5:
		 port=F;
		*port_number=F;
		break;
	}
}



/*
 * Description :
 * Read and return the value for the required pin_number, it should be Logic LOGIC_HIGH or Logic LOGIC_LOW.
 * If the input port_number number or pin_number number are not correct, The function will return Logic LOGIC_LOW.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
  Channel_to_pin_port( ChannelId, &port_number ,  &pin_number);
	switch(port_number)
	{
		case 0:
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 1:
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 2:
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 3:
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 4:
			if(BIT_IS_SET(GPIO_PORTE_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 5:
			if(BIT_IS_SET(GPIO_PORTF_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}

	}
	return LOGIC_LOW;
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level)
{
	Channel_to_pin_port(ChannelId,&port_number,&pin_number);
	switch(port_number)
	{
		case 0:
			if(level)
			{
				SET_BIT(GPIO_PORTA_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_DATA_REG,pin_number);
			}
			break;
		case 1:
			if(level)
			{
				SET_BIT(GPIO_PORTB_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTB_DATA_REG,pin_number);
			}
			break;
		case 2:
			if(level)
			{
				SET_BIT(GPIO_PORTC_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTC_DATA_REG,pin_number);
			}
			break;	
		case 3:
			if(level)
			{
				SET_BIT(GPIO_PORTD_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTD_DATA_REG,pin_number);
			}
			break;			
		case 4:
			if(level)
			{
				SET_BIT(GPIO_PORTE_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTE_DATA_REG,pin_number);
			}
			break;
		case 5:
			if(level)
			{
				SET_BIT(GPIO_PORTF_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTF_DATA_REG,pin_number);
			}
			break;
	}
	
}


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	uint8 Data=0;
	switch(PortId)
	{
		case 0:
			Data =(uint8)GPIO_PORTA_DATA_REG;
			break;
		case 1:
			Data =(uint8)GPIO_PORTB_DATA_REG;
			break;
		case 2:
			Data =(uint8)GPIO_PORTC_DATA_REG;
			break;
		case 3:
			Data =(uint8)GPIO_PORTD_DATA_REG;
			break;
		case 4:
			Data =(uint8)GPIO_PORTE_DATA_REG;
			break;
		case 5:
			Data =(uint8)GPIO_PORTF_DATA_REG;
			break;		
	}
	return Data;
	
	
}


void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level)
{
		switch(PortId)
	{
		case 0:
			GPIO_PORTA_DATA_REG=level;
			break;
		case 1:
			GPIO_PORTB_DATA_REG=level;
			break;
		case 2:
			GPIO_PORTC_DATA_REG=level;
			break;
		case 3:
			GPIO_PORTD_DATA_REG=level;
			break;
		case 4:
			GPIO_PORTE_DATA_REG=level;
			break;
		case 5:
			GPIO_PORTF_DATA_REG=level;
			break;		
	}
}


Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Channel_to_pin_port(ChannelId , &port_number , &pin_number);
	switch(port_number)
	{
		case 0:
			TOGGLE_BIT(GPIO_PORTA_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 1:
			TOGGLE_BIT(GPIO_PORTB_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 2:
			TOGGLE_BIT(GPIO_PORTC_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 3:
			TOGGLE_BIT(GPIO_PORTD_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 4:
			TOGGLE_BIT(GPIO_PORTE_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTE_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
		case 5:
			TOGGLE_BIT(GPIO_PORTF_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTF_DATA_REG,pin_number))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}

	}
	return LOGIC_LOW;
}	