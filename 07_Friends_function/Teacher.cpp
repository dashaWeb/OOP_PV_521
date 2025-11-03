#include "Teacher.h"
#include <iostream>

void Pupil::print() const
{
	std::cout << "Name    :: " << name << std::endl;
	std::cout << "Math    :: " << math << std::endl;
	std::cout << "English :: " << english << std::endl;
}

void Teacher::setMarkMath(Pupil& pupil, const size_t& mark)
{
	pupil.math = mark;
}

void Teacher::setMarkEnglish(Pupil& pupil, const size_t& mark)
{
	pupil.english = mark;
}
