#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "Weapon.h"

using namespace std;

class Player
{
    private:
        int health;
        double speed;
        float xPos;
        float yPos;
        int width;
        int height;
        Weapon* weapon;

    public:
        Player();
        
        void setWeapon(Weapon *w);
        void shoot(vector<Bullet>& bullets, float dirX, float dirY);

        void move();
        void draw();
        void takeDamage(double damage);
        int getHealth();

        float getX();
        float getY();
        double getWidth();
        double getHeight();
        Weapon* getWeapon();

};


#endif