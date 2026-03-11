#include <iostream>
#include <cmath>
#include "Zombie.h"

Zombie::Zombie(double posX,double posY)
{
    this->posX = posX;
    this->posY = posY;
    speed = 1;
    health = 100;
    radius = 15;
    damage = 5;
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

double Zombie::getY()
{
    return posY;
}

int  Zombie::getDamage()
{
    return damage;
}

void Zombie::moveTowards(double playerX, double playerY)
{
    double dx = playerX - posX;
    double dy = playerY - posY;

    double length = sqrt(pow(dx,2)+ pow(dy,2)); //The distance between Zombie and Player

    //To Make the Zombie Run Smoothly We Normalize The Vector
    if(length!= 0)
    {
        dx = dx/length;
        dy = dy/length;
    }

    posX = posX+ dx*speed;
    posY = posY + dy*speed;
}

double Zombie::getRadius()
{
    return radius;
}