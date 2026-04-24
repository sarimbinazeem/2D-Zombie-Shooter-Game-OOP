#include "TankZombie.h"
#include <cmath>
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

void TankZombie::update(float playerX, float playerY)
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

void TankZombie::draw()
{
    DrawCircle(x, y, radius, RED);
}

int TankZombie::getReward()
{
    return 50;
}