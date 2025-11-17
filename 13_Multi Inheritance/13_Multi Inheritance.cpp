#include <iostream>
using namespace std;
#include "StudentEmployee.h"
int main()
{
	Employee emp("Denis", "Manager");
	emp.print();

	Student stud("DENIS", "C#");
	stud.print();

	cout << endl;

	StudentEmployee se(stud, emp);
	se.print();

	StudentEmployee se2("Vasil", "VASIL", "C#", "Manger");
	se2.print();

	se2.Student::print();
}
