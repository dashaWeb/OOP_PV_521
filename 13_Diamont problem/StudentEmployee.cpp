#include "StudentEmployee.h"

StudentEmployee::StudentEmployee(const string& name, const string& specialization, const string& position)
	// спочатку буде виклик к-ра вірт базового класу (по замовчуванню, якщо не вказали який працюватиме дефолтний к-р Person)
	:Person(name), // викликали потрібний нам конструктор віртуального базового класу
	Student("", specialization), Employee("--", position)
{
	cout << "\t\t >>>>>>>>>>> Ctor STUDENT_EMPLOYEE " << Student::name << " - " << Employee::name << endl;

	/*Student::name = nameStudent;
	Employee::name = nameEmployee;
	this->specialization = specialization;*/
}

StudentEmployee::StudentEmployee(const Student& student, const Employee& employee)
// спочатку буде виклик к-ра вірт базового класу (по замовчуванню, якщо не вказали який працюватиме дефолтний к-р Person)
	:Person(student),
	Student(student), Employee(employee) //copy ctor
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
	cout << "Name :: \t" << name << endl;
	cout << name << " studies " << specialization << endl;
	cout << name << " work as " << position << endl;
}
