#pragma once
#include <stdio.h>
#include "student.h"
#include "list.h"

//Allocate memory and create the list
list_t studentHandler_create(void);
//Print information about the student
void studentHandler_printStudentInfo(student_t student);
//Print information about all students on the list
void studentHandler_printAllStudentsInfo(list_t studentList);
//Search for a student by ID
student_t studentHandler_searchStudentById(list_t studentList, int studentId);
//Search for a student by last name
student_t studentHandler_searchStudentByLastName(list_t studentList, char* lastName);
//Add student to the list
void studentHandler_addStudent(list_t studentList, student_t student);