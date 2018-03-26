#include <stdio.h>
#include <inttypes.h>

int main()
{
  uint64_t ra, rs, rb;
  int const wi=0;

  //scanf("%"SCNu64"%"SCNu64, &ra, &rb);
  scanf("%"SCNu64, &rb);
int i;
for(i=0;i<10;i++)
{
 __asm__ __volatile__("popcntd %0,%1\n\t" 
     : "=r"(ra)
     : "r"(rb)
    
  );

   printf("%"PRIu64"\n", ra);
}
  return 0;
}

