
#include <iostream>
#include <forward_list>
#include <list>
#include <algorithm>

using namespace std;

template <typename ConType>
void print(const ConType& cont, const string& prompt = "")
{
	cout << prompt << endl;
	for (auto& i : cont)
	{
		cout << i << "\t";
	}cout << endl;
}
int main()
{
	forward_list<int> fl{ 10,23,45,-1,100,-55,10,-22,10,200 };
	fl.push_front(5);
	print(fl, "Forward list :: ");
	auto it = begin(fl);
	advance(it, 3);
	fl.insert_after(it, 77);
	print(fl, "Forward list :: ");

	it = find(fl.begin(), fl.end(),100);
	if (it != fl.end())
	{
		cout << " 100 was found" << endl;
		auto tmpIt = it;
		++tmpIt;
		if (tmpIt != fl.end())
		{
			cout << "Will be deleted :: " << *tmpIt << endl;
			fl.erase_after(it);
		}
		else {
			cout << "Erase after 100 is impossible (because it is last element)" << endl;
		}
	}
	print(fl, "After erase_after :: ");

	fl.remove(10);
	print(fl, "After remove :: ");

	int bound = 50;
	fl.remove_if([bound](auto el) {return el < bound; });
	print(fl, "After remove_if < 50 :: ");

	system("cls");

	list<string> li{ "c++","java","c#","python" };
	li.push_back("js");
	li.push_front("assembler");
	print(li, "List :: ");

	char letter = 'c';
	li.remove_if([letter](string el) {return el.find(letter) != string::npos; /*-1*/ });
	print(li, "List :: ");
}
