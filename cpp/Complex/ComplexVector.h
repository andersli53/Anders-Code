/**

Homework 5
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon

Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#pragma once
#ifndef COMPLEXVECTOR_H
#define COMPLEXVECTOR_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Complex.h"
class ComplexVector {
public:
	/** Default Constructor*/
	ComplexVector();

	/** Constructor to store 4 complex numbers
			@param c1 - Complex object passed by reference
			@param c2 - Complex object passed by reference
			@param c3 - Complex object passed by reference
			@param c4 - Complex object passed by reference
	*/
	ComplexVector(Complex& c1, Complex& c2, Complex& c3, Complex& c4);

	/** Mutator member function to set single complex number
			@param c1 - Complex object
	*/
	void setVector(Complex& c1);

	/** Mutator member function to print the first 6 terms of the equation
			@param start - an int argument for the start of the recursive equation
			@param end - an int argument for the end of the recursive equation
			@param c - Complex object passed by reference
	*/
	void recursion(int start, int end, Complex& c);

	/** Overloading operator <<
			@param os - ostream object passed by reference
			@param c2 - const Complex object that passed by reference
			@return - ostream output
	*/
	friend std::ostream& operator <<(std::ostream& os, const ComplexVector& v);
	
private:
	std::vector<Complex> complexNumber;
};



#endif // !COMPLEXVECTOR_H

