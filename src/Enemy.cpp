#include "Enemy.h"
#include <vector>

Enemy::  Enemy(float startX, float startY)
{
    x = startX;
    y = startY;
    speed = 1.0f;
    radius = 15.0f;
    damage = 5;
    health =100;
}

Enemy:: ~Enemy() { }



Enemy::Enemy()
{
    x= 0;
    y = 0;
    speed = 1.0f;
    radius = 15.0f;
    damage = 5;
    health =100;
}

void Enemy::takeDamage(int dmg)
{
    health -= dmg;
}

bool Enemy::isAlive() const 
{
    return health>0;
}


int  Enemy::getDamage() const
{
    return damage;
}

int Enemy::getRadius() const
{
    return radius;
}

Vector2 Enemy::getPosition()
{
    return{x,y};
}