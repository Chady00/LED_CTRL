
#include "DIO.h"

int pin_number,port_number;

/* function to get the port_number and pin_number number from channelId*/
void Channel_to_pin_port(Dio_ChannelType ChannelId, int* port_number ,  int* pin_number)
{
	
	*pin_number=ChannelId%8;

	if(ChannelId<0x08)
	{
		*port_number=DIO_def_PORTA;

	}
	else if(ChannelId>=0x08 && ChannelId<0x10)
	{
		*port_number=DIO_def_PORTB;

	}
	else if(ChannelId>=0x10 && ChannelId<0x18)
	{
		*port_number=DIO_def_PORTC;

	}
	else if(ChannelId>=0x18 && ChannelId<0x20)
	{
		*port_number=DIO_def_PORTD;

	}
	else if(ChannelId>=0x20 && ChannelId<0x26)
	{
		*port_number=DIO_def_PORTE;
	
	}
	else if(ChannelId>=0x26 && ChannelId<=0x2A)
	{
		*port_number=DIO_def_PORTF;
		*pin_number-=6;
	}
	
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Channel_to_pin_port(ChannelId,&port_number,&pin_number);
	
	switch(port_number)
	{
		case DIO_def_PORTA:
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTB:
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTC:
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTD:
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTE:
			if(BIT_IS_SET(GPIO_PORTE_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTF:
			if(BIT_IS_SET(GPIO_PORTF_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}

	}
	return 0;
}



void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level)
{
	Channel_to_pin_port(ChannelId,&port_number,&pin_number);
	switch(port_number)
	{
		case DIO_def_PORTA:
			if(level)
			{
				SET_BIT(GPIO_PORTA_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTA_DATA_REG,pin_number);
			}
			break;
		case DIO_def_PORTB:
			if(level)
			{
				SET_BIT(GPIO_PORTB_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTB_DATA_REG,pin_number);
			}
			break;
		case DIO_def_PORTC:
			if(level)
			{
				SET_BIT(GPIO_PORTC_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTC_DATA_REG,pin_number);
			}
			break;	
		case DIO_def_PORTD:
			if(level)
			{
				SET_BIT(GPIO_PORTD_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTD_DATA_REG,pin_number);
			}
			break;			
		case DIO_def_PORTE:
			if(level)
			{
				SET_BIT(GPIO_PORTE_DATA_REG,pin_number)	;
			}
			else
			{
				CLEAR_BIT(GPIO_PORTE_DATA_REG,pin_number);
			}
			break;
		case DIO_def_PORTF:
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
		case DIO_def_PORTA:
			Data =(uint8)GPIO_PORTA_DATA_REG;
			break;
		case DIO_def_PORTB:
			Data =(uint8)GPIO_PORTB_DATA_REG;
			break;
		case DIO_def_PORTC:
			Data =(uint8)GPIO_PORTC_DATA_REG;
			break;
		case DIO_def_PORTD:
			Data =(uint8)GPIO_PORTD_DATA_REG;
			break;
		case DIO_def_PORTE:
			Data =(uint8)GPIO_PORTE_DATA_REG;
			break;
		case DIO_def_PORTF:
			Data =(uint8)GPIO_PORTF_DATA_REG;
			break;		
	}
	return Data;
	
	
}


void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level)
{
		switch(PortId)
	{
		case DIO_def_PORTA:
			GPIO_PORTA_DATA_REG=level;
			break;
		case DIO_def_PORTB:
			GPIO_PORTB_DATA_REG=level;
			break;
		case DIO_def_PORTC:
			GPIO_PORTC_DATA_REG=level;
			break;
		case DIO_def_PORTD:
			GPIO_PORTD_DATA_REG=level;
			break;
		case DIO_def_PORTE:
			GPIO_PORTE_DATA_REG=level;
			break;
		case DIO_def_PORTF:
			GPIO_PORTF_DATA_REG=level;
			break;		
	}
}


Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Channel_to_pin_port(ChannelId , &port_number , &pin_number);
	switch(port_number)
	{
		case DIO_def_PORTA:
			TOGGLE_BIT(GPIO_PORTA_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTB:
			TOGGLE_BIT(GPIO_PORTB_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTC:
			TOGGLE_BIT(GPIO_PORTC_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTD:
			TOGGLE_BIT(GPIO_PORTD_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTE:
			TOGGLE_BIT(GPIO_PORTE_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTE_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		case DIO_def_PORTF:
			TOGGLE_BIT(GPIO_PORTF_DATA_REG,pin_number);
			if(BIT_IS_SET(GPIO_PORTF_DATA_REG,pin_number))
			{
				return 1;
			}
			else
			{
				return 0;
			}

	}
	return 0;
}	
	
