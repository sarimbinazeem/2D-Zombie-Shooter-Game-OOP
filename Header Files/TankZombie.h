#ifndef TANKZOMBIE_H
#define TANKZOMBIE_H

#include "Enemy.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;

class TankZombie : public Enemy
{
    private:
        static Texture2D texture; // Static member to hold the texture for all TankZombie instances


    public:
        //Constructor 
        TankZombie(float posX, float posY);

        //Function Overriding Polymorphism
        void update(float playerX, float playerY) override;
        void draw() override;
        int getReward() override;

        static void setTexture(Texture2D tex);// Static function to load the texture
};



#endif