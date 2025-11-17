#include <iostream>
#include "Lion.h"
#include "Wolf.h"
using namespace std;


int main()
{
    Animal animal("South Africa", 3);
    animal.print();

    Animal animal2("North Africa", 3);
    animal2.print();

    cout << "\n\n";

    Lion lion("Africa", 4, false);
    lion.print();

    cout << "\n\n";

    Wolf wolf;
    wolf.print();

    Animal test = lion; //

    test = (Animal)wolf;

    system("cls");

    BlueWolf bluewolf;

    Animal** zoo = new Animal*[5]{&animal, &animal2,&lion, &wolf, &bluewolf};
    for (size_t i = 0; i < 5; i++)
    {
        zoo[i]->print();
        zoo[i]->eat();
        cout << "\n----------------" << endl;
    }

}

