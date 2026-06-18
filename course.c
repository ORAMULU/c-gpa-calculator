#include "course.h"
#include <stdio.h>

int calcTotalUnit (Course courses[], int numCourses) {
  int totalUnit = 0;
  for (int i = 0; i < numCourses; i++) {
    totalUnit += courses[i].unit;
  }

  return totalUnit;
}

int getGradePointValue (Course course) {
  char grade = course.grade;

  switch (grade) {
    case 'A': return 5;
    case 'B': return 4;
    case 'C': return 3;
    case 'D': return 2;
    case 'E': return 1;
    case 'F': return 0;
    default: return -1;
  }
}

int getGp(Course course) {
  int gradeValue = getGradePointValue(course);
  if (gradeValue == -1) {
    printf("❌ Invalid grade for %s!\n", course.courseName);
    return 0;
  }
  return course.unit * gradeValue;
}

void fillGpValues (Course courses[], int gpValues[], int numCourses) {
  for (int i = 0; i < numCourses; i++) {
    gpValues[i] = getGp(courses[i]);
  }
}

int getTotalGp (int gpValues[], int numCourses) {
  int totalGp = 0;
  for (int i = 0; i < numCourses; i++) {
    totalGp += gpValues[i];
  }

  return totalGp;
}