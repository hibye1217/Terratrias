#pragma once

// Setting Program
#define CONSOLE_ON true
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define BG_COLOR D3DCOLOR_ARGB(255,255,255,255)
#define PROGRAM_NAME TEXT("Terratrias")
#define CONSOLE_NAME TEXT("Debug Console")
#define _WIN32_WINNT 0x0600

#define KEY_NONE 0
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_ON 3

#define BORDERLESS true
#define I_HAT 50
#define J_HAT 50
#define MARGIN_TOPDOWN HEIGHT%JHAT
#define MARGIN_SIDE WIDTH%IHAT
// 원래 /2 해야지 공정한데, height가 안맞아서 나눌 수가 없음. 어카지?

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