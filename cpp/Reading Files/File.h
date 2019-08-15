/**

Homework 3
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#ifndef FILE_H
#define FILE_H



class File {
public:
	std::ifstream fin;
	std::ofstream fout;
	/** Constructor for File
			@param filename - a string argument for the name of the file
	*/
	File(std::string filename);

	/** Mutator member function to count the number of characters, words, lines
	*/
	void count();

	/** Mutator member function to print out the characters and words of each file, and which file has less lines
			@param file1 - a File class that is passed by reference
			@param file2 - a File class that is passed by reference
	*/
	void print(const File& file1, const File& file2);

	/** Mutator member function to get the difference in number of lines
	@return - an int for the difference in number of lines
	*/
	int difference(const File& file2) const;

	/** Accessor member function to get the name of file
			@return - a string for the name of file
	*/
	std::string getName() const;

	/** Accessor member function to get the number of characters of the file
			@return - an int for the number of characters
	*/
	int getNumChar() const;

	/** Accessor member function to get the number of words of the file
			@return - an int for the number of words
	*/
	int getNumWord() const;

	/** Accessor member function to get the number of lines of the file
			@return - an int for the number of lines
	*/
	int getNumLine() const;

private:
	std::string filename;
	int numChar;
	int numWord;
	int numLine;
};

bool operator> (const File& file1, const File& file2);
bool operator== (const File& file1, const File& file2);

#endif // !FILE_H

