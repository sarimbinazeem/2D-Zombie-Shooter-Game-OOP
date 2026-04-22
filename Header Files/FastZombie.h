#ifndef FASTZOMBIE_H
#define FASTZOMBIE_H

#include "Enemy.h"
#include "raylib.h"
#include <iostream>
using namespace std;

class FastZombie : public Enemy
{
    //Constructors
    FastZombie(float posX, float posY);

    //Member Functions
        void update(float playerX, float playerY) override;
        void draw() override;       

};

#endif