#pragma once
#include <iostream>
#include <list>
#include <algorithm>

#include "Book.h"

using namespace std;

class Library
{
	list<Book> lib 
	{Book("Test 3","Test 7"),Book("Test 2","Test 5"),Book("Test 1","Test 3") }
	;
	
	Book& searchHelper(const string& name, const string& author);
public:
	void editBook(Book& book);
	void addBook();
	void print() const;
	void search(const string& name, const string& author);
	void sorted_();
};

