#include "../Header Files/Player.h"
#include <cmath>
#include <cstring>

Player::Player()
{
    xPos = 400;
    yPos = 300;
    speed = 5;
    health = 100;
    width = 80;
    height = 80;
    money = 0;

    shotgunUnlocked = false;
    machineGunUnlocked = false;

    rotation = 0.0f;

    pistolTexture = LoadTexture("Assets/pistol.png");

    shotgunTexture = LoadTexture("Assets/shotgun.png");

    machineGunTexture = LoadTexture("Assets/machinegun.png");
    
    weapon = nullptr;
  
}

void Player::move()
{
    // WASD Movement
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

    // Screen Boundaries
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

    // Rotate Towards Mouse
    Vector2 mousePos = GetMousePosition();

    float centerX = xPos + width / 2.0f; //Player's center X coordinate
    float centerY = yPos + height / 2.0f; //Player's center Y coordinate

    float dx = mousePos.x - centerX;
    float dy = mousePos.y - centerY;

    targetRotation = atan2(dy, dx) * RAD2DEG + 70; //atan2 gives angle in radians, convert to degrees

    // Smooth Rotation
    float diff = targetRotation - rotation;

    // Ensure the shortest rotation direction
    while (diff > 180)
    {
        diff -= 360;
    }

    while (diff < -180)
    {
        diff += 360;
    }

    rotation += diff * 0.15f; //move by 15% of the difference each frame for smoothness
}


void Player::draw()
{
    //Getting the texture based on the current weapon
    Texture2D currentTexture;

    if (weapon == nullptr)
    {
        currentTexture = pistolTexture;
    }
    else if (strcmp(weapon->getName(), "Pistol") == 0)
    {
        currentTexture = pistolTexture;
    }
    else if (strcmp(weapon->getName(), "Shotgun") == 0) 
    {
        currentTexture = shotgunTexture;
    }
    else
    {
        currentTexture = machineGunTexture;
    }

    //For rotation and drawing the player texture
    Rectangle source = {0, 0,(float)currentTexture.width, (float)currentTexture.height};

    Rectangle destination = { xPos + width / 2.0f,yPos + height / 2.0f, (float)width,(float)height};

    Vector2 origin = { width / 2.0f, height / 2.0f};

    DrawTexturePro( currentTexture, source,  destination, origin, rotation,  WHITE);
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

float Player::getX()
{
    return xPos + width / 2;
}

float Player::getY()
{
    return yPos + height / 2;
}

double Player::getWidth()
{
    return width;
}

double Player::getHeight()
{
    return height;
}

void Player::setWeapon(Weapon* newWeapon)
{

    weapon = newWeapon;
}

void Player::shoot(vector<Bullet>& bullets, float dirX, float dirY)
{
    if (weapon != nullptr)
    {
        weapon->shoot(bullets, getX(), getY(), dirX, dirY);
    }
}

Weapon* Player::getWeapon()
{
    return weapon;
}



void Player::addMoney(int amount)
{
    money += amount;
}

bool Player::spendMoney(int amount)
{
    if(money >= amount)
    {
        money -= amount;
        return true;
    }

    return false;
}

int Player::getMoney()
{
    return money;
}

void Player::increaseHealth(int amount)
{
    health += amount;
}

void Player::increaseSpeed(float amount)
{
    speed += amount;
}

void Player::unlockShotgun()
{
    shotgunUnlocked = true;
}

void Player::unlockMachineGun()
{
    machineGunUnlocked = true;
}

bool Player::hasShotgun()
{
    return shotgunUnlocked;
}

bool Player::hasMachineGun()
{
    return machineGunUnlocked;
}

Player::~Player()
{
    UnloadTexture(pistolTexture);
    UnloadTexture(shotgunTexture);
    UnloadTexture(machineGunTexture);
}

Player& Player::operator+=(int reward)
{
    money += reward;
    return *this;
}

void Player::reset()
{
    xPos = 400;
    yPos = 300;
    speed = 5;
    health = 100;
    money = 0;

    shotgunUnlocked = false;
    machineGunUnlocked = false;

    weapon = nullptr;
}