/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MAIN.h
 *       Module:  
 *  Description:  header file for MAIN file
 *********************************************************************************************************************/
#ifndef MAIN_H
#define MAIN_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 #include "PORT.h"
#include "GPT.h"
#include "NVIC.h"


/**********************************************************************************************************************
 * Configurations
 ********************************************************************************************************************/

// Configurations:
//#define Active		5 		
//#define	Passive		5			

#define DIO_def_PortF_Pin0_Index (uint8) 0x26
#define DIO_def_PortF_Pin1_Index (uint8) 0x27
#define DIO_def_PortF_Pin2_Index (uint8) 0x28
#define DIO_def_PortF_Pin3_Index (uint8) 0x29
#define DIO_def_PortF_Pin4_Index (uint8) 0x2A



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************************************************/


static uint8 sec;
static uint8 Active=1;
static uint8 Passive=1;

typedef uint8 LedID;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void ISR(void);


#endif /* MAIN_H */
/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/