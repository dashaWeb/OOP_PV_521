#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

#include "Product.h"

Product::Product(const char* name)
{
	setName(name);
}

Product::Product(const char* name, const size_t& price, const size_t& quantity, ProductType productType)
{
	setName(name);
	setPrice(price);
	setQuantity(quantity);
	setProductType(productType);
	/*counter++;*/
}

Product::Product(const Product& other)
	:Product(other.name,other.price,other.quantity,other.productType)
	// каскадно викликали конструктор з 4 параметрами
{
	/*setName(other.name);
	setPrice(other.price);
	setQuantity(other.price);
	setProductType(other.productType);*/
}

void Product::operator=(const Product& right) // this(left) -> right;
{
	if (this == &right)
		return;
	setName(right.name);
	setPrice(right.price);
	setQuantity(right.price);
	setProductType(right.productType);
}

Product::~Product()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
}

void Product::setName(const char* name)
{
	if (this->name != nullptr)
		delete[] this->name;

	size_t size = strlen(name) + 1; // end \0
	this->name = new char[size];
	strcpy_s(this->name, size, name);
}

void Product::setPrice(const size_t& price)
{
	this->price = price;
}

void Product::setQuantity(const size_t& quantity)
{
	if (quantity <= MAX_QUANTITY)
		this->quantity = quantity;
	else
		this->quantity = MAX_QUANTITY;
}

void Product::setProductType(const ProductType& productType)
{
	if (productType >= ProductType::NONE and productType <= ProductType::BEVEREAGES)
		this->productType = productType;
}

void Product::print() const
{
	cout << "\t -----ID  :: " << counter << endl;
	cout << "\t Product  :: " << name << endl;
	cout << "\t Price    :: " << price << endl;
	cout << "\t Quantity :: " << quantity << endl;
	cout << "\t Category :: " << productType << endl;
}

size_t Product::counter = 0; // визначення статичної змінної(поля) на глобальному рівні;