#include "common_macros.h"
#include "std_types.h"
#include "basic.h"

int main(void)
{
	//intializing the port and gpt
	
	
	while(1)
	{ // if led is on.. check if seconds > time --> make led off = timeout
		//else if led off switch it to ON --> and vice versa
			
	}
}

void turn_ON(LedID ID)
{	if(ID ==LED_RED){
	Dio_WriteChannel(DIO_def_PortF_Pin1_Index,LOGIC_HIGH);
	}
	else if(ID==LED_BLUE){
		Dio_WriteChannel(DIO_def_PortF_Pin2_Index,LOGIC_HIGH);
	}
	
	else {
		//green
		Dio_WriteChannel(DIO_def_PortF_Pin3_Index,LOGIC_HIGH);
	}
	
}
void turn_OFF(LedID ID)
{
		if(ID ==LED_RED){
	Dio_WriteChannel(DIO_def_PortF_Pin1_Index,LOGIC_LOW);
	}
	else if(ID==LED_BLUE){
		Dio_WriteChannel(DIO_def_PortF_Pin2_Index,LOGIC_LOW);
	}
	
	else {
		//green
		Dio_WriteChannel(DIO_def_PortF_Pin3_Index,LOGIC_LOW);
	}