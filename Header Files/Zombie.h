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
        inline void draw();
        inline void takeDamage(int dmg);
        inline bool isAlive();

        inline double getX();
        inline double getY();
        inline int getDamage();

};

#endif