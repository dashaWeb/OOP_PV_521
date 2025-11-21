#include <iostream>
using namespace std;
//__interface
// interface - пропонує абстрактну поведінку (може містити чисті віртуальні методи)


//struct IMove
//{
//    virtual void move() const = 0;
//    virtual size_t getSpeed() const = 0;
//};

//struct IFly :/*public*/ IMove // by default struct inherits as public
//{
//    virtual void fly() const = 0;
//    virtual size_t getFlyHeight() const = 0;
//};

__interface IMove
{
public:
    virtual void move() const;
    virtual size_t getSpeed() const;
};

__interface IFly :public IMove // by default struct inherits as public
{
public:
    virtual void fly() const;
    virtual size_t getFlyHeight() const;
};

class Bird : public IFly // клас реалізує інтерфейс IFly = реалізує кожен віртуальний метод
{
    size_t height;
    size_t speed;
public:
    Bird(const size_t& height, const size_t& speed)
        :height{ height }, speed{speed}
    {}
    void move() const
    {
        cout << "Bird " << typeid(*this).name() << " can walk and fly \n";
    }

    // Inherited via IFly
    virtual size_t getSpeed() const override
    {
        return speed;
    }
    virtual void fly() const override
    {
        cout << "Bird " << typeid(*this).name() << " can  fly on height "<< getFlyHeight() << "\n";
    }
    virtual size_t getFlyHeight() const override
    {
        return height;
    }
};

class Eagle : public Bird
{
public:
    Eagle()
        :Bird(2000,30)
    {}
};

class Gull : public Bird
{
public:
    Gull()
        :Bird(500, 5)
    {}
};


class Car : public IMove
{
    string brand;
public:
    Car(const string& brand)
        :brand{brand}
    {}

    // Inherited via IMove
    virtual void move() const override
    {
        cout << "Car " << brand << " can move wit speed " << getSpeed() << endl;
    }
    virtual size_t getSpeed() const override
    {
        return 200;
    }
};


class Owner
{
    string name;
    IMove* moveable;
public:
    Owner(const string& name, IMove* moveable) 
        :name{ name }, moveable{moveable}
    {}
    void go()
    {
        moveable->move();
    }
    void setMoveable(IMove* moveable)
    {
        this->moveable = moveable;
    }
};

void demoMoveable(IMove* movable)
{
    cout << "______ Demo func _________" << endl;
    movable->move();
    cout << "Speed of moving :: " << movable->getSpeed() << endl;
}

int main()
{
    Eagle eagle;
    eagle.fly();

    Gull gull;
    gull.move();

    IMove* im = &eagle;
    im->move();

    IFly& ifl = eagle;
    ifl.fly();

    Car car("BMW");
    demoMoveable(&car);
    demoMoveable(&eagle);

    IMove* moving[]{&eagle, &gull, &car};
    cout << "\n\n";
    for (auto& i : moving)
    {
        demoMoveable(i);
    }

    IFly* fliers[]{ &eagle, &gull};

    cout << "\n\n";
    for (auto& i : fliers)
    {
        demoMoveable(i);
        i->fly();
    }
    cout << "\n\n";

    Owner owner("Sergiy", &car);
    owner.go();

    owner.setMoveable(&gull);
    owner.go();

}
