#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include "Bullet.h"
using namespace std;

class Weapon
{
    public:
        virtual void shoot(vector<Bullet>& bullet, double x, double y, float directionX, float directionY) = 0;
        virtual double getRate() = 0;
        virtual const char* getName() = 0;
        
        virtual ~Weapon()
        {

        }
};

#endif