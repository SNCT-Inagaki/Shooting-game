#pragma once
#include "App.h"
#include"Fighter.h"
#include"EnemyA.h"
#include"EnemyB.h"
#include"Missile.h"
#include"Score.h"
#include"Sound.h"
#define N_ENEMY_A 10
#define N_ENEMY_B 10
#define N_MISSILE 100

class ShootingApp : public App
{
 private:
    Fighter fighter;
	EnemyA enemyA[N_ENEMY_A];
	EnemyB enemyB[N_ENEMY_B];
	Missile missile[N_MISSILE];
	std::vector<FlyingObject*>fos;
	std::vector<Enemy*> enemies;
	std::vector<Missile*> missiles;
	Score score;
 public:
	 virtual void init();
	 virtual void cleanup();
	 virtual void update();
	 virtual void draw();
	 virtual void keyDown(WPARAM key);
	 virtual void keyUp(WPARAM key);
};

