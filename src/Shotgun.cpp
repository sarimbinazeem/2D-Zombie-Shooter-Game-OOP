#include "Shotgun.h"
using namespace std;

void Shotgun::shoot(vector<Bullet>& bullet, double x, double y, float directionX, float directionY)
{
    bullet.push_back(Bullet(x,y,directionX - 0.2f,directionY));
    bullet.push_back(Bullet(x,y,directionX,directionY));
    bullet.push_back(Bullet(x,y,directionX + 0.2f,directionY));

}

double Shotgun::getRate()
{
    return 1.0; // Slower
}