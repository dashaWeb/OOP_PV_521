#include "StudentEmployee.h"

StudentEmployee::StudentEmployee(const string& nameStudent, const string& nameEmployee, const string& specialization, const string& position)
	:Student(nameStudent, specialization), Employee(nameEmployee, position)
{

	cout << "\t\t >>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;

	/*Student::name = nameStudent;
	Employee::name = nameEmployee;
	this->specialization = specialization;*/
}

StudentEmployee::StudentEmployee(const Student& student, const Employee& employee)
	:Student(student), Employee(employee) //copy ctor
{
	cout << "\t\t >>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

StudentEmployee::~StudentEmployee()
{
	cout << "\t\t >>>>>>>>>>> Dtor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;
}

void StudentEmployee::print() const
{
	/*Student::print();
	Employee::print();*/
	cout << "Name :: " << Student::name << endl;
}
