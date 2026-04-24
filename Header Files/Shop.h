#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include "Player.h"
using namespace std;



class Player;

class Shop
{
    private:
        bool open;

    public:
        //COnstructor
        Shop();

        //On and Off Functions
        void toggleShop();
        bool isOpen();

        //Raylib function
        void drawShop();

        //Weapon Upgrades Functions
        //&player used so that we can modify later
        void buyShotgun(Player& player);
        void buyMachineGun(Player& player);

        //Player Upgrades Functions
        void upgradeHealth(Player& player);
        void upgradeSpeed(Player& player);
};

#endif