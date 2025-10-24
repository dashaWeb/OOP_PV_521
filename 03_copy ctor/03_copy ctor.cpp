#include <iostream>
#include "Food.h"

using namespace std;
// MyClass.h ==> struct(class) definition (property, methods) + relization of inline methods
// MyClass.cpp ==> relization of notinline
// main.cpp


int main()
{
   
	Food food;
	food.setName("Bread");
	food.setKkal(200);
	food.setWeight(150);

	food.print();

	Food olivie("Salad Olivie", 330, 200);
	olivie.print();



	Food clone = food; // ctor {compile create copy ctor = shallow copy}
	//Food clone{ food };
	cout << "========= Origin ==========" << endl;
	food.print();
	cout << "========= Clone ==========" << endl;
	clone.print();


	clone.setName("Vareniki");

	cout << "========= Origin ==========" << endl;
	food.print();
	cout << "========= Clone ==========" << endl;
	clone.print();


	clone = olivie;
	cout << "\n\n";
	cout << "========= Origin ==========" << endl;
	olivie.print();
	cout << "========= Clone ==========" << endl;
	clone.print();

	clone.setName("Milk");
	cout << "\n\n";
	cout << "========= Origin ==========" << endl;
	olivie.print();
	cout << "========= Clone ==========" << endl;
	clone.print();

}
