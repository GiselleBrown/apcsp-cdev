//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // create dynamic memory for firstName and lastName
  students[numStudents] = (Student*)malloc(sizeof(Student));
  students[numStudents]->firstName = (char*)malloc((strlen(fname) + 1) * sizeof(char));
  students[numStudents]->lastName = (char*)malloc((strlen(lname) + 1) * sizeof(char));

  //adding information into stucture
  strcpy(students[numStudents]->firstName, fname);
  strcpy(students[numStudents]->lastName, lname);

  students[numStudents]->age = age;
  students[numStudents]->id = id;

  //add one to numStudents so next time student added, added to different index

  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting the pointer values to 0
  for (int i = 0; i < numStudents; i++)
  {
    deleteStudent(students[i]);

    students[i] = 0;
  }
  // adjusting the numStudents to 0
  numStudents = 0;
}


void saveStudents(int key)
{

  FILE* fp;
  fp = fopen(STUFILE, "w");
  char buff[500];

  if(fp)
  {
    for(int i = 0; i < numStudents; i++)
    {
      sprintf(buff, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
      if (key != 0)
      {
        caesarEncrypt(buff, key);
      }
      fprintf(fp, "%s\n", buff);
      printf("Saving: %s\n", buff);
    }
    printf("Saved %d students", numStudents);
    fclose(fp);
  }
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory

  char buff1[256];
  char buff2[256];
  char buff3[256];
  char buff4[256];

  unsigned int age;
  long id;

  FILE* fp;
  fp = fopen(STUFILE, "r");

  if (numStudents > 0)
  {
    deleteStudents();
  }

  if (fp)
  {
    while (1)
    {
      if (fscanf(fp, "%s %s %s %s", buff1, buff2, buff3, buff4) == 4)
      {
        if (key != 0)
        {
          caesarDecrypt(buff1, key);
          caesarDecrypt(buff2, key);
          caesarDecrypt(buff3, key);
          caesarDecrypt(buff4, key);
        }
      sscanf(buff3, "%d", &age);
      sscanf(buff4, "%ld", &id);
      }
      else
      {
        break;
      }
      createStudent(buff1, buff2, age, id);
    }
    printf("Loaded %d students", numStudents);
    fclose(fp);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




