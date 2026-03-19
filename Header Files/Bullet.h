#ifndef BULLET_H
#define BULLET_H

#include <raylib.h>

class Bullet
{
    private:
        double x;
        double y;

        double speed;

        double directionX;
        double directionY;

        int radius;

    public:
        Bullet(double x, double y, double dirX, double dirY);

        void updateDirection();
        void drawBullet();

        //Vector2 To get 2 Variables Vector (Co-ordinates of the BULLET)
        Vector2 getPosition();

        int getRadius();

};

#endif