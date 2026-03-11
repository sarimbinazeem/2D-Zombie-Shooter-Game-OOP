#include "Player.h"

Player::Player()
{
    xPos = 400;
    yPos = 300;
    speed = 5;
    health = 100;
}

void Player::move()
{
         if(IsKeyDown(KEY_W))
        {
            yPos -= speed;
        }

        if(IsKeyDown(KEY_S))
        {
            yPos += speed;
        }

        if(IsKeyDown(KEY_A))
        {
            xPos -= speed;
        }

        if(IsKeyDown(KEY_A))
        {
            xPos += speed;
        }   
}

void Player::draw()
{
    DrawRectangle(xPos,yPos,40,40,BLUE);
}

void Player::takeDamage(double damage)
{
    health-= damage;
    if(health<0)
    {
        health = 0;
    }
}

double Player::getHealth()
{
    return health;
}