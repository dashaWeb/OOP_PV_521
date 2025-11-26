#include <iostream>
#include "Library.h"
using namespace std;



int main()
{
    Library lib;
    //lib.addBook();
    //lib.addBook();
    //lib.addBook();

    lib.print();

    cout << "Find book :: \n";
    //lib.search("Test 1", "Test 1");

    lib.print();
    lib.sorted_();
    
    cout << "Sorted" << endl;
    lib.print();

}

