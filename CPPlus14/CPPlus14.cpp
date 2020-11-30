#include <iostream>
#include "studenti.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;


int main()
{
	//数组
	Student ada[pupils]
		= { Student(quizzes)
	,Student(quizzes) ,
		Student(quizzes) };
	int i;
	for ( i = 0; i < pupils; i++)
	{
		set(ada[i],quizzes);
	}
	cout << "\nResults:";
	for ( i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done.\n";
	return 0;
}
void set(Student& sa, int n)
{
	cout << "Please enter the student's name: ";
	//调用内联函数
	getline(cin, sa);
	cout << "Please enter " << n << " quiz scores:\n";
	for (int i = 0; i < n; i++)
	{
		cin >> sa[i];
	}
	while (cin.get() !='\n')
	{
		continue;
	}
}
