/**

Homework 3
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "File.h"

int main()
{
	std::string fileName1, fileName2;
	
	std::cout << "Enter the name of File 1: ";
	getline(std::cin, fileName1);
	std::cout << std::endl;

	std::cout << "Enter the name of File 2: ";
	getline(std::cin, fileName2);
	std::cout << std::endl;

	File file1 = File(fileName1); 
	File file2 = File(fileName2);

	file1.count();
	file2.count();

	file1.print(file1, file2);

	return 0;
}


