#include <iostream>
#include "Teacher.h"
using namespace std;


int main()
{
    Pupil ivan("Ivan");
    ivan.print();

    Teacher taras;

    taras.setMarkMath(ivan, 10);
    taras.setMarkEnglish(ivan, 12);

    cout << endl;

    ivan.print();

    cout << "Average mark :: " << Avg(ivan) << endl;
}

