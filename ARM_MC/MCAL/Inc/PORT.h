

#ifndef PORT_h
#define PORT_h

/*Includes*/

#include "Std_Types.h"
#include "tm4c123gh6pm_registers.h"
#include "Common_Macros.h"
#include "PORT_def.h"
#include "PORT_CFG.h"

#define ConfiguredChannels 43


/**********************************************************************************************************
*																						MODULE DATATYPES																							*
**********************************************************************************************************/

typedef uint8 PORT_PIN_TYPE;

typedef enum
{
	INPUT,OUTPUT
}PORT_PIN_DIRECTION;

typedef uint8 PORT_PIN_MODE;

typedef enum
{
	OFF,PULL_UP,PULL_DOWN
}PORT_PIN_INTERNAL_ATTACH;

typedef enum
{
	_2MA,_4MA,_8MA
}PORT_PIN_OUPTUT_CURRENT_TYPE;


typedef enum
{
	LOW,HIGH
}PORT_PIN_LEVEL_VALUE;


typedef struct
{
	PORT_PIN_TYPE PortNumber;
	PORT_PIN_TYPE PinNumber;
	PORT_PIN_DIRECTION dir;
	PORT_PIN_MODE mode;
	PORT_PIN_INTERNAL_ATTACH resistance;
	PORT_PIN_OUPTUT_CURRENT_TYPE current_type;
	PORT_PIN_LEVEL_VALUE value;
	
}PORT_CFG;


typedef struct 
{
	PORT_CFG  channels[ConfiguredChannels];
}Port_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Port_ConfigType config[PORT_CONFIGURED_CHANNELS];


/**********************************************************************************************************
*																						MODULE FUNCTIONS PROTOTYPE																		*
**********************************************************************************************************/




/************************************************************************************
* Service Name: Port_Init
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module
************************************************************************************/
void Initialize_Port(const Port_ConfigType* configptr);


#endif 

