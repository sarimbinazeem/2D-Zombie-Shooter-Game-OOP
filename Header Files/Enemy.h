#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy
{
    private:
        int health;
        double x;
        double y;
        double speed;


    public:
      // Constructor
        Enemy();

        //Pure Virtual Functions
        virtual void update(float playerX, float playerY) = 0;
        virtual void draw() = 0;

        //Member Functions
        void takeDamage(int damage);
        bool isDead() const;

        //Getters
        double getX() const;
        double getY() const;

        //Virtual Destructor
        virtual ~Enemy();


};