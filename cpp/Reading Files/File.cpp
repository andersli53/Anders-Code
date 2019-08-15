/**

Homework 3
Name: Li, Chak Yin (Anders)
ID: 704950093
PIC 10B Falcon


Honor pledge:
I have not given, received, or used any unauthorized assistance

Signature: Anders Li


*/
#include "File.h"
/** Constructor for File
		@param filename - a string argument for the name of the file
*/
File::File(std::string filename) :filename(filename)
{
}

/** Mutator member function to count the number of characters, words, lines
*/
void File::count()
{
	std::string line;
	char character;
	std::string word;
	fin.open(filename);

	/** If statement to check whether the file is failed to open
	*/
	if (fin.fail()) {
		std::cout << filename << " failed to open." << std::endl;
	}

	fin.seekg(0, std::ios::end);
	numChar = fin.tellg();
	fin.seekg(0, std::ios::beg);

	/** While loop to get the next line until the end of file
	*/
	while (getline(fin, line)) {
		numLine++;
		std::istringstream instr(line);
		/** While loop to get the next character until the end of file
		*/
		while (instr.get(character)) {
			/** If statement to check whether the next character is a alphabet*/
			if ('A' <= character && character <= 'Z' || 'a' <= character && character <= 'z') {
				numWord++;
				instr.unget();
				instr >> word;
			}
		}
	}



	fin.close();
}

/** Mutator member function to print out the characters and words of each file, and which file has less lines
		@param file1 - a File class that is passed by reference
		@param file2 - a File class that is passed by reference
*/
void File::print(const File& file1, const File& file2)
{
	fout.open("Properties.txt");

	/** If statement to check whether "Properties.txt" fails to open
	*/
	if (fout.fail()) {
		std::cout << "Properties.txt failed to open." << std::endl;
	}

	fout << "File Name: " << file1.getName() << std::endl;
	fout << "Number of characters: " << file1.getNumChar() << std::endl;
	fout << "Number of words: " << file1.getNumWord() << std::endl;

	fout << std::endl;

	fout << "File Name: " << file2.getName() << std::endl;
	fout << "Number of characters: " << file2.getNumChar() << std::endl;
	fout << "Number of words: " << file2.getNumWord() << std::endl;

	fout << std::endl;

	/** If statement to check whether file2 has less lines than file1
	*/
	if (file1 > file2) {
		fout << "The file named \"" << file2.getName() << "\" has less lines than \""
			<< file1.getName() << "\"." << std::endl;
	}
	/** If statement to check whether two files have the same number of lines
	*/
	else if (file1 == file2) {
		fout << "The file named \"" << file1.getName() << " and \"" << file2.getName()
			<< "\" has the same number of lines." << std::endl;
	}
	/** If statement to check whether file1 has less lines than file2
	*/
	else {
		fout << "The file named \"" << file1.getName() << "\" has less lines than \""
			<< file2.getName() << "\"." << std::endl;
	}

}

/** Mutator member function to get the difference in number of lines
		@return - an int for the difference in number of lines
*/
int File::difference(const File & file2) const
{
	return numLine - file2.numLine;
}

/** Accessor member function to get the name of file
		@return - a string for the name of file
*/
std::string File::getName() const
{
	return filename;
}

/** Accessor member function to get the number of characters of the file
		@return - an int for the number of characters
*/
int File::getNumChar() const
{
	return numChar;
}

/** Accessor member function to get the number of words of the file
		@return - an int for the number of words
*/
int File::getNumWord() const
{
	return numWord;
}

/** Accessor member function to get the number of lines of the file
		@return - an int for the number of lines
*/
int File::getNumLine() const
{
	return numLine;
}

/** Operator overloading to check if file1 has fewer lines than file2
		@return - a bool for the comparison between number of lines of two files
*/
bool operator>(const File & file1, const File & file2)
{
	return file2.difference(file1) < 0;
}

/** Operator overloading to check if file1 has the same lines as file2
		@return - a bool for the comparison between number of lines of two files
*/
bool operator==(const File & file1, const File & file2)
{
	return file1.difference(file2) == 0;
}
