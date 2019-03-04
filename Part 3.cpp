
#include "Header.h"
#include <iostream>
#include <string>
using namespace std;

void print(student *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i].print();
	}
}

student* gpaabove2(student *a, int size)
{
	int newsize = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i].getGPA() > 2.0)		//calculating the size of the new array//
		{
			newsize++;
		}
	}

	student *temp = new student[newsize];
	for (int i = 0, j = 0; i < newsize; i++)
	{
		if (a[i].getGPA() > 2.0)
		{
			//temp[j].setGPA(a[i].getGPA());
			temp[j] = a[i];
			j++;
		}
	}
	return temp;
}

student *sort(student *a, int size)
{
	float temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{									//Bubble sort algorithm//
			if (a[j].getGPA() < a[j + 1].getGPA())
			{
				temp = a[j].getGPA();
				a[j].setGPA(a[j + 1].getGPA());
				a[j + 1].setGPA(temp);
			}
		}
	}
	return a;
}
int main()
{

	student arr1[3] = { (student (3, 2.0)), (student (3, 3.0)), (student(4, 2.33)) };

	arr1[0].addquizscore(1);
	arr1[0].addquizscore(4);
	arr1[0].addquizscore(10);

	arr1[1].addquizscore(10);
	arr1[1].addquizscore(4);
	arr1[1].addquizscore(9);

	arr1[2].addquizscore(9);
	arr1[2].addquizscore(8);
	arr1[2].addquizscore(7);
	
	/*	DYNAMIC 
	
	student *arr2 = new student[4];	//I have an issue here. When I create this dynamic array, default constructors are invoked.//
	arr2[0] = student(3, 2.0);	//When I execute this statement, overloaded constructor is called for the same index of the array but it is destroyed automatically so I cannot print it further//
	arr2[1] = student(3, 3.0);
	arr2[2] = student(4, 2.33);
	//arr2[3] = student(4, 1.0);

	arr2[0].addquizscore(11);
	arr2[0].addquizscore(4);
	arr2[0].addquizscore(10);


	arr2[1].addquizscore(10);
	arr2[1].addquizscore(4);
	arr2[1].addquizscore(9);

	arr2[2].addquizscore(9);
	arr2[2].addquizscore(8);
	arr2[2].addquizscore(7);

	arr2[3].addquizscore(2);
	arr2[3].addquizscore(4);
	
	*/

	print(arr1, 3);
	cout << endl;
	//print(arr2, 4);

	student *arr3;
	arr3 = gpaabove2(arr1, 3);
	print(arr3, 2);
	

	student *arr4;
	arr4 = sort(arr1, 3);
	print(arr4, 3);
	
	return 0;
}
