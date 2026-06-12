#include "../Header Files/FastZombie.h"
#include <cmath>

Texture2D FastZombie::texture;

void FastZombie::setTexture(Texture2D tex)
{
    texture = tex;
}

FastZombie::FastZombie() : Enemy()
{
    speed = 2.0f; 
    health = 75; 
    radius =  40.0f;
    damage = 7;

}

FastZombie::FastZombie(float x, float y) : Enemy(x, y)
{
    speed = 2.0f; 
    health = 75; 
    radius =  40.0f;
    damage = 7;
}

void FastZombie::update(float playerX, float playerY)
{
    float dx = playerX - x;
    float dy = playerY - y;

    rotation = atan2(dy, dx) * 180 / PI  - 70;  // Calculate rotation angle in degrees

    float length = sqrt(pow(dx,2)+ pow(dy,2)); //The distance between Zombie and Player

    //To Make the Zombie Run Smoothly We Normalize The Vector
    if(length!= 0)
    {
        dx = dx/length;
        dy = dy/length;
    }

    x = x+ dx*speed;
    y = y + dy*speed;
}

void FastZombie::draw()
{
    DrawTexturePro(texture, Rectangle{0,0,(float)texture.width,(float)texture.height},Rectangle{x,y,(float)radius*2,(float)radius*2},  Vector2{(float)radius,(float)radius},  rotation,  WHITE);
}

int FastZombie::getReward()
{
    return 20;
}