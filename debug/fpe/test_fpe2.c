#include <stdlib.h>
#include <stdio.h>
#ifdef TRAPFPE
#include "fpe_x87_sse/fpe_x87_sse.h"
#endif

int main(int argc, char *argv[])
{
  float a, b, c, tmp;

#ifdef TRAPFPE
  set_fpe_x87_sse_();
#endif

  printf("Insert a, b \n");
  scanf("%f",&a);
  scanf("%f",&b);

  tmp = a / b;

  if(tmp > 2.)
    {
      c = +1.;
    }
  else
    {
      c = -1.;
    }

  printf("c = %f \n", c);

  return(EXIT_SUCCESS);
}
