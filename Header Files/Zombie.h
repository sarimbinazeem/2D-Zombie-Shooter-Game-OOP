#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "raylib.h"

class Zombie
{
    private:
        int health;
        double posX;
        double posY;
        double speed;
        int damage;
        double radius;

    public:
        Zombie(double posX,double posY);

        void moveTowards(double playerX, double playerY);
        void draw();
        void takeDamage(int dmg);
        bool isAlive();

        double getX();
        double getY();
        int getDamage();

};

#endif