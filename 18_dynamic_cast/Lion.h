#pragma once
#include "Animal.h"

class Lion :public Animal
{
public:
	Lion(const string& place, const size_t& age, bool isAlone = false);
	~Lion();

	void print() const override;
	void eat()const;
private:
	bool isAlone;
};

