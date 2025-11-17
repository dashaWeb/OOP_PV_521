#pragma once
#include<iostream>
using std::string;
using std::cout;
using std::endl;


class Person
{
public:
	Person(const string& name = "Noname")
		:name{ name }
	{
		cout << "\t\t >>>>>>>>>>> Ctor PERSON " << this->name << endl;
	}
	~Person()
	{
		cout << "\t\t >>>>>>>>>>> Dtor PERSON " << this->name << endl;
	}
	void print() const
	{
		cout << "Name : \t " << name << endl;
	}
protected:
	string name;

};

