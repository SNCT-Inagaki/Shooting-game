#pragma once
#include <Windows.h>
#include<random>

class App
{
public:
	static HWND hWnd;
	static HDC hDC;
	static std::mt19937 mt;

	App();
	virtual ~App();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	virtual void keyDown(WPARAM key);
	virtual void keyUp(WPARAM key);
	static double rand();
};

