#include <iostream>
#include <string>
using namespace std;

const size_t MIN_POWER = 50;
const size_t MAX_POWER = 100;

const double MIN_VOLUME = 0.7;
const double MAX_VOLUME = 6;

const size_t MAX_SPEED_LOW = 100;
const size_t MAX_SPEED_UP = 350;

struct Date {
    size_t day, month, year;
    string getDate()
    {
        // 02.05.2000
        return (day < 10 ? "0" : "") + to_string(day) + "." + (month < 10 ? "0" : "") + to_string(month) + "." + to_string(year);
    }
};

class Car {
private:
    string brand = "NoBrand";
    string color = "NoColor";
    size_t power = MIN_POWER;
    double volume = MIN_VOLUME;
    size_t max_speed = MAX_SPEED_LOW;
    Date date = Date();

public:
    Car() = default;
    /*Car(const string& brand_, const string& color_, const size_t& power_, const double& volume_, const size_t & max_speed_, const Date& date_)
    {
        brand = brand_;
        color = color_;
        power = power_;
        volume = volume_;
        max_speed = max_speed_;
        date = date_;
    }*/
    //Car(const string& brand, const string& color, const size_t& power, const double& volume, const size_t& max_speed, const Date& date)
    //{
    //    //this->brand = brand;
    //    setBrand(brand);
    //    //this->color = color;
    //    setColor(color);
    //    this->power = power;
    //    this->volume = volume;
    //    this->max_speed = max_speed;
    //    this->date = date;
    //}
    Car(const string& brand, const string& color, const size_t& power, const double& volume, const size_t& max_speed, const Date& date) : power{ power }, volume{ volume }, max_speed{max_speed}, date{date}
    {
        setBrand(brand);
        setColor(color);

    }
    void setBrand(const string& brand)
    {
        if (brand.empty() or brand == " ")
        {
            cout << "Error!!! Brand is empty " << endl;
            return;
        }
        this->brand = brand;
    }
    string getBrand()
    {
        return this->brand;
    }
    void setColor(const string& color)
    {
        if (color.empty() or color == " ")
        {
            cout << "Error!!! Brand is empty " << endl;
            return;
        }
        this->color = color;
    }
    string getColor()
    {
        return this->color;
    }
    void print()
    {
        cout << "\n\t ================ " << this->brand << " ===============" << endl;
        cout << "\t\t Color  :: " << this->color << endl;
        cout << "\t\t Power  :: " << this->power << endl;
        cout << "\t\t Volume :: " << this->volume << endl;
        cout << "\t\t Speed  :: " << this->max_speed << endl;
        cout << "\t\t Date   :: " << this->date.getDate() << endl;
    }
    void input()
    {  
        cout << "\t\t Enter Brand  :: ";  getline(cin, this->brand);
        cout << "\t\t Enter Color  :: ";  getline(cin,this->color);
        cout << "\t\t Enter Power  :: ";  cin >> this->power;
        cout << "\t\t Enter Volume :: ";  cin >> this->volume;
        cout << "\t\t Enter Speed  :: ";  cin >> this->max_speed;
        cout << "\t\t Enter Date   :: ";  cin >> this->date.day >> this->date.month >> this->date.year;
    }
};



//class Fraction {
//    int num, denum;
//
//public:
//    Fraction()
//    {
//
//    }
//
//    Fraction add(const Fraction& other)
//    {
//        this->num + other.num
//    }
//};

// public  - вікритий доступ. Маємо доступ до полів та методів і за межами класу
// private - доступ закритий. Доступ до полів і методів маємо лише в межах класу
// protected - захищений доступ. Маємо доступ в межіх класу і класах наслідниках

int main()
{
    Car bmw;
    Car ford("Ford", "Black", 70, 5.2, 170, {10,2,2001});
    

    //cout << "Brand :: " << ford.getBrand() << endl;
    //cout << "Color :: " << ford.getColor() << endl;

    ford.print();

    ford.input();
    ford.print();
}

