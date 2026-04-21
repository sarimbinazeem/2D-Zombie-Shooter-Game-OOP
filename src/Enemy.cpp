#include "Enemy.h"

Enemy:: Enemy(float startX, float startY, float speed); {
    x = startX;
    y = startY;
    this->speed = speed;
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