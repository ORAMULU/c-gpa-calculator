#include "classification.h"
#include <stdio.h>
#include <string.h>

void getClassLabel (float gpa, char buffer[]) {
  if (gpa < 0.00 || gpa > 5.00) {
    strcpy(buffer, "CGPA is out of range");
    return;
  }

  if (gpa >= 4.50) {
    strcpy(buffer, "First Class\n");
  } else if (gpa >= 3.50) {
    strcpy(buffer, "Second Class Upper\n");
  } else if (gpa >= 2.40) {
    strcpy(buffer, "Second Class Lower\n");
  } else if (gpa >= 1.50) {
    strcpy(buffer, "Third Class\n");
  } else if (gpa >= 1.00) {
    strcpy(buffer, "Pass\n");
  } else {
    strcpy(buffer, "Fail\n");
  }
}