#include "Player.h"

Player::Player()
{
    xPos = 400;
    yPos = 300;
    speed = 5;
    health = 100;
    width = 40;
    height = 40;
}

void Player::move()
{
    if (IsKeyDown(KEY_W))
    {
        yPos -= speed;
    }

    if (IsKeyDown(KEY_S))
    {
        yPos += speed;
    }

    if (IsKeyDown(KEY_A))
    {
        xPos -= speed;
    }

    if (IsKeyDown(KEY_D))
    {
        xPos += speed;
    }

    //To limit it to move from boundaries of the screen
    if (xPos < 0)
    {
        xPos = 0;

    }
    if (yPos < 0)
    {
        yPos = 0;

    }
    if (xPos + width > 800)
    {
        xPos = 800 - width;

    }
    if (yPos + height > 600)
    {
        yPos = 600 - height;

    }
}

void Player::draw()
{
    DrawRectangle(xPos, yPos, width, height, BLUE);
}

void Player::takeDamage(double damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}

int Player::getHealth()
{
    return health;
}

double Player::getX()
{
    return xPos + width / 2;
}

double Player::getY()
{
    return yPos + height / 2;
}

double Player::getWidth()
{
    return width;
}

void Player::setWeapon(Weapon* newWeapon)
{
    weapon = newWeapon;
}

void Player::shoot(vector<Bullet>& bullets)
{
    if (weapon != nullptr)
    {
        weapon->shoot(bullets,xPos, yPos);
    }
}