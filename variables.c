#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  a = a + 3;
  c = c - 3;
  printf("a = %d, c = %d\n", a, c);
}
