#include <stdio.h>
#include <string.h>

int main()
{
  // string created using for loop
  char stringOne[27];
  for (int i = 0; i < 26; i++)
  {
    stringOne[i] = 'a' + i;
  }
  stringOne[26] = '\0';
 
 // string created using constant initializer
  char stringTwo[] = "abcdefghijklmnopqrstuvwxyz";

  // Comparing the string
  if (strcmp(stringOne, stringTwo) == 0)
  {
    printf("stringOne and stringTwo are the same\n");
  }
  else
  {
    printf("not working\n");
  }
  //Turing one into uppercase
  for (int i = 0; i < 26; i++)
  {
    stringTwo[i] -= 32;
  }

  // Comparing to see if different
  if (strcmp(stringOne, stringTwo) != 0)
  {
    printf("they no longer equal each other\n");
  }

  // Joint upper and lower case
  char stringThree[54];
  strcpy(stringThree, stringTwo);
  strcpy(stringThree, stringOne);

  // Printing
  printf("String One: %s\n String Two: %s\n String Three: %s\n", stringOne, stringTwo, stringThree);

}
