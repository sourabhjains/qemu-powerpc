#include<stdio.h>
#include<inttypes.h>
int main()
{
uint64_t ra,rs,rb;
scanf("%"SCNu64, &rs);
asm("cnttzw %0,%1\n\t"
     :"=r"(ra)
     :"r"(rs)
   );
printf("%"PRIu64"\n",ra);
return 0;
}
