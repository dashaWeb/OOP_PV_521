#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <string>

#include <algorithm>
using namespace std;


template <typename ContType>
void print(const ContType cont, const string& prompt = "")
{
	cout << "\n\n" << prompt << endl;
	for (auto& i : cont)
	{
		cout << i << "\t";
	}
	cout << endl;
}



bool div3(int number)
{
	return number % 3 == 0;
}


int inc(int el)
{
	return el + 1;
}

int main()
{
	const size_t size = 5;
	array<int, size> arr{ 10,33,4,-5,77 };

	cout << "\n\nPrint container array [] :: \t ";
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	cout << "\n\nPrint container array [] :: \t ";
	for (array<int, size>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;


	cout << "\n\nPrint container reverse array [] :: \t ";
	for (array<int, size>::reverse_iterator /*auto*/ it = arr.rbegin(); it != arr.rend(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;

	//cout << "getValue[5] :: " << arr.at(5) << endl; error range index

	auto it = min_element(arr.begin(), arr.end());
	cout << "Min in array :: " << *it << endl;
	*it *= -1;
	print(arr, "After modifuing min (*-1)");

	it = max_element(arr.begin(), arr.end());
	cout << "Max in array :: " << *it << endl;

	vector<int> v(arr.rbegin(), arr.rend());
	print(v, "Vector ( as reverse copy of arr)");
	v.push_back(333);
	v.insert(v.begin() + 2, 777);
	v.insert(v.begin() + v.size() / 2, { 1,2,3,4 });
	print(v, "Vector ( after push and insert)");


	deque<int> d{ v.begin(), v.begin() + v.size() / 2 };

	d.resize(v.size(), -1);
	print(d, "Deque ( resize)");

	copy(v.rbegin(), v.rend() - v.size() / 2, d.begin() + d.size() / 2);
	print(d, "Deque ( copy 2-nd hala of vector)");

	d.push_back(222);
	print(d, "Deque ( after push)");

	deque<int>::iterator itF = find(d.begin(), d.end(), 4);
	while (itF != d.end())
	{
		cout << "Found value :: " << 4 << " in index " << itF - d.begin() << endl;
		itF = find(itF + 1, d.end(), 4);
	}
	cout << "\nCount of value " << 4 << " = " << count(d.begin(), d.end(), 4) << endl;

	itF = find_if(d.begin(), d.end(), div3);
	while (itF != d.end())
	{
		cout << "Found value ::  in index " << itF - d.begin() << endl;
		itF = find_if(itF + 1, d.end(), div3);
	}
	
	print(d, "Deque ");
	transform(d.begin(), d.end(), d.begin(), inc);
	print(d, "Deque ( after transform)");

	sort(d.begin(), d.end());
	print(d, "Deque ");

	//sort(d.rbegin(), d.rend());
	sort(d.begin(), d.end(),greater<int>());
	print(d, "Deque ");

	vector<int> vect{ 1,2,3,4,5 };
	print(vect, "Print vector");
	cout << "Size :: " << vect.size() << "\t Capacity :: " << vect.capacity() << endl;

	vect.push_back(11);
	print(vect, "Print vector");
	cout << "Size :: " << vect.size() << "\t Capacity :: " << vect.capacity() << endl;

	vect.push_back(11);
	vect.push_back(11);
	
	print(vect, "Print vector");
	cout << "Size :: " << vect.size() << "\t Capacity :: " << vect.capacity() << endl;

	vect.push_back(11);
	vect.push_back(11);
	vect.push_back(11);
	vect.push_back(11);
	vect.push_back(11);

	print(vect, "Print vector");
	cout << "Size :: " << vect.size() << "\t Capacity :: " << vect.capacity() << endl;
}