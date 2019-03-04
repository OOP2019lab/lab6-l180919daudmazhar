#include "Header.h"

int student::counter = 0;
student::student()
{
	counter++;
	quizCapacity = 3;
	quizScore = new float[quizCapacity];
	quizTaken = 0;
	ID = counter;
	GPA = -1.0;

	cout << "Default constructor invoked for student id: " << ID << endl;
}

student::student(int quizcapacity, float gpa)
{
	counter++;
	quizCapacity = quizcapacity;
	GPA = gpa;
	quizScore = new float[quizCapacity];
	quizTaken = 0;
	ID = counter;

	cout << "Overloaded constructor invoked for student id: " << ID << endl;
}

student::student(const student &c)
{
	counter++;
	//copying variable data//
	GPA = c.GPA;
	ID = c.ID;
	quizCapacity = c.quizCapacity;
	quizTaken = c.quizTaken;

	quizScore = new float[quizCapacity];
	for (int i = 0; i < quizCapacity; i++)
	{
		quizScore[i] = c.quizScore[i];		//copying the array data//
	}

	cout << "Copy constructor invoked for student id: " << counter << endl;
}

student::~student()
{
	counter--;
	delete[]quizScore;
	quizScore = nullptr;
	quizCapacity = 0;
	quizTaken = 0;
	GPA = -1.0;

	cout << "Destructor invoked for student id: " << ID << endl;
}

void student::addquizscore(int score)
{
	if (quizTaken == quizCapacity)		//checks the capacity of the quizscore array//
		cout << "No more space to add score \n\n";
	else
	{
		quizScore[quizTaken] = score;
		quizTaken++;
	}
}

void student::setGPA(float gpa)
{
	GPA = gpa;
}

float student::getGPA() const
{
	return GPA;
}

void student::print() const
{
	cout << "Student ID is: " << ID << endl;
	cout << "GPA: " << GPA << endl;
	cout << "Quizzes Taken: " << quizTaken << endl;
	int quizno = 1;
	for (int i = 0; i < quizTaken; i++)
	{
		cout << "Quiz No " << quizno << " score: " << quizScore[i] << endl;
		quizno++;
	}

	cout << endl << endl;
}

bool student::compare(student &c)
{
	if (GPA > c.GPA)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void student::updatescore(int index, int score)
{

	if (index > 0 && index < quizCapacity)		//checks the validity of the quiz no entered//
		quizScore[index - 1] = score;

	else if (index >= quizCapacity)
		cout << "Quiz no : " << index << " not taken \n";
	else if (index <= 0)
		cout << "Invalid quiz no entered: " << endl;
}

