#include <iostream>
#include <cstdio>
#include "stdafx.h"
#include "Const.h"
#include "Manager.h"
#include "Space.h"
#include "Hole.h"
#include "Wall.h"
#include "None.h"
#include "Glue.h"
#include "Key.h"
#include "Jump.h"
#include "Boost.h"
#include "Bomb.h"

//Manager manager;
//Item* item_list[item_num] = { new Key(), new None(), new Jump(), new Boost(), new Bomb(), };
//Topography* topo_list[topo_num] = { new Hole(), new Space(), new Wall(), new Glue(), };

int run(void) {
	std::cout << "Hello" << std::endl;

	manager.initialize("stage1.txt");

	User& user = manager.getUser();
	while (manager.getMoveCnt() <= manager.getLimitCnt() && manager.getKeyCnt() > 0) {
		// print
		system("cls");
		std::cout << "remain key: " << manager.getKeyCnt() << std::endl;
		std::cout << "remain count: " << manager.getLimitCnt() - manager.getMoveCnt() << std::endl;
		std::cout << "(x, y) = " << user.getX() << ' ' << user.getY() << std::endl;
		std::cout << "inventory: " << item_name[user.getInventory()->getType()] << std::endl << std::endl;
		for (int i = 0; i < manager.getHeight(); ++i)
		{
			for (int j = 0; j < manager.getWidth(); ++j)
			{
				//std::cout << manager.getCell(i, j).getTopography()->getType() << ' ';
				std::cout << topo_name[manager.getCell(i, j).getTopography()->getType()] << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < manager.getHeight(); ++i)
		{
			for (int j = 0; j < manager.getWidth(); ++j)
			{
				std::cout << item_name[manager.getCell(i, j).getItem()->getType()] << ' ';
			}
			std::cout << std::endl;
		}

		/*
		*	이동 WASD
		*	쓰기 Space
		*	줍기 Q
		*	놓기 E
		*/
		char ch = getchar();
		switch (ch)
		{
		case 'W':
		case 'w':
			user.move(Enum::UP);
			break;
		case 'A':
		case 'a':
			user.move(Enum::LEFT);
			break;
		case 'S':
		case 's':
			user.move(Enum::DOWN);
			break;
		case 'D':
		case 'd':
			user.move(Enum::RIGHT);
			break;
		case ' ':
			user.useItem();
			break;
		case 'Q':
		case 'q':
			user.gainItem();
			break;
		case 'E':
		case 'e':
			user.putItem();
			break;
		}
	}
	if (manager.getKeyCnt() == 0)
	{
		std::cout << "Clear!!!" << std::endl;
	}
	else
	{
		std::cout << "Game Over" << std::endl;
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
