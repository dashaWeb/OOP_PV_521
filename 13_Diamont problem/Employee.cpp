#include "Employee.h"

Employee::Employee(const string& name, const string& position)
	:Person(name), position{position}
{
	cout << "\t\t >>>>>>>>>>> Ctor EMPLOYEE " << this->name << endl;
}

void Employee::print() const
{
	cout << "Employee name :: " << name << endl;
	cout << "Employee pos  :: " << position << endl;
}

Employee::~Employee()
{
	cout << "\t\t >>>>>>>>>>> Dtor EMPLOYEE " << this->name << endl;
}
