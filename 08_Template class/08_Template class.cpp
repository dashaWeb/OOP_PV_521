#include <iostream>
#include "Array.h"
using namespace std;


//int sum(int a, int b)
//{
//    return a + b;
//}
//
//double sum(double a, double b)
//{
//    return a + b;
//}
//
//char sum(char a, char b)
//{
//    return a + b;
//}

//template <typename T>
//T sum(T a, T b)
//{
//    return a + b;
//}

template<typename T, typename T2>
struct Pair {
	T first;
	T2 last;
	Pair() = default;
	Pair(T first, T2 last)
		:first{ first }, last{ last }
	{}

	template<typename T, typename T2>
	friend ostream& operator <<(ostream& out, const Pair<T, T2> obj)
	{
		// (2,2.5)
		out << "(" << obj.first << "," << obj.last << ")";
		return out;
	}

	// overload operators :  >> // , +=, +;
};

int main()
{
	/* cout << "Sum int :: " << sum(2, 3) << endl;
	 cout << "Sum double :: " << sum(2.3, 3.8) << endl;
	 cout << "Sum char :: " << sum('A', '1') << endl;
	 */
	Array<int> container(3);
	container.print();

	Array<double, 10> containerD(2.2);
	containerD.print();

	Array<char, 15> containerC('A');
	containerC.print();

	Pair<int, double> test(2, 5.2);
	cout << test.first << " >> " << test.last << endl;

	Array<Pair<int, double>, 20> containerPair(test);
	containerPair.print();

	
}



