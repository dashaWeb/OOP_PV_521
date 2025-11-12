#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
struct Node
{
	T data;
	Node *next, *prev;
	Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
		:data{ data }, prev{ prev }, next{next}
	{}
};



template <typename T>
class DList
{
public:
	DList() = default;
	~DList();
	DList(const DList<T>& other);
	DList<T>& operator=(const DList<T>& other);

	void AddHead(const T& data);
	void AddTail(const T& data);

	void removeHead();
	void removeTail();

	void print() const; // left to right
	void printR() const; // right to left

	bool isEmpty() const { return head == nullptr; }
	bool removeByData(const T& data);
private:

	Node<T>* findNode(const T& data);
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline DList<T>::~DList()
{
}

template<typename T>
inline DList<T>::DList(const DList<T>& other)
{
}

template<typename T>
inline DList<T>& DList<T>::operator=(const DList<T>& other)
{
	// TODO: insert return statement here
}

template<typename T>
inline void DList<T>::AddHead(const T& data)
{
	auto tmp = new Node<T>(data,nullptr,head);
	if (isEmpty())
		tail = tmp;
	else
		head->prev = tmp;
	head = tmp;
	++size;
}

template<typename T>
inline void DList<T>::AddTail(const T& data)
{
	auto tmp = new Node<T>(data, tail, nullptr);
	if (isEmpty())
		head = tmp;
	else
		tail->next = tmp;
	tail = tmp;
	++size;
}

template<typename T>
inline void DList<T>::removeHead()
{
	if (isEmpty())
		return;
	auto tmp = head;
	head = head->next;
	delete tmp;
	if (isEmpty())
		tail = nullptr;
	else
		head->prev = nullptr;
	--size;
}

template<typename T>
inline void DList<T>::removeTail()
{
	if (isEmpty())
		return;
	auto tmp = tail;
	tail = tail->prev;
	delete tmp;
	if (tail == nullptr)
		head = nullptr;
	else
		tail->next = nullptr;
	--size;
}

template<typename T>
inline void DList<T>::print() const
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = head;
	cout << "List in direct : \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::printR() const
{
	if (isEmpty())
	{
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = tail;
	cout << "List in reverse : \t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline bool DList<T>::removeByData(const T& data)
{
	auto find = findNode(data);
	if (find == nullptr)
		return false;
	if (find == head)
	{
		removeHead();
		return true;
	}
	if (find == tail) {
		removeTail();
		return true;
	}
	/*find->prev->next = find->next;
	find->next->prev = find->prev;*/
	auto left = find->prev;
	auto right = find->next;

	left->next = right;
	right->prev = left;

	delete find;
	--size;
	return true;
}

template<typename T>
inline Node<T>* DList<T>::findNode(const T& data)
{
	auto tmp = head;
	while (tmp != nullptr and tmp->data != data)
	{
		tmp = tmp->next;
	}
	return tmp;
}
