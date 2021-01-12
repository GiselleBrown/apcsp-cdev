#include <stdio.h>
#include <math.h>

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius)
{
  float area = radius * radius * M_PI;
  return area;
}

int main(int argc, char* argv[]) 
{
  float start;
  float end;
  char buffer[256];

  if (argc < 2)
  {
    printf("What do you want the starting radius to be\n");
    while (1)
    {
      fgets(buffer, 256, stdin);
      if (sscanf(buffer, "%f", &start) == 1) break;
      printf("Not a valid float - try again!\n");
    }

   printf("What do you want the ending raduis to be\n");
   while (1)
   {
     fgets(buffer, 256, stdin);
     if (sscanf(buffer, "%f", &end) == 1) break;
     printf("Not a valid float - try again!\n");
   }
   printf("calculating area of circle starting at %f, and ending at %f\n", start, end);
   float reps = end - start; 
   for (int i = 0; i < reps; i++)
   {
    float calculation  = areaOfCircle(start);
    printf("area for radius %f is %f\n", start, calculation);
    start++;
   }
  }
  else
  {
   

  }
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2

  printf("calculating area of circle starting at %f, and ending at %f\n", start, end);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
  float reps = end - start;
  for (int i = 0; i < reps; i++)
  {
    float calculation  = areaOfCircle(start);
    printf("area for radius %f is %f\n", start, calculation);
    start++;
  }
}
