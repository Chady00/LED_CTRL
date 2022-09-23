

#ifndef PORT_h
#define PORT_h

/*Includes*/

#include "Std_Types.h"
#include "tm4c123gh6pm_registers.h"
#include "Common_Macros.h"
#include "DIO_Def.h"




/**********************************************************************************************************
*								  													MODULE DATATYPES																							*
**********************************************************************************************************/

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}Dio_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}Dio_PortDirectionType;

typedef enum
{
	A,B,C,D,E,F
}Dio_def_PORT;

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;
typedef uint8 Dio_PortLevelType;

typedef enum
{
	LOW,HIGH
}Dio_LevelType;


/**********************************************************************************************************
*																						MODULE FUNCTIONS PROTOTYPE																		*
**********************************************************************************************************/

/************************************************************************************
* Service Name: Dio_ReadChannel
* Parameters (in): ChannelId - Channel number
* Parameters (inout): None
* Parameters (out): None
* Return value: Low or High
* Description: Read the value of specific pin_number
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);



/************************************************************************************
* Service Name: Dio_WriteChannel
* Parameters (in): ChannelId - Channel number , level- high or low
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Writing value on pin_number
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level);



/************************************************************************************
* Service Name: Dio_ReadPort
* Parameters (in): PortId - port_number number
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType 0-255
* Description: Reading the value of specific port_number
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);



/************************************************************************************
* Service Name: Dio_WritePort
* Parameters (in): PortId - port_number number , level - 0->255
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Writing value on specific port_number
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType level);



/************************************************************************************
* Service Name: Dio_FlipChannel
* Parameters (in): ChannelId - Channel number
* Parameters (inout): None
* Parameters (out): None
* Return value: High or Low
* Description: flipping value of specific pin_number and returning the new value 
************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);


#endif 

