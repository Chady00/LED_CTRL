#include "GPT.h"
#include "main.h"

extern void ISR(void);

const Gpt_ConfigType config_GPT[GPT_CFG_CONFIGURED_CHANNELS]=
{
	{GPT_TIMER_A_0_16_32_BIT,16,50,GPT_PRIODIC_TIMER_MODE,ISR}
};