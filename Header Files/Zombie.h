#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "raylib.h"

class Zombie
{
    private:
        int health;
        float posX;
        float posY;
        double speed;
        int damage;
        int radius;

    public:
        Zombie(float posX,float posY);

        void moveTowards(float playerX, float playerY);
        void draw();
        void takeDamage(int dmg);
        bool isAlive();

        float getX();
        float getY();
        int getDamage();
        int getRadius();
        Vector2 getPosition();
};

#endif