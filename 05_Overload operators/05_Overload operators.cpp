#include <iostream>
#include "Point.h"
using namespace std;




int main()
{
	Point A(2, 5);
	Point B(7, 8);

	cout << "A";
	A.print();

	cout << " + ";

	cout << "B";
	B.print();

	Point C = A + B; // + binary A(this) + B(other);
	// A.operator(B)
	cout << " = ";
	cout << "C";
	C.print(); // C(9,13)

	cout << endl;

	Point D = A - B;
	cout << "A - B --> ";
	D.print();
	cout << endl;

	Point E = D; // copy ctor

	cout << "\n\n";
	cout << "A";
	A.print();

	cout << "B";
	B.print();

	cout << "D";
	D.print();

	cout << "E";
	E.print();


	cout << " \n A == D --> " << boolalpha << (A == D) << endl; // виклик операції ==
	cout << " \n E == D --> " << boolalpha << (E == D) << endl; // виклик операції ==

	cout << " \n A != D --> " << boolalpha << (A != D) << endl; // виклик операції !=
	cout << " \n E != D --> " << boolalpha << (E != D) << endl; // виклик операції !=


	//int a = 5;
	//cout << ++a<< endl;
	//cout << a << endl;


	cout << "\n\n";
	cout << " A";
	A.print(); // (2,5)
	cout << "\n A";
	(++A).print(); // (3,6)
	cout << "\n A";
	A.print(); // (4,7)
	cout << "\n A";
	(A++).print(); // маємо почати старий варіант обєкта ()(3,6)
	cout << "\n A";
	A.print(); // (4,7)

}
