#include <iostream>
#include <fstream>

void readFileByChars()
{
	std::fstream fileToRead;
	fileToRead.open("read.txt", std::ios::in);

	if (!fileToRead.is_open())
	{
		return;
	}

	while (!fileToRead.eof())
	{
		const char ch = fileToRead.get();

		std::cout << ch;
	}
}

void read_file_by_lines()
{
	std::fstream fileToRead;
	fileToRead.open("read.txt", std::ios::in);

	if (!fileToRead.is_open())
	{
		return;
	}


	int number = 0;
	char line[64];

	while (!fileToRead.eof())
	{
		fileToRead.getline(line, 64, '\n');

		std::cout << "Student #" << number << ": " << line << std::endl;

		number++;
	}

	fileToRead.close();
}

void writeToFile() 
{
	std::fstream file;
	file.open("E:\\COURSE_CPP\\CPP_BASIC_10_04_26\\Lecture13_Practise_2\\write.txt", std::ios::app);	//append

	if (!file.is_open())
	{
		return;
	}

	file << false;

	file.close();
}


void readFile()
{

	std::fstream fileToRead;
	fileToRead.open("read.txt", std::ios::in);

	if (!fileToRead.is_open())
	{
		std::cout << "COULDN'T OPEN\n";
		return;
	}

	int currentNumber = 0;
	while (!fileToRead.eof())
	{
		fileToRead >> currentNumber;
		std::cout << currentNumber << " ";
	}

	std::cout << "FILE WAS READ SUCCESSFULLY\n";
}

int main()
{
	writeToFile();

	return 0;
}

