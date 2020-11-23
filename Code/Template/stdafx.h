#pragma once

//int OOF = 1280;
//int LUL = 720;

// Setting Program
#define CONSOLE_ON true
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

#define I_HAT J_HAT
#define J_HAT min( (SCREEN_HEIGHT - (SCREEN_HEIGHT%20)) / 20, 50 )

#define MARGIN_OF_LEFT SCREEN_WIDTH - I_HAT * 20
#define MARGIN_OF_TOP SCREEN_HEIGHT - J_HAT * 20

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