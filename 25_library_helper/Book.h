#pragma once
#include <string>
#include "Library.h"
using std::string;
class Book
{
	string author;
	string name;
	size_t year;
	bool available;
	friend class Library;
	
public:
	Book(const string& author = "None", const string& name = "None", const size_t& year = 0, const bool& available = false):
		author{ author }, name{ name }, year{ year }, available{available}
	{}
	friend std::ostream& operator << (std::ostream& out, const Book& obj); // cout << obj
};

inline std::ostream& operator<<(std::ostream& out, const Book& obj)
{
	out << "\n";
	out << "\t Title     :: " << obj.name << "\n";
	out << "\t Author    :: " << obj.author << "\n";
	out << "\t Year      :: " << obj.year << "\n";
	out << "\t Available :: " << std::boolalpha <<  obj.available << "\n";
	return out;
}




