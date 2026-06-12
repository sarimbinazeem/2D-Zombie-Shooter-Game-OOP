#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "raylib.h"
#include "Enemy.h"

class Zombie : public Enemy
{
    private:
        static Texture2D texture;

    public:
         //Zombie Constructor
        Zombie(float posX,float posY);

        //Function overriding
        void update(float playerX, float playerY) override;
        void draw() override;       
        int getReward() override;

        //Getters
        int getDamage();
        int getRadius();
        Vector2 getPosition();

        static void setTexture(Texture2D tex); // Static function to load the texture for all Zombie instances

};

#endif