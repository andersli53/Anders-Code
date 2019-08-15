/**

Homework 5
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon

Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "Complex.h"

/** Default Constructor*/
Complex::Complex() : real(0.0), imagine(0.0)
{
}

/** Constructor to store the complex number by its real and imaginary parts
		@param real - a double argument for the real part
		@param imagine - a double argument for the imaginary part
*/
Complex::Complex(double real, double imagine) : real(real), imagine(imagine)
{
}

/** Accessor member function to get the real part
		@return - a double argument for real
*/
double Complex::getReal() const
{
	return real;
}

/** Accessor member function to get the imaginary part
		@return - a double argument for imagine
*/
double Complex::getImagine() const
{
	return imagine;
}

/** Overloading operator +
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator+(const Complex & c1, const Complex & c2)
{
	double real = c1.getReal() + c2.getReal();
	double imagine = c1.getImagine() + c2.getImagine();

	Complex sum(real, imagine);

	return sum;
}

/** Overloading operator -
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator-(const Complex & c1, const Complex & c2)
{
	double real = c1.getReal() - c2.getReal();
	double imagine = c1.getImagine() - c2.getImagine();

	Complex diff(real, imagine);

	return diff;
}

/** Overloading operator *
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator*(const Complex & c1, const Complex & c2)
{
	double real = c1.getReal() * c2.getReal() - c1.getImagine() * c2.getImagine();
	double imagine = c1.getImagine() * c2.getReal() + c1.getReal() * c2.getImagine();

	Complex product(real, imagine);

	return product;
}

/** Overloading operator /
		@param c1 - const Complex object that passed by reference
		@param c2 - const Complex object that passed by reference
		@return - Complex object
*/
Complex operator/(const Complex & c1, const Complex & c2)
{
	double real = (c1.getReal() * c2.getReal() + c1.getImagine() * c2.getImagine()) / (pow(c2.getReal(), 2) + pow(c2.getImagine(), 2));
	double imagine = (c1.getImagine() * c2.getReal() - c1.getReal() * c2.getImagine()) / (pow(c2.getReal(), 2) + pow(c2.getImagine(), 2));

	Complex quotient(real, imagine);

	return quotient;
}
