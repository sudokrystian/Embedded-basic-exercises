#include <stdlib.h>
#include "student.h"
#include "studentHandler.h"

int main()
{
    //Student IDs
    int putindId = 666666;
    int godpseedId = 777777;
    int obamaId = 268594;
    int ilonaId = 129864;
    int malyszId = 123456;
    //Create students
    student_t student1 = student_createStudent("John", "Godspeed", godpseedId, "Estonia");
    student_t student2 = student_createStudent("Barack", "Obama", obamaId, "USA");
    student_t student3 = student_createStudent("Vladimir", "Putin", putindId, "Russia");
    student_t student4 = student_createStudent("Ilona", "Brewinska", ilonaId, "Poland");
    student_t student5 = student_createStudent("Adam", "Malysz", malyszId, "Poland");
    //Initialize the list
    list_t studentList = studentHandler_create();
    //Add students to the list
    studentHandler_addStudent(studentList, student1);
    studentHandler_addStudent(studentList, student2);
    studentHandler_addStudent(studentList, student3);
    studentHandler_addStudent(studentList, student4);
    studentHandler_addStudent(studentList, student5);
    //Print out members of the list
    printf("### Student list number one\n");
    studentHandler_printAllStudentsInfo(studentList);
    //Search for a student By last name
    char lastNameObama[] = "Obama";
    printf("*** Looking for a student with last name %s ***\n", lastNameObama);
    student_t searchStudentByLastName = studentHandler_searchStudentByLastName(studentList, lastNameObama);
    if (searchStudentByLastName == NULL) {
        printf("Couldn't find student with last name %s\n", lastNameObama);
    }
    else {
        studentHandler_printStudentInfo(searchStudentByLastName);
    }
    //Search for a student by ID
    printf("*** Looking for a student with ID %d ***\n", putindId);
    student_t searchStudentById = studentHandler_searchStudentById(studentList, putindId);
    if (searchStudentById == NULL) {
        printf("PUTIN RAN AWAY");
    }
    else {
        studentHandler_printStudentInfo(searchStudentById);
    }
}