#include  "../Header Files/Bullet.h"

Bullet::Bullet(float beginX, float beginY, float dirX, float dirY)
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

int  Bullet::getRadius()
{
    return radius;
}