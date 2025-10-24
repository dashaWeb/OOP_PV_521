#pragma once

class Food
{
private:
	char* name = nullptr;
	size_t kkal;
	size_t weight;

public:
	const size_t MAX_WEIGHT = 2000;
	const char* getName() const;
	const size_t& getKkal() const;
	const size_t& getWeight() const;

	void setName(const char* name);
	void setKkal(const size_t& kkal);
	void setWeight(const size_t& weight);

	void print() const;

	Food(const char* name = "NoFood", const size_t& kkal = 0, const size_t& weight = 0);
	Food(const Food& other); // this(left operand) a = b (other right operand)
	void operator = (const Food& other);
	~Food()
	{
		if (this->name != nullptr)
			delete[] this->name;
	}
};

inline const char* Food::getName() const
{
	return this->name;
}

inline const size_t& Food::getKkal() const
{
	return this->kkal;
}

inline const size_t& Food::getWeight() const
{
	return this->weight;
}

inline void Food::setKkal(const size_t& kkal)
{
	this->kkal = kkal;
}

inline void Food::setWeight(const size_t& weight)
{
	if (weight <= MAX_WEIGHT)
		this->weight = weight;
}
