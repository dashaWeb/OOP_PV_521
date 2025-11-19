#include <iostream>
#include "Lion.h"
#include "Wolf.h"
#include <vector>
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

   /* Animal** zoo = new Animal * [5] {&animal, & animal2, & lion, & wolf, & bluewolf};
    for (size_t i = 0; i < 5; i++)
    {
        zoo[i]->print();
        zoo[i]->eat();
        cout << "\n----------------" << endl;
    }*/

    /*Animal animal_lion = lion;
    animal_lion.*/

    vector<Animal*> zoo{&animal, &animal2, &lion, &wolf, &bluewolf};

    cout << "\n\n Print :: " << endl;
    for (auto& i : zoo)
    {
        i->print();
        auto l = dynamic_cast<Lion*>(i);
        if(l != nullptr)
            l->eat();
        auto w = dynamic_cast<Wolf*>(i);
        if(w != nullptr)
            w->move();
        auto bw = dynamic_cast<BlueWolf*>(i);
        if (bw != nullptr)
            bw->color();
        cout << "\n ---------------------------- \n";
    }

}

