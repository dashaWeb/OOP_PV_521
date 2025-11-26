#pragma once
#include <iostream>
using namespace std;
//
//// Exception - помилкова ситуація, чка потребує обробки
//
double divi(double a, double b)
{
	const double LIMIT = 1'000'000;
	if (b == 0)
		throw "Error : division by zero"; // викидаємо виняток(помилку) типу const char* 
	if (b > LIMIT)
		throw b; // кидаємо виняток типу double
	if (b < -LIMIT)
		throw (int)b; // кидаємо виняток типу int

	return a / b;
}
// якщо виняток не оброблений, то викликається ф-я termonate(), яка у свою чергу викликає ф-ю abort()

//void terminate()
//{
//    cout << "Overlapping terminate is working " << endl;
//    exit(EXIT_SUCCESS);
//}

//void my_terminate()
//{
//	cout << "my_terminate is working and doing exit " << endl;
//	exit(EXIT_FAILURE);
//}

void test_01_exception()
{
	//set_terminate(my_terminate); //  призначили свою замість стандартної terminate


	
	double a, b;
	cout << "Enter two number :: ";
	//cin >> a >> b;
	//cout << "Result " << divi(a, b) << endl;
	while (cin >> a >> b) // доки читаються дані згідно формату
	{
		try
		{
			cout << "\t Result :: " << divi(a, b) << endl;

		}
		catch (const char* ex)
		{
			cout << "Caught const char* ex! Message :: " << ex << endl;
		}
		//catch (double ex)
		//{
		//	cout << "Caught double! Bad value :: " << ex << endl;
		//}
		//catch (int ex)
		//{
		//	cout << "Caught int! Bad value :: " << ex << endl;
		//}
		catch (...)
		{
			cout << "Caught .....! Something happened " << endl;
		}
	}
}
