#include <iostream>
using namespace std;

void funcInt(const int& value)
{
	//++value;
	++const_cast<int&>(value);
	int& ref = const_cast<int&>(value);
	ref++;
}


class Person {
public:
	Person(const string& name = "Noname", const size_t& age = 0)
		:name{name}, age{age}
	{}
	const string& getName() const // const Person* (const this)
	{
		//name[0] = '*';
		if (islower(name[0]))
		{
			string& ref =const_cast<string&>(name);
			ref[0] = toupper(ref[0]);
		}
		return name;
	}

	const size_t& getAge() const
	{
		Person* changeThis = const_cast<Person*>(this);
		changeThis->age++;
		changeThis->name += "#";
		return age;
	}
private:
	string name;
	size_t age;
};
int main()
{
   
	int test_value = 5;
	cout << "Test value :: " << test_value << endl;
	funcInt(test_value);
	cout << "Test value :: " << test_value << endl;

	const int test_value2 = 200;
	cout << "Test value :: " << test_value2 << endl;
	funcInt(test_value2);
	cout << "Test value :: " << test_value2 << endl;

	//////////////// Person
	Person person("dmytro", 14);
	cout << person.getName() << endl;
	cout << person.getAge() << endl;
	cout << person.getAge() << endl;
	cout << person.getName() << endl;

}
