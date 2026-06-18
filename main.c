#include "course.h"
#include "classification.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

void writeToFile(Course courses[], int numCourses, float gpa, char label[], int gpValues[]) {
  FILE *file = fopen("output.txt", "w");
  fprintf(file, "Course Name  Units  Grades  GP Contribution\n");
  fprintf(file, "--------------------------------------------\n");

  for (int i = 0; i < numCourses; i++) {
    fprintf(file, "%-11s  %-5d  %-6c  %-3d\n", courses[i].courseName, courses[i].unit, courses[i].grade, gpValues[i]);
  }

  fprintf(file, "--------------------------------------------\n");
  fprintf(file, "GPA: %.2f\n", gpa);
  fprintf(file, "Class of Degree: %s", label);
  fclose(file);
  return;
}

int main (void) {
  int numCourses;
  do {
    printf("How many courses? ");
    int result = scanf("%d", &numCourses);
    if (result != 1) {
      printf("⚠️ That's not a valid number!\n");
      while (getchar() != '\n');
    } else if (numCourses < 1 || numCourses > 12) {
      printf("⚠️ Number of courses is out of range! ... \n");
    }
  } while (numCourses < 1 || numCourses > 12);

  int gpValues[numCourses];
  Course courses[numCourses];

  for (int i = 0; i < numCourses; i++) {
    printf("Course %d \n", i+1);

    do {
      printf("Enter course name:");
      scanf("%s", courses[i].courseName);

      if (strlen(courses[i].courseName) != 6) {
        printf("⚠️ \"%s\" is not a valid course name!\n", courses[i].courseName);
      }
    } while (strlen(courses[i].courseName) != 6);

    do {
      printf("Enter course unit:");
      int result = scanf("%d", &courses[i].unit);
      if (result != 1) {
        printf("⚠️ That's not a valid number!\n");
        while (getchar() != '\n');
      } else if (courses[i].unit < 0 || courses[i].unit > 5) {
        printf("⚠️ Invalid unit! ... \n");
      }
    } while (courses[i].unit < 0 || courses[i].unit > 5);

    printf("Enter course grade (e.g. A, B, C, ...):");
    scanf(" %c", &courses[i].grade);
    courses[i].grade = toupper(courses[i].grade);
  }

  //numCourses = sizeof(courses) / sizeof(courses[0]);
  fillGpValues(courses, gpValues, numCourses);


  printf("Course Name  Units  Grades  GP Contribution\n");
  printf("--------------------------------------------\n");
  for (int i = 0; i < numCourses; i++) {
    printf("%-11s  %-5d  %-6c  %-3d\n", courses[i].courseName, courses[i].unit, courses[i].grade, gpValues[i]);
  }

  float GPA = (float)getTotalGp(gpValues, numCourses) / calcTotalUnit(courses, numCourses);

  char label[50];
  getClassLabel(GPA, label);

  printf("--------------------------------------------\n");
  printf("GPA: %.2f\n", GPA);
  printf("Class of Degree: %s", label);

  char saveChoice;
  printf("Save results to a file? (y/n): ");
  scanf(" %c", &saveChoice);
  if (saveChoice == 'y') {
    writeToFile(courses, numCourses, GPA, label, gpValues);
    printf("Saving results");
    fflush(stdout);
    for (int i = 1; i <= 3; i++) {
      usleep(300000);
      printf("▪");
      fflush(stdout);
    }
    printf("\n");
  }

  return 0;
}