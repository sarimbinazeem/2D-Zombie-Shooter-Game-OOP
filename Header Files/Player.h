#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include <Weapon.h>
using namespace std;

class Player
{
    private:
        int health;
        double speed;
        double xPos;
        double yPos;
        int width;
        int height;
        Weapon* weapon;

    public:
        Player();
        
        void setWeapon(Weapon *w);
        void shoot(vector <Bullet>& bullet);

        void move();
        void draw();
        void takeDamage(double damage);
        int getHealth();

        double getX();
        double getY();
        double getWidth();

};


#endif