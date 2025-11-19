#include "Lion.h"

Lion::Lion(const string& place, const size_t& age, bool isAlone)
// Animal(); спочатку викликається конструктор базового типу
	:Animal(place, age), // явно викликаємопотрібний конструктор базового типу
	isAlone(isAlone)
{
	/*setAge(age);
	setPlace(place);
	isAlone = isAlone;*/
	cout << ">>>>>>>>>>> Ctor Lion ID #" << id << endl;
}

Lion::~Lion()
{
	cout << ">>>>>>>>>>> Dtor Lion ID #" << id << endl;
}

void Lion::print() const
{
	cout << "------------------- Lion #" << id << endl;
	// cout << age << endl; compile error - бо приватне поле в успадклваному класі, не видно
	cout << "\t\t Age     :: " << getAge() << endl;
	cout << "\t\t PLace   :: " << place << endl; // protected
	cout << "\t\t IsAlone :: " << boolalpha << isAlone << endl;
}

void Lion::eat() const
{
	cout << "Lion id :: " << id << " like eat meat" << endl;
}
