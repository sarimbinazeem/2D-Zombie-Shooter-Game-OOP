#include "Machinegun.h"
using namespace std;

void MachineGun::shoot(vector<Bullet>& bullet, double x, double y, float directionX, float directionY)
{
    bullet.push_back(Bullet(x, y, directionX, directionY));
}

double MachineGun::getRate()
{
    return 0.2; // Fast
}

const char* MachineGun::getName()
{
   return "Machine Gun";
}