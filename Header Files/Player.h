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
        inline void draw();
        void takeDamage(double damage);
        inline int getHealth();
        
};


#endif