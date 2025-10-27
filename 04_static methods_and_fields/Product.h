#pragma once

enum ProductType
{
	NONE, BAKERY, DAIRY, CONFECTIONERS, BEVEREAGES
};

class Product
{
private:
	size_t id = ++counter;
	char* name = nullptr;
	size_t price = 0;
	size_t quantity = 0;
	ProductType productType = ProductType::NONE;
	static size_t counter; // декларація статичного поля, Требі визначати це поле на глобальному рівні, для багатоф проєкту - . cpp

public:
	// статичну константу цілого (int, size_t, long) типу можна проініціадізувати тут 
	static const size_t MAX_QUANTITY = 1000; // static = const ОДНА ДЛЯ ВСІХ ОБЄКТІВ
	Product() = default;
	Product(const char* name);
	Product(const char* name, const size_t& price, const size_t& quantity = 0, ProductType productType = ProductType::NONE);
	Product(const Product& other);
	void operator=(const Product& right); // this(left) = right; a = b
	~Product();

	void setName(const char* name);
	void setPrice(const size_t& price);
	void setQuantity(const size_t& quantity);
	void setProductType(const ProductType& productType);

	void print() const;
	static size_t getCounter(); // статичний метод повязаний не з обєктом, повязаний з класом, не отримує this

	static bool sameTypeProducts(const Product& one, const Product& two);

};

inline size_t Product::getCounter() // статичний метод може працювати зі статичними полями
{
	return counter;
}

inline bool Product::sameTypeProducts(const Product& one, const Product& two)
{
	return one.productType == two.productType;
}
