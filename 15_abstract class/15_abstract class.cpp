#include <iostream>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Wolf.h"
using namespace std;


int main()
{
    /*Animal animal("South Africa", 3); // НЕ МОЖНА створити екземпляр абстр типу
    animal.print();*/

    Lion lion("South Africa", 3);
    lion.print();

    Wolf wolf("Africa",2);
    wolf.print();


    //Animal**
    vector<Animal*> zoo{&lion, (Animal*) & wolf, new Lion("CENTRAL AFRICA",6,true)};

    cout << "\n\n Print zoo :: " << endl;
    for (size_t i = 0; i < zoo.size(); i++)
    {
        zoo[i]->print();
        zoo[i]->eat();
        zoo[i]->move();
    }

    delete zoo[2];

    cout << "\n\n End of main " << endl;
}


