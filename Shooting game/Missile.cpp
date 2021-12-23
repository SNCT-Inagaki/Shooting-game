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
	if (status & COLLISION) { // �Փ˂��Ă�������W���X�V���Ȃ�
		if (etimer.get() > 0.5) // �Փˊ��Ԃ��I�������A
			cleanup(); // �I���葱��
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
	if (status & COLLISION) { // �Փ˂��Ă����甚���A�j���[�V����
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
