#include <iostream>
#include <algorithm>

const unsigned MARKS_COUNT = 4;
struct Student
{
    std::string name;
    unsigned marks[MARKS_COUNT]{ 0 };
};

int getAverageMark(const Student& student)
{
    int summ = 0;
    for (int i = 0; i < MARKS_COUNT; i++)
    {
        summ += student.marks[i];
    }

    return std::ceil(summ / MARKS_COUNT);
}

bool compareByAverageMark(
    const Student& st1,
    const Student& st2)
{
    const int average1 = getAverageMark(st1);
    const int average2 = getAverageMark(st2);

    return average1 > average2;
}

Student* getBestStudent(Student students[], int size)
{
    if (size <= 0)
    {
        return nullptr;
    }

    int maxAverage = 0;
    Student* bestStudent = nullptr;
    for (int i = 0; i < size; i++)
    {
        int currentAverage = getAverageMark(students[i]);
        if (currentAverage > maxAverage)
        {
            maxAverage = currentAverage;
            bestStudent = &(students[i]);
        }
    }

    return bestStudent;
}

int countAboveMark(Student students[], int size, int threshold)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (getAverageMark(students[i]) > threshold)
        {
            count++;
        }
    }

    return count;
}

Student* getBestStudents(
    Student studentsIn[],
    int inSize,
    unsigned& outSize,
    unsigned percentage
)
{
    std::sort(studentsIn, studentsIn + inSize, compareByAverageMark);

    outSize = inSize / 100.0f * percentage;

    Student* studentsOut = new Student[outSize];    //array of Student
    for (int i = 0; i < outSize; i++)
    {
        studentsOut[i] = studentsIn[i];
    }

    return studentsOut;
}

int main()
{
    Student student{ "Ivan", {90, 100, 100, 60} };
    Student student2{ "Oleh", {70, 90, 80, 10} };
    Student student3{ "Dariia", {100, 100, 100, 100} };
    Student student4{ "Oleksii", {90, 80, 100, 100} };
    Student student5{ "Kristina", {90, 80, 100, 100} };

    const int STUDENTS_COUNT = 5;
    Student students[5]{student, student2, student3, student4, student5};

    std::sort(students, students + STUDENTS_COUNT, compareByAverageMark);

    std::cout << "Average mark of " << student.name <<
        ": " << getAverageMark(student);

    Student* bestStudent = getBestStudent(students, STUDENTS_COUNT);

    if (bestStudent != nullptr)
    {
        std::cout << "Best student is: " << bestStudent->name << std::endl;
    }

    std::cout << "Number of students with cool shiny Diploma: " <<
        countAboveMark(students, STUDENTS_COUNT, 90) << std::endl;

    Student* bestStudents = nullptr; //array of students

    unsigned int outSize = 0;
    bestStudents = getBestStudents(students, STUDENTS_COUNT, outSize, 50);

    std::cout << "Best 50% students: \n";
    for (int i = 0; i < outSize; i++)
    {
        std::cout << bestStudents[i].name << std::endl;
    }

    delete [] bestStudents; //this array was dynamically allocated on HEAP, delete it

}
