#pragma once
#include<Windows.h>
#include<string>
#include"App.h"
using namespace std;

class Score
{
private:
	int score;
public:
	void init();
	void add(int point);
	void draw(int x, int y);
};

