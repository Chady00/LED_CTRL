 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: dio.h
 *
 * Description: Header file for the Dio driver
*******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define NUM_OF_PORTS           6
#define NUM_OF_PINS_PORTA   	 8
#define NUM_OF_PINS_PORTB   	 8
#define NUM_OF_PINS_PORTC   	 8
#define NUM_OF_PINS_PORTD   	 8
#define NUM_OF_PINS_PORTE   	 6
#define NUM_OF_PINS_PORTF   	 5



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
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


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType level);



/*
 * Description :
 * Flip the channel (bit). If bit is high flip to low , if bit is low flip to high
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType level);

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

#endif /* GPIO_H_ */
