/**

Homework 5
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
#include <vector>
#include <cmath>
#include <iomanip>
#include "Complex.h"
#include "ComplexVector.h"


int main()
{
	Complex c1(2.0, 4.0);
	Complex c2(3.0, 5.0);
	Complex c3(-1.0, -3.0);
	Complex c4(8.0, 10.0);
	Complex c5(-10.0, 3.5);
	Complex c6(4.0, 7.3);
	Complex c7(2.0, -8.0);
	Complex c8(10.0, -142.0);

	ComplexVector v1(c1, c2, c3, c4);
	ComplexVector v2(c5, c6, c7, c8);

	Complex a1 = c1 + c5;
	Complex a2 = c2 + c6;
	Complex a3 = c3 + c7;
	Complex a4 = c4 + c8;

	ComplexVector v3(a1, a2, a3, a4);

	Complex s1 = c1 - c5;
	Complex s2 = c2 - c6;
	Complex s3 = c3 - c7;
	Complex s4 = c4 - c8;

	ComplexVector v4(s1, s2, s3, s4);

	Complex m1 = c1 * c5;
	Complex m2 = c2 * c6;
	Complex m3 = c3 * c7;
	Complex m4 = c4 * c8;

	ComplexVector v5(m1, m2, m3, m4);

	Complex d1 = c1 / c5;
	Complex d2 = c2 / c6;
	Complex d3 = c3 / c7;
	Complex d4 = c4 / c8;

	ComplexVector v6(d1, d2, d3, d4);

	std::cout << "     v1 = " << std::fixed << std::setprecision(1) << v1 << std::endl;
	std::cout << "     v2 = " << std::fixed << std::setprecision(1) << v2 << std::endl;
	std::cout << "v1 + v2 = " << std::fixed << std::setprecision(1) << v3 << std::endl;
	std::cout << "v1 - v2 = " << std::fixed << std::setprecision(1) << v4 << std::endl;
	std::cout << "v1 * v2 = " << std::fixed << std::setprecision(1) << v5 << std::endl;
	std::cout << "v1 / v2 = " << std::fixed << std::setprecision(1) << v6 << std::endl;
	std::cout << std::endl;

	ComplexVector vn;
	Complex f1(1.0, 1.0);
	vn.recursion(0, 5, f1);

	std::ofstream fout;
	fout.open("ComplexSequence.txt");
	/** If else statement to check fail state of ofstream*/
	if (fout.fail()) {
		std::cout << "ComplexSequence.txt failed to open";
	}
	/** If else statement to show successfulness of ofstream*/
	else {
		std::cout << "Writing Complex Sequence to File ...Done" << std::endl << std::endl;
	}

	fout << vn;

	fout.close();
	return 0;
}
