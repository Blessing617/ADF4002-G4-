#ifndef _adf4002_h_
#define _adf4002_h_

#include "main.h"

#define R_Address 0X000000
#define N_Address 0X000001
#define F_Address 0X000002
#define I_Address 0X000003
#define Pre_R 0X000000
#define Pre_N 0X000000

//¹Ü½ÅÉùÃ÷
#define PLL_SCK_0 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET)
#define PLL_SCK_1 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET)

#define PLL_SDI_0 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET)
#define PLL_SDI_1 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET)

#define PLL_SEN_0 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET)
#define PLL_SEN_1 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET)


void InitADF4002(void);
void Delay(unsigned int z);
void DelayMs(void);
void SendDataPll(unsigned long int Data);

void RDivideTest(uint16_t RData);
void NDivideTest(uint16_t NData);


#endif
