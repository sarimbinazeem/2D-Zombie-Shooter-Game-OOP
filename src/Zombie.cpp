#include <iostream>
#include <cmath>
#include "Zombie.h"

Zombie::Zombie(float posX,float posY)
{
    this->posX = posX;
    this->posY = posY;
    speed = 1;
    health = 100;
    radius = 15;
    damage = 5;
}


void Zombie::takeDamage(int dmg)
{
    health -= dmg;
}

bool Zombie::isAlive()
{
    return health>0;
}

float Zombie::getX()
{
    return posX;
}

float Zombie::getY()
{
    return posY;
}

int  Zombie::getDamage()
{
    return damage;
}

//Function overriding

void Zombie::draw()
{
    DrawCircle((int)posX,(int)posY,radius,GREEN);
}
void Zombie::update(float playerX, float playerY)
{
    float dx = playerX - posX;
    float dy = playerY - posY;

    float length = sqrt(pow(dx,2)+ pow(dy,2)); //The distance between Zombie and Player

    //To Make the Zombie Run Smoothly We Normalize The Vector
    if(length!= 0)
    {
        dx = dx/length;
        dy = dy/length;
    }

    posX = posX+ dx*speed;
    posY = posY + dy*speed;
}

int Zombie::getRadius()
{
    return radius;
}

Vector2 Zombie::getPosition()
{
    return{posX,posY};
}