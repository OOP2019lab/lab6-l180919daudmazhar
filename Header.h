#include <iostream>
using namespace std;

class student {

private:
	static int counter;
	float *quizScore;
	int quizCapacity, quizTaken, ID;
	float GPA;

public:
	student();  //default//
	student(int, float);  //overloaded//
	student(const student &); //copy//
	~student(); //destructor//
	void addquizscore(int);
	void setGPA(float);
	float getGPA() const;
	void print() const;
	bool compare(student &);
	void updatescore(int, int);

};
