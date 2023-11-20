#include "Header.h"
#include "Menu.h"
#include "GoodsManager.h"

int main()
{
	std::string taskName = " Goods Catalogue";
	std::vector<std::string> menuList = {
		"Display all goods",
		"Add new product",
		"Delete one product",
		"Exit"
	};
	std::unique_ptr<Menu> m(new Menu(taskName, menuList));
	std::unique_ptr<GoodsManager> manager(new GoodsManager);
	manager->loadData();

	bool stop = false;
	do {
		system("cls");
		m->displayTaskName();
		m->displayMenuList();
		int choice = m->getChoice();
		switch (choice)
		{
		case 1:
			manager->displayAllGoods();
			break;
		case 2:
			manager->addProduct();
			break;
		case 3:
			manager->delProduct();
			break;
		case 4: stop = true;
			break;
		default:
			std::cout << "\n Wrong choice";
			break;
		}
		if (stop) {
			break;
		}

	} while (m->allowContinue());
}
