#include <iostream>
#include <string>
#include <algorithm>

//TOO long declaration and cubersome, not clean interface
void printStudent(const std::string* names, int size, unsigned marks[], unsigned ages[])
{

}

struct University
{
	std::string name;
	unsigned foundationYear;
	std::string address;
};

struct Student
{
	//Поля, field
	std::string name = "";	//40 bytes
	unsigned mark = 60;	//4 bytes
	unsigned age = 14;	//4 bytes

	University* university;	//8 bytes
};

//function overloading
void print(const University& university)
{ 
	std::cout << "Info about university: \n";
	std::cout << "Name: " << university.name;
	std::cout << ", Address: " << university.address;
	std::cout << ", foundationYear: " << university.foundationYear;
}

void print(const Student& studentArg)
{
	//pass by reference, using only 8 bytes.
	//Copy by value will require sizeof(Student) additional memory
	std::cout << "Student " << studentArg.name;
	std::cout << ", mark " << studentArg.mark;
	std::cout << ", age: " << studentArg.age << std::endl;

	print(*(studentArg.university));
}

void updateAge(Student& student, unsigned newAge)
{
	student.age = newAge;
}

bool compareByMarks(const Student& st1, const Student& st2)
{
	return st1.mark > st2.mark;
}

bool compareByAge(const Student& st1, const Student& st2)
{
	if (st1.age == st2.age)
	{
		return compareByMarks(st1, st2);
	}

	return st1.age < st2.age;
}


struct Player
{
	std::string name;

	Player* teammate;	//cross referencing in ok in structures
};


void print(Student students[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		print(students[i]);
		std::cout << std::endl;
	}
}

int main()
{
	Player p1{ "Bohdan" };
	Player p2{ "Oleksii" };

	p1.teammate = &p2;
	p2.teammate = &p1;

	std::cout << "Player 1 " << p1.name << " is playing with Player 2 " << p1.teammate->teammate->teammate->teammate << std::endl;

	University kpi{ "KPI National University", 1898, "Beresteyskiy prospekt 25" };
	Student* newStudent = new Student{"Johny", 60, 25, &kpi};
	Student* newStudent2 = new Student{ "Jack", 70, 35, new University{"Mohylyanka", 1360, "Podil"}};

	const unsigned STUDENTS_COUNT = 3;
	Student students[STUDENTS_COUNT] = { *newStudent , *newStudent2, Student{"Sergii", 75, 19, &kpi} };

	std::sort(students, students + STUDENTS_COUNT, compareByMarks);
	std::cout << "-----------------AFTER SORT------------------\n";
	print(students, STUDENTS_COUNT);

	std::sort(students, students + STUDENTS_COUNT, compareByAge);
	std::cout << "\n-----------------AFTER SORTING 2---------------\n";
	print(students, STUDENTS_COUNT);

	newStudent->university = &kpi;
	Student st2;
	st2.university = &kpi;

	//Can access every level of indirection separetely
	University* university = st2.university;
	std::string address = university->address;
	std::cout << address;

	delete newStudent;
	delete newStudent2;
}
