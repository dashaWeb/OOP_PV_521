#include <iostream>
#include "MyStack.h"
using namespace std;

template<typename T>
struct Pair
{
	T data;
	int priority;
};


template <typename T>
class QueuePr
{
private:

	Pair<T>* queue = nullptr;
};


template <typename T>
void print(const MyStack<T>& cont, const string& text = "")
{
	cout << text;
	for (size_t i = 0; i < cont.size(); i++)
	{
		cout << cont[i] << "\t";
	}
	cout << endl;
}


int main()
{
	MyStack<int> stack(5, 5);
	for (size_t i = 0; i < 11; i++)
	{
		stack.push(rand() % 50);
		cout << "Capacity :: " << stack.getCapacity() << endl;
		print(stack, "Print Stack :: ");
	}
}

