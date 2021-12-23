#define _USE_MATH_DEFINES	// Visual C++でM_PIを使えるように
#include <cmath>
#include "ShootingApp.h"
#include "EnemyB.h"

EnemyB::EnemyB() : Enemy()
{
	phase = 0;
}


EnemyB::~EnemyB()
{
}

void EnemyB::init()
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	// M_PIはπ

	x = 100 + 500 * App::rand();
	y = 100 + 200 * App::rand();

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	len = 30;
	radius = 25;

	point = 10;
}

void EnemyB::update()
{
	if (status & COLLISION) { // 衝突していたら座標を更新しない
		if (etimer.get() > 0.5) // 衝突期間が終わったら、
			cleanup(); // 終了手続き
		return;
	}
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	// updateの間隔が長すぎるときは、強制的にdtを設定
	if (dt > 1.0 / 30)
		dt = 1.0 / 30;

	dx = vx * cos(2 * mt + phase) * dt;
	dy = vy * sin(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	elapsed.reset();
}

void EnemyB::draw()
{
	if (status & COLLISION) { // 衝突していたら爆発アニメーション
		drawExplosion();
		return;
	}
	Rectangle(App::hDC, x, y, x + len, y + len);
}
