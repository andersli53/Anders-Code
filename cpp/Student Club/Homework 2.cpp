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
// Homework 2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "StudentClub.h"


int main()
{
	std::string p_name;
	std::string vp_name;
	std::string s_name;
	std::string t_name;
	std::string new_member;
	std::vector<Student*> member;
	Student* president = nullptr;
	Student* vicePresident = nullptr;
	Student* secretary = nullptr;
	Student* treasurer = nullptr;

	StudentClub mathletes;
	std::cout << "President: ";
	getline(std::cin, p_name);
	president = new Student(p_name);
	member.push_back(president);
	std::cout << std::endl;

	std::cout << "Vice-President: ";
	getline(std::cin, vp_name);
	/** If-else statement to check if VicePresident and President are the same person */
	if (vp_name == p_name) {
		vicePresident = president;
	}
	/** If-else statement to check if VicePresident is a different person */
	else {
		vicePresident = new Student(vp_name);
		member.push_back(vicePresident);
	}
	std::cout << std::endl;

	std::cout << "Secretary: ";
	getline(std::cin, s_name);
	/** If-else statement to check if Secretary and President are the same person */
	if (s_name == p_name) {
		secretary = president;
	}
	/** If-else statement to check if Secretary and VicePresident are the same person */
	else if (s_name == vp_name) {
		secretary = vicePresident;
	}
	/** If-else statement to check if Secretary is a different person*/
	else {
		secretary = new Student(s_name);
		member.push_back(secretary);
	}
	std::cout << std::endl;

	std::cout << "Treasurer: ";
	getline(std::cin, t_name);
	/** If-else statement to check if Treasurer and President are the same person */
	if (t_name == p_name) {
		treasurer = president;
	}
	/** If-else statement to check if Treasurer and VicePresident are the same person */
	else if (t_name == vp_name) {
		treasurer = vicePresident;
	}
	/** If-else statement to check if Treasurer and Secretary are the same person */
	else if (t_name == s_name) {
		treasurer = secretary;
	}
	/** If-else statement to check if Treasurer is a different person */
	else {
		treasurer = new Student(t_name);
		member.push_back(treasurer);
	}
	std::cout << std::endl;

	/** While loop for user to continue inputting member's name until user inputs "Q"
	*/
	while (new_member != "Q") {
		std::cout << "New Member (Q to quit): ";
		getline(std::cin, new_member);
		std::cout << std::endl;
		Student* newMember = new Student(new_member);
		member.push_back(newMember);
	}
	member.pop_back();




	mathletes = StudentClub(president, vicePresident, secretary, treasurer, member);

	std::cout << "MATHLETES( " << mathletes.num_members() << " total members )" << std::endl;
	std::cout << "      President: " << mathletes.get_president()->getName() << std::endl;
	std::cout << " Vice President: " << mathletes.get_vice_president()->getName() << std::endl;
	std::cout << "      Secretary: " << mathletes.get_secretary()->getName() << std::endl;
	std::cout << "      Treasurer: " << mathletes.get_treasurer()->getName() << std::endl;


	for (std::vector<Student*>::iterator it = member.begin(); it != member.end(); it++) {
		delete (*it);
	}
	member.clear();
	president = nullptr;
	vicePresident = nullptr;
	secretary = nullptr;
	treasurer = nullptr;

	return 0;
}
