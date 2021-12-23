#define _USE_MATH_DEFINES	// Visual C++��M_PI���g����悤��
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

	phase = App::rand() * M_PI;	// M_PI�̓�

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
	if (status & COLLISION) { // �Փ˂��Ă�������W���X�V���Ȃ�
		if (etimer.get() > 0.5) // �Փˊ��Ԃ��I�������A
			cleanup(); // �I���葱��
		return;
	}
	double dt = elapsed.get();
	double mt = mtimer.get();
	double dx, dy;

	// update�̊Ԋu����������Ƃ��́A�����I��dt��ݒ�
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
	if (status & COLLISION) { // �Փ˂��Ă����甚���A�j���[�V����
		drawExplosion();
		return;
	}
	Rectangle(App::hDC, x, y, x + len, y + len);
}
