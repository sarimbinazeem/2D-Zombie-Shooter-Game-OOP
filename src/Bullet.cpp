#include "Bullet.h"

Bullet::Bullet(double beginX, double beginY, double dirX, double dirY)
{
    x = beginX;
    y = beginY;

    speed  =10;
    radius = 5;

    directionX = dirX;
    directionY = dirY;
}


void Bullet::drawBullet()
{
    DrawCircle(x,y,radius,GOLD);
}

void Bullet::updateDirection()
{
    x = x + directionX*speed;
    y = y + directionY*speed;
}

Vector2 Bullet::getPosition()
{
    return{x,y};
}