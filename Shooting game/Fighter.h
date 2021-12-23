#pragma once
#include<vector>
#include "FlyingObject.h"
#include"Missile.h"

class Fighter : public FlyingObject
{
	unsigned int dir;

public:
	std::vector<Missile*>missiles;
	enum DIRECTION {
		STOP = 0,
		FORE = 1,
		BACK = 2,
		LEFT = 4,
		RIGHT = 8
	};

	Fighter();
	~Fighter();

	void init();
	void cleanup();
	void update();
	void draw();

	void move(DIRECTION dir);
	void stop(DIRECTION dir);

	void loadMissile(Missile* m);
	void shoot();
};
