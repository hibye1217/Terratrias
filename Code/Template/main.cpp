#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

#include "skTest_Scene.h"
#include "StartScene.h"
#include "Object.h"

#include "Const.h"
#include "space.h"
#include "hole.h"
#include "wall.h"
#include "none.h"
#include "glue.h"
#include "key.h"
#include "jump.h"
#include "boost.h"
#include "bomb.h"

Manager manager;
Item* item_list[item_num];
Topography* topo_list[topo_num];

std::string savefile;
int i_hat;
int j_hat;
int margin_bafor;
int margin_side;
int save[12][2]; 
//	0이 플레이어, 1이 최선
// 0,0 이 몇스테이지까지 해봤는지


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR, INT cmdShow) {
	srand(GetTickCount());

	Console console;
	Application app;

	if (CONSOLE_ON) {
		console.OpenConsole();
	}

	app.InitWindow(hInstance);
	app.InitD3D(app.FloatWindow(hInstance, cmdShow));

	app.InitDeltaTime();
	app.InitManager();


	item_list[Enum::KEY] = new Key(1);
	item_list[Enum::NONE] = new None();
	item_list[Enum::JUMP] = new Jump();
	item_list[Enum::BOOST] = new Boost();
	item_list[Enum::BOMB] = new Bomb();
	
	topo_list[Enum::HOLE] = new Hole(1);
	topo_list[Enum::SPACE] = new Space();
	topo_list[Enum::WALL] = new Wall();
	topo_list[Enum::GLUE] = new Glue();

	manager.getUser().setSprite(new Sprite("Resources/Sprite/Big/UserStart.png"));

	//return app.DoMainLoop(new MainScene());
	skTest_Scene * skTelekom = new skTest_Scene();

	StartScene* sceneStartPoint = new StartScene();

	sceneStartPoint->setNextScene(skTelekom);

	return app.DoMainLoop(sceneStartPoint);
}
