#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Bullet.h"
#include <raylib.h>
#include "Weapon.h"

using namespace std;

class Player
{
    private:
        int health;
        double speed;
        float xPos;
        float yPos;
        int width;
        int height;
        int money;  

        bool shotgunUnlocked;
        bool machineGunUnlocked;

        Weapon* weapon;

        Texture2D pistolTexture;
        Texture2D shotgunTexture;
        Texture2D machineGunTexture;

    public:
        Player();
        
        void setWeapon(Weapon *w);
        void shoot(vector<Bullet>& bullets, float dirX, float dirY);

        void move();
        void draw();
        void takeDamage(double damage);

        int getHealth();
        float getX();
        float getY();
        double getWidth();
        double getHeight();
        Weapon* getWeapon();
        int getMoney();

        
        void addMoney(int amount);
        bool spendMoney(int amount);

        void increaseHealth(int amount);
        void increaseSpeed(float amount);

        void unlockShotgun();
        void unlockMachineGun();

        bool hasShotgun();
        bool hasMachineGun();

        ~Player();

};


#endif