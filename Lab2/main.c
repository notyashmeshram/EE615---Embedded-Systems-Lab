#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

int main(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;       /* enable clock to GPIOF */
    GPIO_PORTF_LOCK_R = 0x4C4F434B;     /* unlock commit register */
    GPIO_PORTF_CR_R = 0x1F;             /* make PORTF0 configurable */
    GPIO_PORTF_DEN_R = 0x1E;            /* set PORTF pins 4 pin */
    GPIO_PORTF_DIR_R = 0x0E;            /* set PORTF4 pin as input user switch pin */
    GPIO_PORTF_PUR_R = 0x10;            /* PORTF4 is pulled up */


    register int i = 0;
      while(1)
      {
//          GPIO_PORTF_DATA_R = 0x10;
//          if(GPIO_PORTF_DATA_R < 0x10)
//          {
//              GPIO_PORTF_DATA_R = 0x02;
//          }


          GPIO_PORTF_DATA_R = 0x10;
          if(GPIO_PORTF_DATA_R < 0x10)
          {
                  if(GPIO_PORTF_DATA_R == 0x00 && i==0)
                  {
                      GPIO_PORTF_DATA_R = 0x02;
                      i = 1;
                  }
                  else if(GPIO_PORTF_DATA_R == 0x00 && i==1)
                  {
                      GPIO_PORTF_DATA_R = 0x04;
                       i = 2;
                  }
                  else if(GPIO_PORTF_DATA_R == 0x00 && i==2)
                  {
                      GPIO_PORTF_DATA_R = 0x08;
                      i = 0;
                  }
              }
          }
}

