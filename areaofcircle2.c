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
  int arg = 0; 
  if (argc < 2)
  {
  
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;

  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end

  for (int i = 0; i < reps; i++)
  {
    float calculation  = areaOfCircle(start);
    printf("area for radius %f is %f\n", start, calculation);
    start++;
  }
}