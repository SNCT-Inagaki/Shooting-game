#include "ShootingApp.h"

void ShootingApp::init()
{
	App::init();
	fighter.init();
	fos.push_back(&fighter);
	for (size_t s = 0; s < N_ENEMY_A; s++) {
		enemyA[s].init();
		enemies.push_back(&enemyA[s]);
		fos.push_back(&enemyA[s]);
	}
	for (size_t s = 0; s < N_ENEMY_B; s++) {
		enemyB[s].init();
		enemies.push_back(&enemyB[s]);
		fos.push_back(&enemyB[s]);
	}
	for (size_t s = 0; s < N_MISSILE; s++) {
		fighter.loadMissile(&missile[s]);
		missiles.push_back(&missile[s]);
		fos.push_back(&missile[s]);
	}
	score.init();
	Sound::getInstance()->registerFile(TEXT("c:/windows/Media/chimes.wav"), TEXT("explosion"));
	Sound::getInstance()->registerFile(TEXT("c:/windows/Media/ir_begin.wav"), TEXT("shoot"));
	Sound::getInstance()->registerFile(TEXT("c:/windows/Media/flourish.mid"), TEXT("bgm"));
	Sound::getInstance()->request(TEXT("bgm"));
}

void ShootingApp::cleanup()
{
	App::cleanup();
	for (size_t s = 0; s < fos.size(); s++) {
		fos[s]->cleanup();
	}
	fos.clear();
	enemies.clear();
	missiles.clear();
	Sound::getInstance()->cleanup();
}

void ShootingApp::update()
{
	App::update();
	for (size_t s = 0; s < fos.size(); s++) {
		if (fos[s]->status & FlyingObject::ACTIVE) {
			fos[s]->update();
		}
	}
	for (size_t s = 0; s < enemies.size(); s++) {
		if (!(enemies[s]->status & FlyingObject::ACTIVE)) {
			continue;
		}
		for (size_t i = 0; i < missiles.size(); i++) {
			if (enemies[s]->checkCollision(missiles[i])) {
				score.add(enemies[s]->point);
			}
		}
		enemies[s]->checkCollision(&fighter);
	}
	for (size_t i = 0; i < enemies.size(); i++)
		if (!enemies[i]->status) // 敵機がやられたら（アクティブでなければ）
			enemies[i]->init(); // 初期化してアクティブ化
	if (!fighter.status) { // 自機がやられたら（アクティブでなければ）
		cleanup(); // ゲームオーバー（終了手続き）
		init(); // ゲームスタート（初期化手続き）
	}
}

void ShootingApp::draw()
{
	App::draw();
	for (size_t s = 0; s < fos.size(); s++) {
		if (fos[s]->status & FlyingObject::ACTIVE) {
			fos[s]->draw();
		}
	}
	score.draw(0, 0);
	Sound::getInstance()->play();
}

void ShootingApp::keyDown(WPARAM key)
{
	switch (key) {
	case 0x41:
		fighter.move(Fighter::LEFT);
		break;
	case 0x44:
		fighter.move(Fighter::RIGHT);
		break;
	case 0x57:
		fighter.move(Fighter::FORE);
		break;
	case 0x53:
		fighter.move(Fighter::BACK);
		break;
	case VK_SPACE:
		fighter.shoot();
		break;
	case VK_RETURN:
		fighter.shoot();
		break;
	}
}

void ShootingApp::keyUp(WPARAM key)
{
	switch (key) {
	case 0x41:
		fighter.stop(Fighter::LEFT);
		break;
	case 0x44:
		fighter.stop(Fighter::RIGHT);
		break;
	case 0x57:
		fighter.stop(Fighter::FORE);
		break;
	case 0x53:
		fighter.stop(Fighter::BACK);
		break;
	}
}