#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "raylib.h"
#include "Enemy.h"

class Zombie : class Enemy
{
    private:

        int damage;
        int radius;

    public:
    //Zombie Constructor
        Zombie(float posX,float posY);

        //Member Functions
        void draw();
        void takeDamage(int dmg);
        bool isAlive();

        //Getters

        int getDamage();
        int getRadius();
        Vector2 getPosition();

        //Function overriding
        void update(float playerX, float playerY) override;
        void draw() override;       
};

#endif