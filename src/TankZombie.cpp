#include "../Header Files/TankZombie.h"
#include <cmath>
using namespace std;

Texture2D TankZombie::texture;

void TankZombie::setTexture(Texture2D tex)
{
    texture = tex;
}

TankZombie::TankZombie(float posX, float posY)
{
    x  = posX;
    y = posY;
    health = 200;
    speed = 0.75f;
    damage = 10;
    radius = 100;
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
    rotation = atan2(dy, dx) * 180 / PI - 80; // Calculate rotation angle in degrees
}

void TankZombie::draw()
{
    DrawTexturePro(texture, Rectangle{0,0,(float)texture.width,(float)texture.height},Rectangle{x,y,(float)radius*2,(float)radius*2},  Vector2{(float)radius,(float)radius},  rotation,  WHITE);
}

int TankZombie::getReward()
{
    return 50;
}