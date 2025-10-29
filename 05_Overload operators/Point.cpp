#include "Point.h"


Point Point::operator+(const Point& other) const
{
	/*Point result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;

	return result;*/

	return Point(this->x + other.x, this->y + other.y);
}

Point Point::operator-(const Point& other) const
{
	return Point(this->x - other.x, this->y - other.y);
}

bool Point::operator==(const Point& other) const
{
	return this->x == other.x and this->y == other.y;
}

bool Point::operator!=(const Point& other) const // this(left) + other(right) 
{
	return !(*this == other); // використали операцію написану раніше ==, і заперечили результат
}

Point& Point::operator++() // ++a
{
	++this->x;
	++this->y;
	return *this;
}

Point Point::operator++(int) // a++
{
	Point tmp(*this); // copy ctor, зняли копію самого себе, записали у tmp

	//++this->x; // змінюємо поля обєкта this
	//++this->y;
	++ *this; //або можна так : викликати написану раніше ++ префіксну

	return tmp;
}
