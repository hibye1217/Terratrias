#include "stdafx.h"
#include "Console.h"
#include "Application.h"
#include "MainScene.h"

#include "skTest_Scene.h"
#include "Object.h"

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