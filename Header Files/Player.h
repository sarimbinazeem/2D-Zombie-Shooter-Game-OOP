#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player
{
    private:
        double health;
        double speed;
        double xPos;
        double yPos;

    public:
        Player();
        
        void move();
        void draw();
        void takeDamage(double damage);
        double getHealth();
        
};


#endif