#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// ���݂̈ʒu (pixel)
	double vx;		// ���݂̈ړ����x (pixel/s)
	double y;
	double vy;
	Timer elapsed;	// �O���update����̌o�ߎ��Ԍv���p
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

