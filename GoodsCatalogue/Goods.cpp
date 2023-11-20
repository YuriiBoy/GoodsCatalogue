#include "Header.h"
#include "Goods.h"

Goods::Goods() : id(0), name("-"), category("-"), price(0.0)
{
}

Goods::Goods(int id, std::string name, std::string category, double price)
	:  id(id), name(name), category(category), price(price)
{}

void Goods::display() const
{
	std::cout << std::setw(5) << id;
	std::cout << std::setw(20) << name;
	std::cout << std::setw(20) << category;
	std::cout << std::setw(10) << price;
	std::cout << std::endl;
}

int Goods::getId() const
{
	return id;
}

std::string Goods::getName() const
{
	return name;
}

std::string Goods::getCategory() const
{
	return category;
}

double Goods::getPrice() const
{
	return price;
}
