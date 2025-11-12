#include <iostream>
#include "DList.h"
using namespace std;



int main()
{
	DList<int> list;

	list.AddHead(11);
	list.print();
	list.printR();

	cout << endl;

	for (size_t i = 0; i < 5; i++)
	{
		list.AddHead(rand() % 10); 
		list.print();
		list.printR();
		cout << endl;
	}

	for (size_t i = 0; i < 5; i++)
	{
		list.AddTail(rand() % 10);
		list.print();
		list.printR();
		cout << endl;
	}

	cout << "\n\n Test addTail" << endl;
	DList<int> list2;

	for (size_t i = 0; i < 5; i++)
	{
		list2.AddTail(rand() % 10);
		list2.print();
		list2.printR();
		cout << endl;
	}

	cout << "\n\n Test remove Head" << endl;
	list.print();
	cout << endl;

	while (!list.isEmpty())
	{
		list.removeHead();
		list.print();
		list.printR();
		cout << endl;
	}
	system("cls");
	cout << "\n\n Test remove Tail" << endl;

	list2.print();
	cout << endl;

	while (!list2.isEmpty())
	{
		list2.removeTail();
		list2.print();
		list2.printR();
		cout << endl;
	}

	system("cls");
	cout << "\n\n Test remove Data" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		list.AddHead(rand() % 20);
	}
	list.print();

	cout << endl;
	size_t i = 0;
	while (list.removeByData(11)) i++;

	list.print();
	list.printR();
	cout << "Delete Nodes " << i << endl;


}
