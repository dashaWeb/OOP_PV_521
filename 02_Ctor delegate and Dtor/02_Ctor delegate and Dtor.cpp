#include <iostream>
using namespace std;




class City
{
private:
	char* name = nullptr;
	char* country = nullptr;
	size_t population = 0;

	void CopyStrField(char*& dest, const char* source) // cource - звідки, dest - куди копіюємо
	{
		if (name != nullptr)
			delete[] dest; // щоб не було витоку памяиі (видаляємо стару ділянку з назвою міста)

		size_t size = strlen(source) + 1;
		dest = new char[size];
		strcpy_s(dest, size, source);
	}

	bool isValidName(const char* name)
	{
		/*if (name == nullptr or name[0] == '\0')
			return false;
		return true;*/
		//return name != nullptr and name[0] != '\0';
		return !(name == nullptr or name[0] == '\0');
	}

public:
	City() = default;

	City(const char* name)
		:City(name,"NoCountry")
	{
		cout << "Ctor with 1 parameter " << endl;
	}

	City(const char* name, const char* country)
		:City(name,country,0)
	{
		cout << "Ctor with 2 parameter " << endl;
	}

	City(const char* name, const char* country, const size_t& population)
		:population{population}
	{
		cout << "Ctor with 3 parameter " << endl;
		setName(name);
		setCountry(country);
	}
	void setName(const char* name)
	{
		if (isValidName(name))
			CopyStrField(this->name, name);
	}

	void setCountry(const char* country)
	{
		if (isValidName(country))
			CopyStrField(this->country, country);
	}

	const char* getName() const
	{
		return this->name;
	}
	const char* getCountry() const
	{
		return this->country;
	}

	~City()
	{
		cout << "Dtor with  " << this->name << endl;
		if (this->name != nullptr)
			delete[] this->name;
		if (this->country != nullptr)
			delete[] this->country;
	}

	void print() const // не повинен змінювати стан обєкту (тобто жодне поле міняти не можна)
	{
		cout << "Name       :: " << this->name << endl;
		cout << "Country    :: " << this->country << endl;
		cout << "Population :: " << this->population << endl;
	}
};

int main()
{

	/*char* tmp = new char[6] {'R', 'i', 'v', 'n', 'e', '\0'};
	string test = "Rivne";
	City rivne("Rivne");
	rivne.print();

	delete[] tmp;
	tmp = nullptr;
	rivne.print();*/

	City* rivne = new City("Rivne", "Ukraine", 243873); // ctor 3 params
	rivne->print();
	cout << endl;
	cin.get();

	cout << "Test get :: " << rivne->getName() << endl;

	cin.get();

	const char* test = rivne->getName();


	City* paris = new City("Paris"); // ctor 3 params
	paris->print();
	cin.get();
	cout << endl;

	delete rivne;
	delete paris;
	cin.get();
	
	cout << endl;

	City lviv("Lviv");
	lviv.print();

	cout << endl;
	cin.get();
}
