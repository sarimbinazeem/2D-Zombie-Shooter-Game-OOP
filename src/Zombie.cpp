#include <iostream>
#include "Zombie.h"

Zombie::Zombie(double posX,double posY)
{
    this->posX = posX;
    this->posY = posY;
    speed = 1;
    health = 100;
    radius = 15;
}

void Zombie::draw()
{
    DrawCircle((int)posX,(int)posY,radius,GREEN);
}

void Zombie::takeDamage(int dmg)
{
    health -= dmg;
}

bool Zombie::isAlive()
{
    return health>0;
}

double Zombie::getX()
{
    return posX;
}