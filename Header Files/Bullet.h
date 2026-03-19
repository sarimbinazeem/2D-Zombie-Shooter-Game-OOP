#ifndef BULLET_H
#define BULLET_H

#include <raylib.h>

class Bullet
{
    private:
        double beginX;
        double beginY;

        double speed;

        double directionX;
        double directionY;

        int radius;

    public:
        Bullet(double x, double y, double speed, double dirX, double dirY);

        void updateSpeed();
        void drawBullet();

        //Vector2 To get 2 Variables Vector (Co-ordinates of the BULLET)
        Vector2 getPosition();

};