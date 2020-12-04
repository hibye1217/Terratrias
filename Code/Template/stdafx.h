#pragma once

//int OOF = 1280;
//int LUL = 720;

// Setting Program
#define CONSOLE_ON false
#define BG_COLOR D3DCOLOR_ARGB(255,255,255,255)
#define PROGRAM_NAME TEXT("Terratrias")
#define CONSOLE_NAME TEXT("Debug Console")
#define _WIN32_WINNT 0x0600

#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

#define BORDERLESS true

#define SAFE_RELEASE(p) {if(p) {p->Release(); (p) = NULL;}}
#define SAFE_DELETE(p) {if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete [](p); (p) = nullptr;}}

// 사용자설정

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
#include "Ice.h"

#include <fstream>

// DirectX Header
#include <d3d9.h>
#include <d3dx9.h>
#include <dsound.h>

// Window Header
#include <Windows.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// Debug Header
#include <iostream>

// Game Manager Header
#include "TextureManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "SoundManager.h"

// Library Header
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9d.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "dxguid.lib")

#if BORDERLESS

#define SCREEN_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define SCREEN_HEIGHT GetSystemMetrics(SM_CYSCREEN)

#else

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#endif // BORDERLESS

// Constant


// Global Variable
extern LPDIRECT3D9 pd3d;
extern D3DPRESENT_PARAMETERS d3dpp;
extern LPDIRECT3DDEVICE9 pd3dDevice;
extern LPD3DXSPRITE pd3dSprite;
extern HWND hWnd;
extern SceneManager* sceneManager;
extern TextureManager* textureManager;
extern InputManager* inputManager;
extern SoundManager* soundManager;


extern Manager manager;
extern Item* item_list[item_num];
extern Topography* topo_list[topo_num];

extern std::string savefile;
extern int save[12][2];
extern int i_hat;
extern int j_hat;
extern int margin_bafor;
extern int margin_side;