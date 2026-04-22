#include "FastZombie.h"

FastZombie::FastZombie() : Enemy()
{
    speed = 2.0f; 
    health = 75; 
    radius =  15.0f;
    damage = 7;

}

FastZombie::FastZombie(float x, float y) : Enemy(x, y)
{
    speed = 2.0f; 
    health = 75; 
    radius =  15.0f;
    damage = 7;
}

void FastZombie::update(float playerX, float playerY)
{
    float dx = playerX - posX;
    float dy = playerY - posY;

    float length = sqrt(pow(dx,2)+ pow(dy,2)); //The distance between Zombie and Player

    //To Make the Zombie Run Smoothly We Normalize The Vector
    if(length!= 0)
    {
        dx = dx/length;
        dy = dy/length;
    }

    posX = posX+ dx*speed;
    posY = posY + dy*speed;
}

void FastZombie::draw()
{
    DrawCircle(x, y, radius, BLUE);
}

