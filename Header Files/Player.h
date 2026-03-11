#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player
{
    private:
        int health;
        double speed;
        double xPos;
        double yPos;

    public:
        Player();
        
        void move();
        void draw();
        void takeDamage(double damage);
        int getHealth();
        
};


#endif