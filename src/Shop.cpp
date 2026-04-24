#include "Shop.h"

#include "Shotgun.h"
#include "MachineGun.h"

#include <iostream>
using namespace std;


Shop::Shop()
{
    open = false;
}

void Shop::toggleShop()
{
    //revert the status of the shop
    open = !open;
}

bool Shop::isOpen()
{
    return open;
}

void Shop::buyShotgun(Player &player)
{
    if(player.getMoney() >= 200)
    {
        player.spendMoney(200);

        player.setWeapon(new Shotgun());

        cout<<"You bought a Shotgun!"<<endl;
    }
    else
    {
        cout<<"You don't have enough money to buy a Shotgun!"<<endl;
    }
}

void Shop::buyMachineGun(Player &player)
{
    if(player.getMoney() >= 400)
    {
        player.spendMoney(400);

        player.setWeapon(new MachineGun());

        cout<<"You bought a Machine Gun!"<<endl;
    }
    else
    {
        cout<<"You don't have enough money to buy a Machine Gun!"<<endl;
    }
}

void Shop::upgradeHealth(Player& player)
{
    if(player.getMoney() >= 80)
    {
        player.spendMoney(80);

        player.increaseHealth(40);

        cout<<"Health Upgraded\n";
    }
}

void Shop::upgradeSpeed(Player& player)
{
    if(player.getMoney() >=60)
    {
        player.spendMoney(60);

        player.increaseSpeed(1);

        cout<<"Speed Increased\n";
    }
}

void Shop::drawShop()
{
    DrawText("SHOP",300,100,30,BLACK);

    DrawText("1 Shotgun 100",250,150,20,BLACK);

    DrawText("2 Machine Gun 250",250,180,20,BLACK);

    DrawText("3 Health +50 75",250,210,20,BLACK);

    DrawText("4 Speed +1 50",250,240,20,BLACK);
}