#pragma once
#include <string>
using std::string;
#include "Person.h"

class Student
	:virtual public Person // віртуальне успадкування скасовує дублювання полів від класу Person при проблемі ромба
{
public:
	Student(const string& name = "Noname", const string& specialization = "Nospec");
	void print() const;
	~Student();
protected:
	//string name; успадковується від Персони
	string specialization;
};

