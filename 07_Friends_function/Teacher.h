#pragma once
#include <string>
using std::string;

class Pupil;

class Teacher
{
public:
	void setMarkMath(Pupil& pupil, const size_t& mark);
	void setMarkEnglish(Pupil& pupil, const size_t& mark);
};


class Pupil {
public:
	Pupil(const string& name, const size_t& math = 0, const size_t& english = 0);
	Pupil() = default;
	void print() const;
private:
	string name = "None";
	size_t math = 0;
	size_t english = 0;

	/*
	friend void Teacher::setMarkMath(Pupil& pupil, const size_t& mark);
	friend void Teacher::setMarkEnglish(Pupil& pupil, const size_t& mark);
	*/
	friend class Teacher;
	friend double Avg(const Pupil& pupil);
};

inline Pupil::Pupil(const string& name, const size_t& math, const size_t& english)
	:name{ name }, math{ math }, english{english}
{
}

inline double Avg(const Pupil& pupil)
{
	return (pupil.math + pupil.english) / 2;
}