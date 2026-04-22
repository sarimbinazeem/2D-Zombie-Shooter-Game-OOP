#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <iostream>
#include "raylib.h"
using namespace std;

class Enemy
{
    protected:
        int health;
        float  x;
        float  y;
        float  speed;
        
        int damage;
        int radius;


    public:
      // Constructor
        Enemy();
        Enemy(float startX, float startY);

        //Pure Virtual Functions
        virtual void update(float playerX, float playerY) = 0;
        virtual void draw() = 0;

        void takeDamage(int damage);
        bool isAlive() const; 

        //Getters
        int  getDamage() const;
        int getRadius() const;
        Vector2 getPosition();
        
        //Virtual Destructor
        virtual ~Enemy();


};

#endif