#include <stdio.h>
#include <string.h>


// student structure
//struct Student...
struct Student {
  char firstName[100];
  char lastName[100];
  int age;
  int studentID;
};

void printStudent(struct Student* student)
{
  printf("---------------\n");
  printf("Name: %s %s \n", student->firstName, student->lastName);
  printf("Age: %d\n", student->age);
  printf("Student ID: %d\n", student->studentID);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++)
  {
  printStudent(&students[i]);
  }
}


int main()
{
  // an array of students
  //xxx students;
  struct Student students[100];

  int numStudents = 0;
  while (1)
  {
    char c;
    char input[256];

    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {

      // enter a new student
      char input[256];
      printf("  First name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].firstName);


      printf("\n  Last name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].lastName);

      printf("\n  Age: ");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &students[numStudents].age);

      printf("\n  Student ID: ");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &students[numStudents].studentID);

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
