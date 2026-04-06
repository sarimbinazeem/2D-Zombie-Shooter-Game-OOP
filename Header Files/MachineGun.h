#ifndef MACHINEGUN_H
#define MACHINEGUN_H

#include "Weapon.h"

class MachineGun: public Weapon
{
    public:
        void shoot(vector <Bullet> &bullet, double x,double y) override;
        double getRate() override;
};

#endif