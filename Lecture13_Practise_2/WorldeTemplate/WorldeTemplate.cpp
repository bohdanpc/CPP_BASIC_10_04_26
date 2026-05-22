#include <iostream>
#include <string>
#include <fstream>

const int MAX_WORDS = 100;
const int WORD_LEN = 5;
std::string g_Lines[MAX_WORDS];

void readLines()
{
	//#TODO
	//Open words.txt file
	//read words into g_Lines line by line
	//e.g.: 
	// file >> g_Lines[i];
}

std::string generateRandomWord()
{
	//#TODO
	//Return random word from the g_Lines array

	return "";
}

std::string compareWords(const std::string& userGuess, const std::string& correctWord)
{
	//#TODO
	
	std::string result = "*****";
	//compare two words, if the letter is present, set it instead of '*' symbol in correct position
	// e.g.: result[i] = correctWord[i];
	//

	return result;
}

int main()
{
	readLines();

	std::string userChoice;
	std::string randomWord = generateRandomWord();

	//While user doesn't enter valid word:
	while (userChoice != randomWord)	//it's ok to compare std::string objects directly
	{
		//Current Choice
		std::cout << "Enter: ";
		std::cin >> userChoice;

		std::string currentResult = compareWords(userChoice, randomWord);

		//Current result
		std::cout << "Result: " << currentResult << std::endl << std::endl;
	}

	//#TODO: Output number of tries
}
