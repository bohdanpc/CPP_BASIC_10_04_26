#include <iostream>
#include <fstream>
#include <string>

constexpr unsigned DAYS_PER_YEAR = 366;
float g_Temperatures[DAYS_PER_YEAR] { 0 };
int g_LastReadYear = -1;
int lastTimeRead = 2383010;


int readYear()
{
    int year = 0;
    std::cout << "Enter year to analyze: ";
    std::cin >> year;

    return year;
}

enum class ErrorCode
{
    Success,
    MissingFile,
    AccessDenied,
};


ErrorCode readTemperature(int year)
{
    if (year == g_LastReadYear)
    {
        return ErrorCode::Success;
    }


    //read metadata from file MODIFIED
    //

    std::fstream file;

    //temperatures_2025.txt
    //temperatures_2024.txt
    std::string fileName;
    fileName = "temperatures_";
    fileName += std::to_string(year);
    fileName += ".txt";

    file.open(fileName, std::ios::in);

    if (!file.is_open())
    {
        return ErrorCode::MissingFile;
    }

    for (int i = 0; i < DAYS_PER_YEAR && !file.eof(); i++)
    {
        file >> g_Temperatures[i];
    }

    file.close();

    g_LastReadYear = year;
    return ErrorCode::Success;
}


void launcAveragePerYear()
{
    const int year = readYear();
    readTemperature(year);

    float average = 0;

    for (int i = 0; i < DAYS_PER_YEAR; i++)
    {
        average += g_Temperatures[i];
    }

    average /= DAYS_PER_YEAR;

    std::cout << "Average temperature in " << year << ": " << average << std::endl;
}

void printTemperatures()
{
    for (int i = 0; i < DAYS_PER_YEAR; i++)
    {
        std::cout << g_Temperatures[i] << " ";
    }
}


float findMax(float* temperatures)
{
    float max = temperatures[0];
    //nlogN
    //N -> max
    for (int i = 1; i < DAYS_PER_YEAR; i++)
    {
        if (temperatures[i] > max)
        {
            max = temperatures[i];
        }
    }

    return max;
}

void launchMaxPerYear()
{
    int year = readYear();

    ErrorCode status = readTemperature(year);
    if (status == ErrorCode::MissingFile)
    {
        std::cout << "Failed to read file for year " << year << "\n";
        return;
    }

    float max = findMax(g_Temperatures);

    //limit number of rational decimals
    std::cout << "Max per year " << year << ": " << max << std::endl << std::endl;
}

void launchMinPerYear()
{
    //#TODO

    std::cout << "launch min\n";
}

//-12 -5 -10 12 10 9 10 //365
int main()
{
    while(true)
    {
        std::cout << "------ SELECT YOUR ANALYZE----------\n\n";
        std::cout << "1 - Average per year\n";
        std::cout << "2 - Max per Year\n";
        std::cout << "3 - Min per year\n";
        std::cout << "-1 - exit\n";

        int choice = 0;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            launcAveragePerYear();
            break;
        case 2:
            launchMaxPerYear();
            break;
        case 3:
            launchMinPerYear();
            break;
        case -1:
            return 0;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    }
}