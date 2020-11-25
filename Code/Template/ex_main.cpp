#include <iostream>
#include "ItemList.h"
#include "Manager.h"
#include "Space.h"

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT,
};

None NONE = None();
Space SPACE = Space();
Manager manager;

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
				std::cout << manager.getCell(i, j).getTopography().symbol;
			}
			std::cout << std::endl;
		}

		switch (getchar()) {
		case 'w':
		case 'W':
			manager.getUser().move(UP);
			break;
		case 'a':
		case 'A':
			manager.getUser().move(LEFT);
			break;
		case 's':
		case 'S':
			manager.getUser().move(DOWN);
			break;
		case 'd':
		case 'D':
			manager.getUser().move(RIGHT);
			break;
		}
	}

	return 0;
}

void print() {

}