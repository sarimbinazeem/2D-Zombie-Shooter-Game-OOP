#include "Pistol.h"
using namespace std;

void Pistol::shoot(vector<Bullet>& bullet, double x, double y, float directionX, float directionY)
{
    bullet.push_back(Bullet(x,y,directionX,directionY));

}

double Pistol::getRate()
{
    return 0.5; //Slow
}

const char* Pistol::getName()
{
   return "Pistol";
}