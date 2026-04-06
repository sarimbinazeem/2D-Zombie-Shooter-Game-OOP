#ifndef PISTOL_H
#define PISTOL_H

#include "Weapon.h"

class Pistol: public Weapon
{
    public:
        void shoot(vector <Bullet> &bullet, double x,double y) override;
        double getRate() override;
};

#endif