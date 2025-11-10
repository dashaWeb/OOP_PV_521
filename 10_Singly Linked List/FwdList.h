#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


template <typename T>
struct Node // структура для опису одного вузла однозв списку
{
	T data;
	Node* next;
	Node(const T& data = T(), Node* next = nullptr)
		:data{ data }, next{next}
	{}
};

template<typename T>
class FwdList
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	size_t size = 0;
public:
	FwdList() = default;
	void addHead(const T& data);
	void print() const;
	bool isEmpty() const;
	void removeHead();
};

template<typename T>
inline void FwdList<T>::addHead(const T& data)
{
	/*Node<T>**/ auto tmp = new Node<T>(data, head);
	if (isEmpty())
		tail = tmp;
	head = tmp;
	size++;
}

template<typename T>
inline void FwdList<T>::print() const
{
	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = head; // починаємо з початку списка
	cout << "List :: \t ";
	while (tmp != nullptr) // доки не дійшли до кінця списку
	{
		cout << tmp->data << "\t"; // вивели дані з вузла
		tmp = tmp->next; // перейшли на наступний вузол
	}
	cout << endl;
}

template<typename T>
inline bool FwdList<T>::isEmpty() const
{
	return head == nullptr;
	//return size == 0;
}

template<typename T>
inline void FwdList<T>::removeHead()
{
	if (isEmpty()) {
		cout << "List is Empty" << endl;
		return;
	}
	auto tmp = head; // запамятали старий head
	head = head->next; // перемістили head на наступний елемент (можливо стане nullptr, якщо у списку був один елемент)
	if (isEmpty()) // якщо список стає порожнім, то виправляємо вказівник tail
		tail = nullptr;
	--size;
	delete tmp;
}
