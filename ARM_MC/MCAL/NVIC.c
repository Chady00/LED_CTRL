

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "NVIC.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")


/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm("CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm("CPSID F") 


/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")



#define NVIC_GROUPING_TYPE_XXX    		4
#define NVIC_GROUPING_TYPE_XXY    		5
#define NVIC_GROUPING_TYPE_XYY    		6
#define NVIC_GROUPING_TYPE_YYY    		7


#define WORD_LENGTH_BIT 							32

#define WORD_LENGTH_BYTE 							4



#define APINT_VECTKEY_PASSKEY         0x05FA
#define PRIGROUP_FIELD_OFFSET        	0x8u
#define APINT_VECTKEY_FIELD_OFFSET   	16u
#define NVIC_PRI_REG_RESERVED					5u
#define NVIC_REG_NUM_OF_PRI_FIELDS   	4u 

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
	static  volatile unsigned long  * Pri_Reg_PTR		=		NULL_PTR;

/******************************************************************************
* \Syntax          : void NVIC_init(void)        
* \Description     : Initilizing the configured interrupts                                   
*                                                                       
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void NVIC_init(void)
{
	NVIC_InterruptType InterruptNumber;
	
	uint8 Group,SubGroup,i;
	
	uint32 GroupingSystem,RegOffset,Offset;
	
	NVIC_APINT_REG =(APINT_VECTKEY_PASSKEY<<APINT_VECTKEY_FIELD_OFFSET)|(NVIC_CFG_GROUPING_SUBGROUPINT_PRIORITY_SYSTEM<<PRIGROUP_FIELD_OFFSET);
	
	Enable_Exceptions();
	
	Enable_Faults();
	
	for(i=0;i<NVIC_CFG_NUMBER_OF_CONFIGURED_HANDLERS;i++)
	{
		
		InterruptNumber=NVIC_CFG_Init[i].InterruptPeripheralGates;
		Group=NVIC_CFG_Init[i].InterruptGroupPriority;
		SubGroup=NVIC_CFG_Init[i].InterruptSubGroupPriority;
		
		RegOffset=(InterruptNumber/WORD_LENGTH_BIT)*WORD_LENGTH_BYTE;
		Offset=InterruptNumber%WORD_LENGTH_BIT;
		switch(RegOffset/WORD_LENGTH_BYTE)
		{
			case 0: SET_BIT(NVIC_EN0_REG,Offset); break;
			case 1: SET_BIT(NVIC_EN1_REG,Offset); break;
			case 2: SET_BIT(NVIC_EN2_REG,Offset); break;
			case 3: SET_BIT(NVIC_EN3_REG,Offset); break;			
		}
		
		#if(NVIC_CFG_GROUPING_SUBGROUPINT_PRIORITY_SYSTEM==NVIC_GROUPING_TYPE_XXX)
		GroupingSystem=((Group<<0)&0x7)|(SubGroup&0x0);
		#endif
		#if(NVIC_CFG_GROUPING_SUBGROUPINT_PRIORITY_SYSTEM==NVIC_GROUPING_TYPE_XXY)
		GroupingSystem=((Group<<1)&0x6)|(SubGroup&0x1);
		#endif
		#if(NVIC_CFG_GROUPING_SUBGROUPINT_PRIORITY_SYSTEM==NVIC_GROUPING_TYPE_XYY)
		GroupingSystem=((Group<<2)&0x4)|(SubGroup&0x3);
		#endif
		#if(NVIC_CFG_GROUPING_SUBGROUPINT_PRIORITY_SYSTEM==NVIC_GROUPING_TYPE_YYY)
		GroupingSystem=((Group<<3)&0x0)|(SubGroup&0x7);
		#endif
		
		RegOffset=(InterruptNumber/NVIC_REG_NUM_OF_PRI_FIELDS);
		
		Offset=NVIC_PRI_REG_RESERVED+((InterruptNumber%NVIC_REG_NUM_OF_PRI_FIELDS)*8);
		
		Pri_Reg_PTR=&(NVIC_PRI0_REG);
		
		Pri_Reg_PTR+=RegOffset;
		
		*(Pri_Reg_PTR)|=(GroupingSystem<<Offset);
		
		
	}
	
	
	
}

/**********************************************************************************************************************
 *  END OF FILE: NVIC.c
 *********************************************************************************************************************/
