#include <iostream>
#include <cmath>
#include "../Header Files/Zombie.h"

Zombie::Zombie(float posX,float posY)
{
    x = posX;
    y = posY;
    speed = 1;
    health = 100;
    radius = 20;
    damage = 5;
}




//Function overriding

void Zombie::draw()
{
    DrawCircle((int)x,(int)y,radius,GREEN);
}
void Zombie::update(float playerX, float playerY)
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

    x = x + dx*speed;
    y = y + dy*speed;
}

int Zombie::getReward()
{
    return 10;
}