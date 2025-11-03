#pragma once
#include <iostream>
class MyArray
{
public:
	MyArray(); // по замовчуванню масив довжини 1
	MyArray(const size_t& size); // 3 1 параметром, масив довжини size
	MyArray(const size_t& size, int value); // 3 2 параметрами, масив довжини size, заповнений значенням value
	MyArray(const MyArray& other); // к-р копії

	~MyArray();

	size_t getSize() const { return size; }
	void print() const;

	int operator[](size_t index) const; // повертати елемент масиву за індексом
	int& operator[](size_t index); // повертати посилання на елемент масиву за індексом
	MyArray operator()(size_t startIndex, size_t endIndex) const;
	MyArray operator()(int up) const;

	MyArray& operator -=(int less);


	explicit operator int() const; // return sum
	explicit operator double() const; // return avg

	friend std::ostream& operator << (std::ostream& out, const MyArray& obj); // cout << obj

private:
	int* arr = nullptr;
	size_t size = 0;
};

std::istream& operator >> (std::istream& in, MyArray& obj); //cin >> obj; 
