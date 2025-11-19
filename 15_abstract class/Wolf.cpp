#include "Wolf.h"

void Wolf::print() const
{
	cout << "------------------- Wolf #" << id << endl;
	// cout << age << endl; compile error - бо приватне поле в успадклваному класі, не видно
	cout << "\t\t Age     :: " << getAge() << endl;
	cout << "\t\t PLace   :: " << place << endl; // protected

	cout << "\t\t Weight  :: " << weight << endl;
}

Wolf::Wolf(const string& place, const size_t& age, const size_t& weight)
	:Animal(place, age), weight{ weight }
{
	cout << ">>>>>>>>>>> Ctor Wolf ID #" << id << endl;
}

Wolf::~Wolf()
{
	cout << ">>>>>>>>>>> Dtor Wolf ID #" << id << endl;

}

void Wolf::eat() const
{
	cout << "Wolf ID :: " << id << " like meat and hunts to other animals" << endl;
}

void Wolf::move() const
{
	cout << "Wolf can run" << endl;
}
