#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
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
        float  getX() const;
        float  getY() const;

        //Virtual Destructor
        virtual ~Enemy();


};

#endif