#include<stdio.h>
#include<inttypes.h>
int main()
{
uint64_t ra,rs,rb;
scanf("%"SCNu64, &rs);
scanf("%"SCNu64, &ra);
  asm("cmprb %0,%1\n\t" 
     : "r"(ra)
     : "i"(1)
     : "=r"(rs)
     : "r"(ra)
  );
printf("%"PRIu64"\n",ra);
return 0;
}
