#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T, size_t size = 5> // T - параметр типу, size = нетипований параметр (константа)
class Array
{
public:
	Array(const T& value = T());
	void fill(const T& value = T());
	const size_t& getSize() const;
	void print() const;

	T& operator[](size_t index);

private:
	
	T arr[size];
};

template<typename T, size_t size>
inline Array<T, size>::Array(const T& value)
{
	fill(value);
}

template<typename T, size_t size>
inline void Array<T, size>::fill(const T& value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

template<typename T, size_t size>
inline const size_t& Array<T, size>::getSize() const
{
	return size;
}



template<typename T, size_t size>
inline void Array<T, size>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template<typename T, size_t size>
inline T& Array<T, size>::operator[](size_t index)
{
	static T error;
	if (index < size)
		return arr[index];
	cout << "\t\t Error Index :: operator[]" << endl;
	return error;
}
