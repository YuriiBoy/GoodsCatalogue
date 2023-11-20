#pragma once
#include "Goods.h"

class GoodsManager
{
	std::vector <Goods> prod;
public:
	void loadData();
	void saveData();
	void displayAllGoods() const;
	void addProduct();
	void delProduct();
};

