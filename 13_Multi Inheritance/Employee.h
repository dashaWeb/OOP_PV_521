#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Employee
{
public:
	Employee(const string& name = "Noname", const string& position = "NoPosition");
	void print() const;
	~Employee();
protected:
	string name;
	string position;
};

