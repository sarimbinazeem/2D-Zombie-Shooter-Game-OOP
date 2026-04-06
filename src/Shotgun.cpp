#include "Shotgun.h"
using namespace std;

void Shotgun::shoot(vector <Bullet> &bullet, double x,double y)
{
    bullet.push_back(Bullet(x,y,-2,-5));
    bullet.push_back(Bullet(x,y,0,-5));
    bullet.push_back(Bullet(x,y,2,-5));

}

double Shotgun::getRate()
{
    return 1.0; // Slower
}