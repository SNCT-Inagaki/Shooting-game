#include "Score.h"

void Score::init()
{
	score = 0;
}

void Score::add(int point)
{
	score += point;
}

void Score::draw(int x, int y)
{
	wstring msg = TEXT("Score : ") + to_wstring(score);
	TextOut(App::hDC, x, y, msg.c_str(), lstrlen(msg.c_str()));
}