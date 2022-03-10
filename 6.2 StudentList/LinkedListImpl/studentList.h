#pragma once
#include "list.h"
#include "student.h"

//Allocate memory and return pointer to student list
list_t studentList_create(void);
//Add student to student list
ListReturnCode studentList_addStudent(list_t studentList, student_t student);
//Get student from student list
ListReturnCode studentList_getStudent(list_t studentList, student_t* student, uint16_t index);
//Remove student from student list
ListReturnCode studentList_removeStudent(list_t studentList, student_t student);
//Return size of student list
uint16_t studentList_noOfStudents(list_t studentList);