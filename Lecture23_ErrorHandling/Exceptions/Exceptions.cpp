#include <iostream>
#include <fstream>
#include <vector>

std::string readFileName()
{
    std::string filename;
    std::cin >> filename;

    if (filename.empty())   //will be propagated into main
        throw std::invalid_argument{ "Failed reading filename from user" };

    return filename;
}

std::vector<std::string> readFile()
{
    std::string fileNameStr = readFileName();

    std::fstream file;
    file.open(fileNameStr, std::ios::in);

    if (!file.is_open())
        throw std::runtime_error("Failed openning file");

    if (file.eof())
        throw std::length_error("File is empty");

    std::vector<std::string> words;

    int wordsCount = 0;
    file >> wordsCount;

    if (wordsCount <= 0)
        throw std::length_error("No words present in the file");

    words.reserve(wordsCount);

    while (!file.eof())
    {
        std::string word;
        file >> word;
        words.push_back(word);
    }

    return words;
}

int main()
{
    try
    {
        std::vector<std::string> words = readFile();
    }
    catch (const std::invalid_argument& invalidArgException)
    {
        std::cout << "Failed parsing file with invalid arg exception\n";
        std::cout << "Exception msg: " << invalidArgException.what();
    }
    catch (const std::runtime_error& runtimeGeneralError)
    {

    }
    catch (int exceptionInt)
    {

    }
    catch (...)
    {
        std::cout << "Uknown error thrown\n";
    }
}
