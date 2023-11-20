#pragma once
class Goods

{
	int id;
	std::string name;
	std::string category;
	double price;
public:
	Goods();
	Goods(int id, std::string name, std::string category, double price);
	void display() const;
	int getId() const;
	std::string getName() const;
	std::string getCategory() const;
	double getPrice() const;
};

