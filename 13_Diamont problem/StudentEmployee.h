#pragma once
#include "Student.h"
#include "Employee.h"
class StudentEmployee
	:protected Student, protected Employee
{
public:
	StudentEmployee(const string& name, const string& specialization, const string& position);
	StudentEmployee(const Student& student, const Employee& employee);
	~StudentEmployee();
	void print() const; // hides Student::print(), and Employee::print();
};

