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
    //To Dim The Background Gameplay
    DrawRectangle(0,0,800,600,Fade(BLACK,0.4));

    //Shop in rectangle background
    DrawRectangle(200,120,400,300,LIGHTGRAY);
    DrawRectangleLines(200,120,400,300,BLACK);

    DrawText("WEAPON SHOP",300,145,30,RED);

    DrawText("1- Buy Shotgun ($100)",240,200,22,BLACK);

    DrawText("2 Buy Machine Gun ($250)",240,240,22,BLACK);

    DrawText("3 Health Upgrade by +50 ($80)",240,280,22,BLACK);

    DrawText("4 Speed Upgrade by +1 ($50)",240,320,22,BLACK);

    DrawText("Press X to close shop",260,380,20,BLUE);
}