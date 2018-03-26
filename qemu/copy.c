#include<stdio.h>
#include<inttypes.h>
int main()
{
uint64_t ra,rs,rb;
//scanf("%"SCNu64, &rs);
scanf("%"SCNu64, &rb);

  asm("copy %0,%1\n\t"
     : "=r"(rs)
     : "r"(rb)
  );

printf("%"PRIu64"\n",ra);	
return 0;
}
