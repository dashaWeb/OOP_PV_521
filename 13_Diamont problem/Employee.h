#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;
#include "Person.h"
class Employee
	:virtual public Person // віртуальне успадкування скасовує дублювання полів від класу Person при проблемі ромба
{
public:
	Employee(const string& name = "Noname", const string& position = "NoPosition");
	void print() const;
	~Employee();
protected:
	//string name;  успадковується від Персони
	string position;
};

