#include <iostream>
#include <algorithm>
#include <set>
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
	multiset<int> ms{ 10,22,10,22,33,-33,100,200,100,1,100 };
	//multiset<int,greater<int>> ms{ 10,22,10,22,33,-33,100,200,100,1,100 };
	print(ms, "Print multi set");
	ms.insert(77);
	print(ms, "Print multi set");

	cout << "Min :: " << *ms.begin() << endl;
	cout << "Max :: " << *ms.rbegin() << endl;

	int key = 100;
	auto it = ms.find(key);
	if (it != ms.end())
	{
		cout << "Key " << key << " was found " << ms.count(key) << " times" << endl;
		ms.erase(key);
	}
	else {
		cout << "Key " << key << " not found" << endl;
	}
	print(ms, "Print multi set");

	key = 22;
	it = ms.lower_bound(key); // >= key
	if (it != ms.end())
	{
		cout << "Lower bound key :: " << *it << " in index " << distance(begin(ms), it) << endl;
	}

	key = 22;
	it = ms.upper_bound(key); // > key
	if (it != ms.end())
	{
		cout << "Upper bound key :: " << *it << " in index " << distance(begin(ms), it) << endl;
	}


	set<int/*, greater<int>*/> s(ms.begin(), ms.end());
	print(s, "Print  set");
	set<int> s2{100, 65, 77, 88, 300, 100,200,300,10,22};
	print(s2, "Print  set");
	ostream_iterator<int> outIt(cout,"\t");
	cout << "\n-------------- UNION -------------------" << endl;
	set_union(begin(s), end(s), begin(s2), end(s2), outIt);
	cout << "\n-------------- COMMON(INTERSECTION) -------------------" << endl;
	set_intersection(begin(s), end(s), begin(s2), end(s2), outIt);

	cout << "\n-------------- DIFFERENCE(s1-s2) -------------------" << endl;
	set_difference(begin(s), end(s), begin(s2), end(s2), outIt);

	cout << "\n-------------- DIFFERENCE(s2-s1) -------------------" << endl;
	set_difference(begin(s2), end(s2), begin(s), end(s), outIt);

}
