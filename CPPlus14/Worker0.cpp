#include "Worker0.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::Set() 
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter worker' ID: ";
	cin >> id;
	//需要输入一个换行结束
	while (cin.get()!='\n')
	{
		continue;
	}
}

void Worker::Show() const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}

void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get()!='\n')
	{
		continue;
	}
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << "\n";
}


//Singer
char *Singer::pv[] = {(char*)""};
