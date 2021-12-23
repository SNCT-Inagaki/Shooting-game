#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// 現在の位置 (pixel)
	double vx;		// 現在の移動速度 (pixel/s)
	double y;
	double vy;
	Timer elapsed;	// 前回のupdateからの経過時間計測用
	double radius = 0;
	Timer mtimer;
	double len = 0;
	Timer etimer;
public:
	unsigned int status = 0;
	FlyingObject();
	virtual ~FlyingObject();

	virtual void init();
	virtual void cleanup();
	virtual void update();
	virtual void draw();
	enum STATUS {
		ACTIVE = 1,COLLISION=2
	};
	void drawDebug();
	bool checkCollision(FlyingObject* fo);
	void drawExplosion();
};

