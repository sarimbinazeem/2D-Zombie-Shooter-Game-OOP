#ifndef FASTZOMBIE_H
#define FASTZOMBIE_H

#include "Enemy.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;

class FastZombie : public Enemy
{
    public:
        //Constructors
        FastZombie();
        FastZombie(float posX, float posY);

        //Member Functions Overriden
        void update(float playerX, float playerY) override;
        void draw() override; 
        int getReward() override;      

};

#endif