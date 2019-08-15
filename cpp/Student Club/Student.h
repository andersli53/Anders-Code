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
#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>

class Student {
public:
	/** Default Constructor
	*/
	Student();

	/** Constructor for Student
			@param name - a string argument for the student
	*/
	Student(std::string name);
	/** Accessor member function for the name of student
			@return a string for the name of student
	*/
	std::string getName();


private:
	std::string name;
};


#endif // !STUDENT_
