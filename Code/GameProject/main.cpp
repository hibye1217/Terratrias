#include <iostream>
#include "Const.h"
#include "Manager.h"
#include "Space.h"
#include "Hole.h"
#include "Wall.h"

Manager manager;
Item* item_list[item_num] = { new Key(), new None(), };
Topography* topo_list[topo_num] = { new Hole(), new Space(), new Wall(), };

void print();

const int _h = 3;
const int _w = 3;

int main(void) {
	std::cout << "Hello" << std::endl;

	manager.initialize("test.txt");

	//User& user = manager.getUser();
	while (true) {
		system("cls");
		for (int i = 0; i < _h; ++i) {
			for (int j = 0; j < _w; ++j) {
				if (i == manager.getUser().getX() && j == manager.getUser().getY()) {
					std::cout << "?";
					continue;
				}
				// std::cout << manager.getCell(i, j).getTopography().symbol;
			}
			std::cout << std::endl;
		}

		switch (getchar()) {
		case 'w':
		case 'W':
			manager.getUser().move(Enum::UP);
			break;
		case 'a':
		case 'A':
			manager.getUser().move(Enum::LEFT);
			break;
		case 's':
		case 'S':
			manager.getUser().move(Enum::DOWN);
			break;
		case 'd':
		case 'D':
			manager.getUser().move(Enum::RIGHT);
			break;
		}
	}

	// 해제
	for(int i = 0; i < item_num; ++i)
	{
		delete item_list[i];
	}
	for(int i = 0; i < topo_num; ++i)
	{
		delete topo_list[i];
	}
	return 0;
}

void print() {

}