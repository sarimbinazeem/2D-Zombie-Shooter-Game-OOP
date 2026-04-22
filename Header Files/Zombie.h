#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "raylib.h"
#include "Enemy.h"

class Zombie : class Enemy
{

    public:
         //Zombie Constructor
        Zombie(float posX,float posY);

        //Function overriding
        void update(float playerX, float playerY) override;
        void draw() override;       
        void takeDamage(int damage) override;
        bool isAlive() override;

        //Getters
        int getDamage();
        int getRadius();
        Vector2 getPosition();

};

#endif