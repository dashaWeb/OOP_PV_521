#include <iostream>
#include "FwdList.h"
using namespace std;


int main()
{

	FwdList<int> list;

	for (size_t i = 0; i < 10; i++)
	{
		list.addHead(rand() % 50);
		list.print();
	}

	cout << endl;
	for (size_t i = 0; i < 11; i++)
	{
		list.removeHead();
		list.print();
	}

	cout << "Test removeHead" << endl;
}

