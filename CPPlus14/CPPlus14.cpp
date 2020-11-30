#include <iostream>
#include "studenti.h"
#include "Worker0.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

const int LIM = 4;

int main()
{
	//数组
	//Student ada[pupils]
	//	= { Student(quizzes)
	//,Student(quizzes) ,
	//	Student(quizzes) };
	//int i;
	//for ( i = 0; i < pupils; i++)
	//{
	//	set(ada[i],quizzes);
	//}
	//cout << "\nResults:";
	//for ( i = 0; i < pupils; i++)
	//{
	//	cout << endl << ada[i];
	//	cout << "average: " << ada[i].Average() << endl;
	//}
	//cout << "Done.\n";
	/*————————————————————————————————*/
	Waiter bob("Bob Apple",314L,5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Waiter s_temp;

	Worker* pw[LIM] = { &bob,&bev,&w_temp,&s_temp };

	int i;
	for ( i = 2; i < LIM; i++)
	{
		pw[i]->Set();
	}

	for ( i = 0; i < LIM; i++)
	{
		pw[i]->Show();
		std::cout << std::endl;
	}

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
