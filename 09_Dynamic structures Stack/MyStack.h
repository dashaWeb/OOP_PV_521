#pragma once
#include <iostream>
using std::cout;
using std::endl;
template <typename T>
class MyStack // First in - Last out
{
	enum {EMPTY = -1, DEFAULT_CAPACITY = 10, DEFAULT_GROW = 5};
public:
	MyStack(size_t capacity = DEFAULT_CAPACITY, size_t grow = DEFAULT_GROW);
	void push(const T& element); // додати новий елемент в кінець
	void pop(); // видалити елемент в кінці
	T top() const; // повернути верхній елемент
	size_t size() const; // кількість елементів у масиві
	bool empty() const; // перевірки чи пустий масив
	~MyStack(); // очищення ресурсів (memory leak)
	T operator[](size_t  index) const;
	size_t getCapacity() const;
private:
	void reserve(); // перевиділення пам'яті
	bool full() const; // перевірка чи масив заповнений
	int top_ = EMPTY;
	T* stack_ = nullptr; // вказівник на масив 
	size_t capacity;
	size_t growStep;
};

template<typename T>
inline MyStack<T>::MyStack(size_t capacity, size_t grow)
	:capacity{ capacity }, growStep{ grow }, stack_{ new T[capacity] }
{
	//stack_ = new T[capacity];
}

template<typename T>
inline void MyStack<T>::push(const T& element)
{
	if (full())
	{
		reserve();
	}
	stack_[++top_] = element;
}

template<typename T>
inline void MyStack<T>::pop()
{
	if(!empty())
		--top_;
}

template<typename T>
inline T MyStack<T>::top() const
{
	if (!empty())
		return stack_[top_];
	cout << "top() error : stack is empty" << endl;
	//return T();
	exit(EXIT_FAILURE);
}

template<typename T>
inline size_t MyStack<T>::size() const
{
	return top_ + 1;
}

template<typename T>
inline bool MyStack<T>::empty() const
{
	return top_ == EMPTY;
}

template<typename T>
inline MyStack<T>::~MyStack()
{
	if(!empty())
		delete[] stack_;
}

template<typename T>
inline T MyStack<T>::operator[](size_t index) const
{
	return stack_[index];
}

template<typename T>
inline size_t MyStack<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline void MyStack<T>::reserve()
{
	T* tmp = new T[capacity += growStep];
	for (size_t i = 0; i <= top_ ; i++)
	{
		tmp[i] = stack_[i];
	}
	growStep *= 2;
	delete[] stack_;
	stack_ = tmp;
}

template<typename T>
inline bool MyStack<T>::full() const
{
	return top_ == capacity - 1;
}
