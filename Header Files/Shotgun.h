#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "Weapon.h"

class Shotgun: public Weapon
{
    public:
        void shoot(vector <Bullet> &bullet, double x,double y) override;
        double getRate() override;
};

#endif