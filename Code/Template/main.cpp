#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

#include "skTest_Scene.h"
#include "Object.h"

Manager manager;
Item* item_list[item_num] = { new Key(), new None(), new Jump(), new Boost(), new Bomb(), };
Topography* topo_list[topo_num] = { new Hole(), new Space(), new Wall(), new Glue(), };

int i_hat;
int j_hat;
int margin_bafor;
int margin_side;


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


	//return app.DoMainLoop(new MainScene());
	skTest_Scene * skTelekom = new skTest_Scene();

	return app.DoMainLoop(skTelekom);
}