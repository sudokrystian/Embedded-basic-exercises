#include "studentHandler.h"
#include "studentList.h"
#include <stdlib.h>

list_t studentHandler_create(void)
{
    return studentList_create();
}

void studentHandler_printStudentInfo(student_t student)
{
    student_printInfo(student);
}

void studentHandler_printAllStudentsInfo(list_t studentList)
{
    uint16_t numberOfStudents = studentList_noOfStudents(studentList);

    student_t student = (student_t)malloc(sizeof(student_t));


    for (int i = 0; i < numberOfStudents; i++)
    {
        studentList_getStudent(studentList, &student, i);
        student_printInfo(student);
    }
    free(student);
}

student_t studentHandler_searchStudentById(list_t studentList, int studentId)
{

    uint16_t numberOfStudents = studentList_noOfStudents(studentList);

    student_t student = (student_t)malloc(sizeof(student_t));

    for (int i = 0; i < numberOfStudents; i++)
    {
        studentList_getStudent(studentList, &student, i);
        if (student_getStudentId(student) == studentId)
        {
            return student;
        }
    }
    free(student);
    return NULL;
}

student_t studentHandler_searchStudentByLastName(list_t studentList, char* lastName)
{
    int numberOfStudents = studentList_noOfStudents(studentList);
    student_t student;

    for (int i = 0; i < numberOfStudents; i++)
    {
        studentList_getStudent(studentList, &student, i);
        if (*student_getStudentLastName(student) == *lastName)
        {
            return student;
        }
    }
    return NULL;
}

void studentHandler_addStudent(list_t studentList, student_t student)
{
    studentList_addStudent(studentList, student);
}