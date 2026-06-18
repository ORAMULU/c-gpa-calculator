#ifndef COURSE_H
#define COURSE_H

typedef struct {
  char courseName[50];
  int unit;
  char grade;
} Course;

int calcTotalUnit (Course courses[], int numCourses);
int getGp(Course course);
void fillGpValues (Course courses[], int gpValues[], int numCourses);
int getTotalGp (int gpValues[], int numCourses);

#endif