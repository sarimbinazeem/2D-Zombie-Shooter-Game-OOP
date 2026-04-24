#ifndef TANKZOMBIE_H
#define TANKZOMBIE_H

#include "Enemy.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;

class TankZombie : public Enemy
{
    public:
        //Constructor 
        TankZombie(float posX, float posY);

        //Function Overriding Polymorphism
        void update(float playerX, float playerY) override;
        void draw() override;
        int getReward() override;
};



#endif