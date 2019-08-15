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
#ifndef STUDENTCLUB_H
#define STUDENTCLUB_H
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class StudentClub {
public:
	/** Default Constructor
	*/
	StudentClub();

	/** Constructor for StudentClub
			@param p - a pointer to a Student class
			@param v - a pointer to a Student class
			@param s - a pointer to a Student class
			@param t - a pointer to a Student Class
			@param m - a pointer to a vector
	*/
	StudentClub(Student* p, Student* v, Student* s, Student* t, std::vector<Student*> m);
	
	/** Accessor member function for the pointer of president
			@return a pointer to a class
	*/
	Student* get_president() const;

	/** Accessor member function for the pointer of vice-president
			@return a pointer to a class
	*/
	Student* get_vice_president() const;

	/** Accessor member function for the pointer of secretary
			@return a pointer to a class
	*/
	Student* get_secretary() const;

	/** Accessor member function for the pointer of treasurer
			@return a pointer to a class
	*/
	Student* get_treasurer() const;

	/** Mutator member function to get the members
			@return a vector of pointer
	*/
	std::vector<Student*> get_members() const;
	
	/** Mutator member function to store members' name
			@param s - a pointer to class
	*/
	void add_member(Student* s);

	/** Accessor member function to give the number of members
			@return an int for the number of members
	*/
	int num_members() const;

private:
	Student* president;
	Student* vicePresident;
	Student* secretary;
	Student* treasurer;
	std::vector<Student*> club_members;
	std::vector<Student*> club_officers;
};

#endif // !STUDENTCLUB_H

