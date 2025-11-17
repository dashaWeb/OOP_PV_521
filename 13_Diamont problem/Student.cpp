#include <iostream>
using std::cout;
using std::endl;
#include "Student.h"

Student::Student(const string& name, const string& specialization)
	:Person(name), specialization{specialization}
{
	cout << "\t\t >>>>>>>>>>> Ctor STUDENT " << this->name << endl;
}

void Student::print() const
{
	cout << "Student name :: " << name << endl;
	cout << "Student spec :: " << specialization << endl;
}

Student::~Student()
{
	cout << "\t\t >>>>>>>>>>> Dtor STUDENT " << this->name << endl;
}
