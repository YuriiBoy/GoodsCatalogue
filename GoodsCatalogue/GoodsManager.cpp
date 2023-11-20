#include "Header.h"
#include "GoodsManager.h"

void GoodsManager::loadData()
{
	std::ifstream fin;
	fin.open("GoodsStorage.txt");
	prod.clear();
	
	while (!fin.eof()) {
		int id;
		std::string name;
		std::string category;
		double price;

		fin >> id;
		fin.ignore();
		std::getline(fin, name);
		std::getline(fin, category);
		fin >> price;

		Goods product(id, name, category, price);
		prod.push_back(product);
		std::cout << "\n List of goods has been loaded\n";
	}
	prod.pop_back();
	fin.close();
}

void GoodsManager::saveData()
{
	std::ofstream fout;
	fout.open("GoodsStorage.txt");

	for (int i = 0; i < prod.size(); i++) {
		Goods temp = prod[i];
		fout << temp.getId() << std::endl;
		fout << temp.getName() << std::endl;
		fout << temp.getCategory() << std::endl;
		fout << temp.getPrice() << std::endl;
	}
	fout.close();
	std::cout << "\n List of goods is saved\n";
}

void GoodsManager::displayAllGoods() const
{
	if (prod.empty()) {
		std::cout << "\n Goods list is empty\n";
	}
	else {
		const int N = prod.size();
		std::cout << "\n There are " << N << " products in the list\n";
		std::cout << std::setw(5) << "N" << std::setw(20) << " Name: ";
		std::cout << std::setw(20) << " Category : " << std::setw(10) << " Price:\n";
		for (int i = 0; i < N; i++) {
			prod[i].display();
		}
	}
}

void GoodsManager::addProduct()
{
	int id;
	std::string name;
	std::string category;
	double price;

	id = prod.back().getId() + 1;
	std::cin.ignore();

	std::cout << "\n Input Name of the product: ";
	std::getline(std::cin, name);
	std::cout << "\n Input category of the product: ";
	std::getline(std::cin, category);
	std::cout << "\n Input price of the product: ";
	std::cin >> price;

	Goods newGoods(id, name, category, price);
	prod.push_back(newGoods);
	saveData();
}

void GoodsManager::delProduct()
{
	int id;
	std::cout << "\n Please input ID of the product you want to delete\n";
	std::cin >> id;

	auto iter = std::find_if(prod.begin(), prod.end(),
		[id](Goods& g) {return(g.getId() == id); });
	if (iter == prod.end()) {
	std::cout << "\n There is no such product\n";
	}
	else {
		prod.erase(iter);
		std::cout << "\n The product has been deleted\n";
		saveData();
	}
}
