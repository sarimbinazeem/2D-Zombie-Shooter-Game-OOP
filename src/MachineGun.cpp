#include "Machinegun.h"
using namespace std;

void MachineGun::shoot(vector <Bullet> &bullet, double x,double y)
{
    bullet.push_back(Bullet(x,y,0,-7));


}

double MachineGun::getRate()
{
    return 0.2; // Fast
}