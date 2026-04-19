#ifndef MACHINEGUN_H
#define MACHINEGUN_H

#include "Weapon.h"

class MachineGun: public Weapon
{
    public:
        void shoot(vector<Bullet>& bullet, double x, double y, float directionX, float directionY) override;
        double getRate() override;
};

#endif