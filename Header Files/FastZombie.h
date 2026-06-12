#ifndef FASTZOMBIE_H
#define FASTZOMBIE_H

#include "Enemy.h"
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std;

class FastZombie : public Enemy
{
    private:
         static Texture2D texture;

    public:
        //Constructors
        FastZombie();
        FastZombie(float posX, float posY);

        //Member Functions Overriden
        void update(float playerX, float playerY) override;
        void draw() override; 
        int getReward() override;      

        static void setTexture(Texture2D tex); // Static function to load the texture for all Zombie instances
};

#endif