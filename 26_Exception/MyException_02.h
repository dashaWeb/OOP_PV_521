#pragma once
#include<iostream>
using namespace std;

// класи користувацьких винятків
class MyException //  базовий клас для наших помилок (по задачі: ф-я ділення)
{
public:
	MyException(const string& message = "Unknown", const double& value = 0)
		:message(message), value(value)
	{}
	virtual const string& what() const
	{
		return message;
	}
	virtual const double& getValue() const
	{
		return value;
	}
private:
	string message;
	double value;
};

// клас для позначення помилки ділення на 0
class DivByZeroException : public MyException
{
public:
	DivByZeroException(const string& message = "Division by zero")
		:MyException(message)
	{
	}
};
// клас для позначення помилки ділення на велике число
class ToBigDivisorException : public MyException
{
	static const int LIMIT_UP = 1'000'000;
public:
	ToBigDivisorException(const string& message = "Too big divisor", const double& value = LIMIT_UP)
		:MyException(message, value)
	{
	}
};

// клас для позначення помилки ділення на замале число < - 1000 000
class TooSmallDivisorException : public MyException
{
	static const int LIMIT_DOWN = -1'000'000;
public:
	TooSmallDivisorException(const string& message = "Too small divisor", const double& value = LIMIT_DOWN)
		:MyException(message, value)
	{
	}
};

double divi2(double a, double b)
{
	if (b == 0)
		throw DivByZeroException("Error : division by zero 2"); // викидаємо виняток(помилку) типу DivByZeroException
	if (b > 1'000'000)
		throw ToBigDivisorException("Too big number", b); // кидаємо виняток типу ToBigDivisorException
	if (b < -1'000'000)
		throw TooSmallDivisorException("Too small number", b); // кидаємо виняток типу TooSmallDivisorException

	return a / b;
}
void test_myException_02()
{
	double a, b;
	cout << "Enter two number :: \n";
	while (cin >> a >> b) // доки читаються дані згідно формату
	{
		try
		{
			cout << a << " / " << b << " = " << divi2(a, b) << endl;
		}
		/*catch (const DivByZeroException& ex)
		{
			cout << "Exception " << typeid(ex).name() << " was caught " << endl;
			cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
		}
		catch (const ToBigDivisorException& ex)
		{
			cout << "Exception " << typeid(ex).name() << " was caught " << endl;
			cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
		}
		catch (const TooSmallDivisorException& ex)
		{
			cout << "Exception " << typeid(ex).name() << " was caught " << endl;
			cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
		}*/
		/*catch (const MyException& ex)
		{
			cout << "My Exception " << typeid(ex).name() << " was caught " << endl;
			cout << ex.what() << "\t Bad value :: " << ex.getValue() << endl;
		}*/
		catch (...) // default catch
		{
			cout << "Exception .... was caught. Error" << endl;
		}
	}
}
