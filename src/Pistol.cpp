#include "Pistol.h"
using namespace std;

void Pistol::shoot(vector <Bullet> &bullet, double x,double y)
{
    bullet.push_back(Bullet(x,y,0,-5));

}

double Pistol::getRate()
{
    return 0.5; //Slow
}