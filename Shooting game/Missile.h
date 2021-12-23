#pragma once
#include "FlyingObject.h"
class Missile :
    public FlyingObject
{
public:
   /* Missile();
    ~Missile();*/

    void init();
    void update();
    void draw();
    void fire(double x,double y,double vx,double vy);
};

