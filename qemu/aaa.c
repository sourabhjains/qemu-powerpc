#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <altivec.h>

#define SIZE (sizeof(__vector uint8_t) / sizeof(uint8_t))

typedef union {
  __vector uint8_t v;
  uint8_t a[SIZE];
} vuint8_t;

void vec_get_x8(__vector uint8_t *v) {
  int i;
  vuint8_t u;

  for (i = 0; i < SIZE; ++i) {
    scanf("%"SCNx8, &u.a[i]);
  }

  *v = u.v;
}

void vec_put_x8(__vector uint8_t v) {
  int i;
  vuint8_t u;

  for (u.v = v, i = 0; i < SIZE; ++i) {
    printf("%4"PRIx8, u.a[i]);
  }

  putchar('\n');
}

int main(void) {
  uint8_t t;
  __vector uint8_t vra, vrb, vrt;

  scanf("%"SCNu8, &t);

  while (t--) {
    vec_get_x8(&vra);
    vec_get_x8(&vrb);

    asm(
      "vcmpnezb %0,%1,%2 \n\t" \
      : "=vr"(vrt)
      : "vr"(vra), "vr"(vrb)
    );

    printf("VRA = "); vec_put_x8(vra);
    printf("VRB = "); vec_put_x8(vrb);
    printf("VRT = "); vec_put_x8(vrt);
  }

  return EXIT_SUCCESS;
}
