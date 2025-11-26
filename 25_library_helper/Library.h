#pragma once
#include <iostream>
#include <list>
#include <algorithm>

#include "Book.h"

using namespace std;

class Library
{
	list<Book> lib 
	{Book("D","D"),Book("B","4"),Book("A","d"),Book("B","3"),Book("B","1") }
	;
	
	Book& searchHelper(const string& name, const string& author);
public:
	void editBook(Book& book);
	void addBook();
	void print() const;
	void search(const string& name, const string& author);
	void sorted_();
};

