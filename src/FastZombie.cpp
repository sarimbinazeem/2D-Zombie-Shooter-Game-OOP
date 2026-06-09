#include "../Header Files/FastZombie.h"
#include <cmath>

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
    float dx = playerX - x;
    float dy = playerY - y;

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
    DrawCircle(x, y, radius, BLUE);
}

int FastZombie::getReward()
{
    return 20;
}