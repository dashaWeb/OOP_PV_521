#include <iostream>
#include <map>
using namespace std;

using id = size_t;
using name = string;

void print(map<id, name> coll)
{
	for (auto& p : coll)
	{
		cout << "Id :: " << p.first << "\t Name :: " << p.second << endl;
	}
}

void print(multimap<name, name> coll)
{
	for (auto& p : coll)
	{
		cout << "Id :: " << p.first << "\t Name :: " << p.second << endl;
	}
}
int main()
{
	map<id, name> people{
		pair<id, name>(555,"Ann"),
		make_pair(777,"Tom"),
		{222,"Olena"}
	};

	print(people);

	people.insert({ 333,"Ivan" });
	people.insert({ 333,"Den" });

	people[555] = "ANNA";
	people[888] = "Matviy";
	cout << "\n\n";
	print(people);

	id key = 1000;
	//cout << "Test get by key " << key << " :::: " << people[key] << endl;
	//cout << "Test get by key " << key << " :::: " << people.at(key) << endl; // expection

	key = 888;
	auto it = people.find(key);
	if (it != people.end())
	{
		cout << "Was found id " << key << " in index " << distance(begin(people), it) << " name " << (*it).second << endl;
	}
	cout << "\n\n";
	print(people);

	multimap<string, string> library{
		{"Iron Flame","Rebecca Yarros"},
			{"The Ever King","LJ Andrews"},
			{"Harry Potter and the Philosopher's Stone","J.K. Rowling"},
			{"Harry Potter and the Philosopher's Stone","J.K. Rowling"},
			{"Harry Potter and the Philosopher's Stone","J.K. Rowling"},
	};
	cout << "\n\n";
	print(library);

	//library["Harry Potter and the Philosopher's Stone"] = "Test test"; // multi map
	cout << "\n\n";
	library.insert({ "Harry Potter and the Philosopher's Stone" , "Test test" });
	print(library);

	//library.erase("Harry Potter and the Philosopher's Stone");
	//cout << "\n\n";
	string title = "Harry Potter and the Philosopher's Stone";
	auto p = library.equal_range(title);
	
	print(library);
}

