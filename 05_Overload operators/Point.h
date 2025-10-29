#pragma once
#include <iostream>
// не можна перевантажити операції : sizeof, typeid, ?

class Point
{
private:
	double x = 0, y = 0;
public:
	Point() = default;
	Point(const double& x) :x{ x } {};
	Point(const double& x, const double& y) : x{ x }, y{ y } {};

	void setX(const double& x);
	void setY(const double& y);

	double getX() const;
	double getY() const;

	void print() const;

	Point operator +(const Point& other) const; // this(left) + other(right) 
	Point operator -(const Point& other) const; // this(left) + other(right) 
	bool operator ==(const Point& other) const;
	bool operator !=(const Point& other) const;

	// ++ unary
	Point& operator ++(); // this - вже прийшов, префіксна форма
	Point operator ++(int); // this - вже прийшов, постфіксна форма має приймати фіктивний параметр
};

inline void Point::setX(const double& x)
{
	this->x = x;
}

inline void Point::setY(const double& y)
{
	this->y = y;
}

inline double Point::getX() const
{
	return x;
}

inline double Point::getY() const
{
	return y;
}

inline void Point::print() const
{
	std::cout << "(" << x << "," << y << ")" << "\t";
}


/*
	1. Унарний оператор
		a++;
		b--;
		++a;
		--b;
		!a;
		-a;
	2. Бінарний оператор
		a + b;
		a - b;
		a = b;
		a == b;

	a = 5;
	b = 3;
	c = a + b;
	___
	c = 8

	------------------
		a == b 


*/