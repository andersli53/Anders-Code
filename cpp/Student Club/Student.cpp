/**

Homework 2
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon

Collaborator: Wong, Chi Hin (Terence)

Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

/** Default Constructor
*/
Student::Student()
{
}

/** Constructor for Student
		@param name - a string argument for the student
*/
Student::Student(std::string name) : name(name){}

/** Accessor member function for the name of student
		@return a string for the name of student
*/
std::string Student::getName()
{
	return name;
}
