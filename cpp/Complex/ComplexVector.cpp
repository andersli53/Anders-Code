/**

Homework 5
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon

Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "ComplexVector.h"
#include "Complex.h"

/** Default Constructor*/
ComplexVector::ComplexVector()
{
}

/** Constructor to store 4 complex numbers
		@param c1 - Complex object
		@param c2 - Complex object
		@param c3 - Complex object
		@param c4 - Complex object
*/
ComplexVector::ComplexVector(Complex& c1, Complex& c2, Complex& c3, Complex& c4)
{
	complexNumber.push_back(c1);
	complexNumber.push_back(c2);
	complexNumber.push_back(c3);
	complexNumber.push_back(c4);
}

/** Mutator member function to set single complex number
		@param c1 - Complex object
*/
void ComplexVector::setVector(Complex& c1)
{
	complexNumber.push_back(c1);
}

/** Mutator member function to print the first 6 terms of the equation
		@param start - an int argument for the start of the recursive equation
		@param end - an int argument for the end of the recursive equation
		@param c - Complex object passed by reference
*/
void ComplexVector::recursion(int start, int end, Complex& c)
{
	Complex k1 = Complex(2 * start, 3 * start);
	Complex k2 = Complex(7, 5 * pow(start, 2));
	Complex fn;
	ComplexVector vn;
	
	/** If else statement for the base case*/
	if (start == 0) {
		setVector(c);
		start+=1;
		recursion(start, end, c);
	}
	/** If else statement when it is not the base case*/
	else if (start<=end && start>0) {
		fn = (c/k2)*k1;

		setVector(fn);
		start+=1;
		recursion(start, end, fn);
	}



}
/** Overloading operator <<
		@param os - ostream object passed by reference
		@param c2 - const Complex object that passed by reference
		@return - ostream output
*/
std::ostream & operator<<(std::ostream & os, const ComplexVector & v)
{
	os << "{ " << std::setw(3);
	/** For loop to go through every elements in the vector*/
	for (size_t i = 0; i < v.complexNumber.size() - 1; i++) {
		/** If else statement to test if imaginary part > 0 and modify the combined complex number*/
		if (v.complexNumber[i].getImagine() > 0) {
			os << std::setw(3) << v.complexNumber[i].getReal() << std::setw(3) << " + " << std::setw(3) << v.complexNumber[i].getImagine() << "i" << std::setw(3) << " , ";
		}
		/** If else statement to test if imaginary part < 0 and modify the combinde complex number*/
		else if (v.complexNumber[i].getImagine() <= 0) {
			os << std::setw(3) << v.complexNumber[i].getReal() << std::setw(3) << " - " << std::setw(3) << v.complexNumber[i].getImagine() * -1 << "i" << std::setw(3) << " , ";
		}
	}
	/** If else statement to test if imaginary part > 0 and modify the combined complex number*/
	if (v.complexNumber[v.complexNumber.size() - 1].getImagine() > 0) {
		os << v.complexNumber[v.complexNumber.size() - 1].getReal() << " + " << v.complexNumber[v.complexNumber.size() - 1].getImagine() << "i" << " }";
	}
	/** If else statement to test if imaginary part < 0 and modify the combined complex number*/
	else if (v.complexNumber[v.complexNumber.size() - 1].getImagine() < 0) {
		os << v.complexNumber[v.complexNumber.size() - 1].getReal() << " - " << v.complexNumber[v.complexNumber.size() - 1].getImagine() * -1 << "i" << " }";
	}
	
	return os;
}
