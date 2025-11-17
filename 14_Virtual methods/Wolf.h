#pragma once
#include "Animal.h"
class Wolf //final клас - від нього не можна успадковуватися
    : public Animal
{
public:
    void print() const  override; //final; похідним типам заборонено перевизначати цей метод
    Wolf(const string& place = "No Place", const size_t& age = 0, const size_t& weight = 0);
    ~Wolf();
private:
    size_t weight;
};

class BlueWolf : public Wolf
{
public:
    void print() const
    {
        cout << "------------------- BlueWolf #" << id << endl;
        // cout << age << endl; compile error - áî ïðèâàòíå ïîëå â óñïàäêëâàíîìó êëàñ³, íå âèäíî
        cout << "\t\t Age     :: " << getAge() << endl;
        cout << "\t\t PLace   :: " << place << endl; // protected

        //cout << "\t\t Weight  :: " << weight << endl;
    }
};

