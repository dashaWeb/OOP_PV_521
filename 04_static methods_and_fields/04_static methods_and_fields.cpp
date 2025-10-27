#include <iostream>
#include "Product.h"
using namespace std;


int main()
{
    cout << Product::MAX_QUANTITY << endl;
    cout << "Number of products :: " << Product::getCounter() << endl;

    Product milk("Milk", 50, 3, ProductType::DAIRY);
    milk.print();

    cout << milk.MAX_QUANTITY << endl;

    Product bread("Bread", 25, 10, ProductType::BAKERY);
    bread.print();
    cout << bread.MAX_QUANTITY << endl;
   
    //bread.MAX_QUANTITY = 2000; error

    cout << "Number of products :: " << Product::getCounter() << endl;
    cout << boolalpha << "Check category :: " <<  Product::sameTypeProducts(milk, bread) << endl;

    Product yogurt("Berry yogurt", 40, 55, ProductType::DAIRY);
    yogurt.print();

    cout << "Number of products :: " << Product::getCounter() << endl;
    cout << boolalpha << "Check category :: " << Product::sameTypeProducts(milk, yogurt) << endl;

}
