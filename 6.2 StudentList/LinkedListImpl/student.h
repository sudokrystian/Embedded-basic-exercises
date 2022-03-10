#pragma once
#include <string.h>

typedef struct student* student_t;

//Allocate memory and create a student
student_t student_createStudent(char* firstName, char* lastName, int studentId, char* nationality);
//Get student's last name
char* student_getStudentLastName(student_t student);
//Get student's ID
int student_getStudentId(student_t student);
//Print info about the student
void student_printInfo(student_t self);