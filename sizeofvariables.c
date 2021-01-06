#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = 'b';
  printf("char b character: %c and size: %lu bytes\n", b, sizeof(b));

  float c = 12.345;
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));

  double d = 123.456;
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));

  unsigned int e = 10;
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));

  short int f = 7;
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f)); 
}

