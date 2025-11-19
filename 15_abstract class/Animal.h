#pragma once
#include "Lib.h"
class Animal abstract
{
public:
	void setAge(const size_t& age);
	void setPlace(const string& place);

	const size_t& getAge() const;
	const string& getPlace() const;

	virtual void print() const = 0; // pure virtual function - чисто віртуальна функція , може не містити реалізацію
	virtual void eat() const = 0;
	virtual void move() const = 0;



	Animal(const string& place = "No place", const size_t& age = 0); // default
	~Animal();
private:
	size_t  age;
	static size_t last_id;
protected:
	size_t id;
	string place;

};

