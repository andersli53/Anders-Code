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
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
class Complex {
public:
	/** Default Constructor*/
	Complex();

	/** Constructor to store the complex number by its real and imaginary parts
			@param real - a double argument for the real part
			@param imagine - a double argument for the imaginary part
	*/
	Complex(double real, double imagine);

	/** Accessor member function to get the real part
			@return - a double argument for real
	*/
	double getReal() const;

	/** Accessor member function to get the imaginary part
			@return - a double argument for imagine
	*/
	double getImagine() const;


private:
	double real;
	double imagine;
};

/** Overloading operator +
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator+(const Complex& c1, const Complex& c2);

/** Overloading operator -
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator-(const Complex& c1, const Complex& c2);

/** Overloading operator *
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator*(const Complex& c1, const Complex& c2);

/** Overloading operator /
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator/(const Complex& c1, const Complex& c2);

#endif // !COMPLEX_H
