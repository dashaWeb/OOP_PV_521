#include "Library.h"

void Library::editBook(Book& book)
{
	cout << "\n Enter value :: \n";
	cout << "\t Title     :: "; getline(cin, book.name);
	cout << "\t Author    :: "; getline(cin, book.author);
	cout << "\t Year      :: "; cin >> book.year;
	book.available = false;
	cin.clear();
	cin.ignore();
}

void Library::addBook()
{
	Book tmp;
	editBook(tmp);
	lib.push_back(tmp);
}

void Library::print() const
{
	for (auto& i : lib)
	{
		cout << i;
	}
}

void Library::search(const string& name, const string& author)
{
	const Book res = searchHelper(name, author);
	cout << "Result find book :: ";
	cout << res << endl;
}

void Library::sorted_()
{
	//sort(lib.begin(), lib.end(), );
	lib.sort([](Book a, Book b) {return a.author < b.author; });
}

Book& Library::searchHelper(const string& name, const string& author)
{
	return *(find_if(lib.begin(), lib.end(), [&name, &author](auto book) {return (book.name == name && book.author == author); }));
}
