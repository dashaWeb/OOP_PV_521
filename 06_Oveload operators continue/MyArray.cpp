#include "MyArray.h"

using std::cout;
using std::endl;
MyArray::MyArray()
	:MyArray(1)
{
}

MyArray::MyArray(const size_t& size)
{
	this->size = size;
	arr = new int[size] {}; // створили память для масиву і занулили {}
}

MyArray::MyArray(const size_t& size, int value)
	:MyArray(size)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

MyArray::MyArray(const MyArray& other)
	:MyArray(other.size)
{
	/*this->size = other.size;
	this->arr = new int[this->size];*/

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}

}

MyArray::~MyArray()
{
	delete[] arr;
	arr = nullptr;
}

void MyArray::print() const
{
	cout << "\n Array has " << size << " elements :: " << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int MyArray::operator[](size_t index) const
{
	if (index < size)
		return arr[index];
	return INT_MIN;
}

int& MyArray::operator[](size_t index)
{
	static int errValue;
	if (index < size)
		return arr[index];
	cout << ">>>>>>>> Error index(set) " << index << endl;
	return errValue;
}

MyArray MyArray::operator()(size_t startIndex, size_t endIndex) const
{
	if (startIndex >= size)
		return MyArray(0);
	if (endIndex >= size)
		endIndex = size - 1;
	if (startIndex > endIndex)
		std::swap(startIndex, endIndex);

	MyArray tmp(endIndex - startIndex + 1);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] = arr[i + startIndex];
	}
	return tmp;
}

MyArray MyArray::operator()(int up) const
{
	MyArray tmp(*this);
	for (size_t i = 0; i < tmp.size; i++)
	{
		tmp[i] += up;
	}
	return tmp;
}

MyArray& MyArray::operator-=(int less)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] -= less;
	}
	return *this;
}

MyArray::operator int() const
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

MyArray::operator double() const
{
	return (int)*this / (double)size;
}

std::ostream& operator<<(std::ostream& out, const MyArray& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		out << obj.arr[i] << "\t";
	}
	out << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, MyArray& obj)
{
	for (size_t i = 0; i < obj.getSize(); i++)
	{
		in >> obj[i];
	}
	return in;
}
