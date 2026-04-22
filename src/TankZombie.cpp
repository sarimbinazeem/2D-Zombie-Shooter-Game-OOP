#include "TankZombie.h"
using namespace std;

TankZombie::TankZombie(float posX, float posY)
{
    x  = posX;
    y = posY;
    health = 200;
    speed = 0.75f;
    damage = 10;
    radius = 30;
}

TankZombie::update(float playerX, float playerY)
{
    float dx = playerX - x;
    float dy = playerY - y;

    float distance = sqrt(dx*dx + dy*dy);

    if(distance != 0)
    {
        x += (dx / distance) * speed;
        y += (dy / distance) * speed;
    }
}

TankZombie::draw()
{
    DrawCircle(x, y, radius, RED);
}