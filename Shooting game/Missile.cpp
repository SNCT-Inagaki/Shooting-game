#include "ShootingApp.h"
#include "Missile.h"

/*Missile::Missile()
{
}

Missile::~Missile()
{
}*/

void Missile::init()
{
	FlyingObject::init();
	vx = vy = 0;
	radius = 10;
}

void Missile::update()
{
	if (status & COLLISION) { // 衝突していたら座標を更新しない
		if (etimer.get() > 0.5) // 衝突期間が終わったら、
			cleanup(); // 終了手続き
		return;
	}
	if (x < 0 || x > 799 || y < 0 || y > 599)
		cleanup();
	double dt = elapsed.get();
	x += vx * dt;
	y += vy * dt;
	elapsed.reset();

}

void Missile::draw()
{
	if (status & COLLISION) { // 衝突していたら爆発アニメーション
		drawExplosion();
		return;
	}
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
}

void Missile::fire(double x, double y, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}
