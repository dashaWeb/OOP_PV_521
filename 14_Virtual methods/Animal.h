#pragma once
#include "lib.h"
class Animal
{
public:
	void setAge(const size_t& age);
	void setPlace(const string& place);

	const size_t& getAge() const;
	const string& getPlace() const;

	virtual void print() const;
	virtual void eat() const;

	Animal(const string& place = "No place", const size_t& age = 0); // default
	~Animal();
private:
	size_t  age;
	static size_t last_id;
protected:
	size_t id;
	string place;

};

