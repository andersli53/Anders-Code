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
#include <algorithm>
#include "Student.h"
#include "StudentClub.h"

/** Default Constructor
*/
StudentClub::StudentClub() {}


/** Constructor for StudentClub
		@param p - a pointer to a Student class
		@param v - a pointer to a Student class
		@param s - a pointer to a Student class
		@param t - a pointer to a Student Class
		@param m - a pointer to a vector
*/
StudentClub::StudentClub(Student* p, Student* v, Student* s, Student* t, std::vector<Student*> m) 
	: president(p), vicePresident(v), secretary(s), treasurer(t), club_members(m)
{
}

/** Accessor member function for the pointer of president
		@return a pointer to a class
*/
Student * StudentClub::get_president() const
{
	return president;
}

/** Accessor member function for the pointer of vice-president
		@return a pointer to a class
*/
Student * StudentClub::get_vice_president() const
{
	return vicePresident;
}

/** Accessor member function for the pointer of secretary
		@return a pointer to a class
*/
Student * StudentClub::get_secretary() const
{
	return secretary;
}

/** Accessor member function for the pointer of treasurer
		@return a pointer to a class
*/
Student * StudentClub::get_treasurer() const
{
	return treasurer;
}

/** Mutator member function to get the members
		@return a vector of pointer
*/
std::vector<Student*> StudentClub::get_members() const
{
	return club_members;
}

/** Mutator member function to store members' name
		@param s - a pointer to class
*/
void StudentClub::add_member(Student * s)
{
	std::vector<Student*> memberName;
	memberName.push_back(s);
}

/** Accessor member function to give the number of members
		@return an int for the number of members
*/
int StudentClub::num_members() const
{

	return club_members.size();
}


