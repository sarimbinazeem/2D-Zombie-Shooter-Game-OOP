#include "Enemy.h"

Enemy::  Enemy(float startX, float startY)
    x = startX;
    y = startY;
    speed = 1.0f;
    radius = 15.0f;
    damage = 5;
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
    radius = 15.0f;
    damage = 5;
    health =100;
}