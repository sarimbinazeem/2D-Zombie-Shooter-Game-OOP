#include "Enemy.h"

Enemy::  Enemy(float startX, float startY, int radius)
 {
    x = startX;
    y = startY;

    this->radius = radius;


    health =100;
}

Enemy:: ~Enemy() { }

float Enemy::getX()  
{
    return x;
}

float Enemy::getY()  
{
    return x;
}

Enemy::Enemy()
{
    x= 0;
    y = 0;
    speed = 1.0f;
    health = 100
}