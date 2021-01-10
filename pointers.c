#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 12.34;
  float e = 56.78;

  printf("The value of d is  %f and it's address is %p\n", d, &d);
  printf("The value of e is  %f and it's address is %p\n", e, &e);

  float* ptrtod = &d;
  float* ptrtoe = &e;

  float f = *ptrtod;

  *ptrtod = *ptrtoe;
  *ptrtoe = f;

  printf("d equals %f and e equals %f\n", d, e);
}
