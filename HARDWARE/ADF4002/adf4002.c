#include "adf4002.h"

long int ReadData;

//long int Reg0x00 = 0x001F40;//r
//////long int Reg0x01 = 0x0DAC01;//n

long int functionReg0x02R = 0x0D80C2; 	//function FUNCTION  0000 1101 1000 0000 1100 0010 //function¼Ä´æÆ÷ ÉèÖÃR DIVIDER OUTPUT
long int initReg0x03R = 0x0D80C3;		//init  0000 1101 1000 0000 1100 0011  //INITIALIZATION ¼Ä´æÆ÷ ÉèÖÃR DIVIDER OUTPUT

long int functionReg0x02N = 0x0D80A2;	 //function 0000 1101 1000 0000 1010 0010 //function¼Ä´æÆ÷ ÉèÖÃN DIVIDER OUTPUT
long int initReg0x03N = 0x0D80A3;		 //init  0000 1101 1000 0000 1010 0011   //INITIALIZATION¼Ä´æÆ÷ ÉèÖÃN DIVIDER OUTPUT

long int Reg0x02_LEDON  = 0x0D80B2; 		//MUXOUT CONTROL : DVDD
long int Reg0x02_LEDOFF = 0x0D80F2;		 	//MUXOUT CONTROL: DGND


void Delay(unsigned int z)
{
  unsigned int i,j;
  
  for(i = z; i > 0; i--)
    for(j = 10; j > 0; j--) ;
}

void DelayMs(void)
{
  unsigned int i, j;
  
  for(i = 0; i < 1000; i++)
  {
    for(j = 0; j < 1000; j++)
    {
      Delay(1000);
    }
  }
}
//adf4002 IO¿Ú³õÊ¼»¯
void InitADF4002(void)
{
	PLL_SCK_0;
	PLL_SDI_0;
	PLL_SEN_0;   
	//SendDataPll(initReg0x03R); //INIT	
	//SendDataPll(functionReg0x02R); //funtion
	SendDataPll(Reg0x02_LEDOFF); //INIT	
	//RDivideTest(1);

}

void SendDataPll(unsigned long int Data)          //´«ËÍµÄÊý¾Ý
{
  unsigned char i;

	PLL_SCK_0;
  PLL_SEN_0;  
  
  for(i = 0; i < 24; i++)
  {
    if(Data & 0x800000)
    {
      PLL_SDI_1;
    }
    else
    {
       PLL_SDI_0;
    }
    Data <<= 1;     
    PLL_SCK_1;
    
    Delay(100);
    
    PLL_SCK_0;
    Delay(100);
  }
  PLL_SDI_0;
  
  PLL_SEN_0;
  Delay(100);
  PLL_SEN_1;
}

void RDivideTest(uint16_t RData)
{
	uint32_t S_R = 0;
	
	S_R = Pre_R + (RData<<2) + R_Address;
	SendDataPll(functionReg0x02R); //funtion
	SendDataPll(S_R);
	SendDataPll(0X000001);	
}
void NDivideTest(uint16_t NData)
{
	uint32_t S_N = 0;
	
	S_N = Pre_N + (NData<<8) + N_Address;
	SendDataPll(functionReg0x02N); //funtion
	SendDataPll(0X000000);
	SendDataPll(S_N);
}














