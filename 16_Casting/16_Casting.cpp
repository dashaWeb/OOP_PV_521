#include <iostream>
using namespace std;

//explicit operator int() const {return ....}

enum Colors
{
	RED, GREEN, BLUE
};

struct Point
{
	int x = 0, y = 0;
	virtual void print() const
	{
		cout << "{" << x << ", " << y << "}" << endl;
	}
};

struct Point3D :Point // public inheritance by defaul for struct
{
	int z = 0;

	void print() const override
	{
		cout << "{" << x << ", " << y << ", " << z << "}" << endl;
	}
};

struct String
{
	string str; // -1
};

int main()
{
	char ch = 90; //неявне

	//int numb = { 2.5 }; // error

	cout << "char(122) = " << char(122) << endl;
	cout << "int() Colors::GREEN  = " << (int)Colors::GREEN << endl;

	Point point;
	point.x = 1;
	point.y = 2;

	//String str = (String&)point; // ??? немає помилки компіляції при загальному зведенні типу, а краще була

	//cout << "String number = (String&)point ::: " << str.str << endl;

	// static_cast if implicit type1 --> type2  (static_cast<type2>(valueType1))

	cout << "\n ________________ STATIC_CAST ____________________" << endl;
	cout << "static_cast<char>(122) = " << static_cast<char>(122) << endl;// явне перетворення типу
	cout << "static_cast<int>(Colors::GREEN) = " << static_cast<int>(Colors::GREEN) << endl;// явне перетворення типу

	//String str = static_cast<String&>(point); // compille error - it is good


	Point3D point3d;
	point3d.x = 1;
	point3d.y = 2;
	point3d.z = 3;

	cout << "Point 3D :: ";
	point3d.print();


	//Point point_ = point3d;// ok  - дозволене неявне зведення від похідного типу до базового

	Point& point_ = point3d;


	cout << "\n\n point_ :: ";
	point_.print();

	//Point3D point3 = (Point3D&)point_;
	//Point3D point3 = (Point3D&)point_;

	if (typeid(point_) == typeid(Point3D))
	{
		Point3D point3 = static_cast<Point3D&>(point_);

		cout << "\n\n point3 :: ";
		point3.print();
	}
}

