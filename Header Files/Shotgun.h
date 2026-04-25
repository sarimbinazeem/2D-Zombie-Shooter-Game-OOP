#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "Weapon.h"

class Shotgun: public Weapon
{
    public:
        void shoot(vector<Bullet>& bullet, double x, double y, float directionX, float directionY) override;
        double getRate() override;
        const char* getName() override;
};

#endif