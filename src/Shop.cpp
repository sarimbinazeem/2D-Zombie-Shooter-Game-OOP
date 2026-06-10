#include "../Header Files/Shop.h"

#include "../Header Files/Shotgun.h"
#include "../Header Files/MachineGun.h"

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
    //It checks if player has the required money and have no shotgun
    if(player.getMoney() >= 200 && !player.hasShotgun())
    {
        player.spendMoney(200);

        player.unlockShotgun();

        cout<<"You bought a Shotgun!"<<endl;
    }
    else
    {
        cout<<"You don't have enough money to buy a Shotgun!"<<endl;
    }
}

void Shop::buyMachineGun(Player &player)
{
    if(player.getMoney() >= 400 && !player.hasMachineGun())
    {
        player.spendMoney(400);

        player.unlockMachineGun();

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

        //friend class
        player.health += 25;

        cout<<"Health Upgraded\n";
    }
}

void Shop::upgradeSpeed(Player& player)
{
    if(player.getMoney() >=60)
    {
        player.spendMoney(60);

        //friend class
        player.speed +=1;

        cout<<"Speed Increased\n";
    }
}

void Shop::drawShop()
{
    //To Dim The Background Gameplay
    DrawRectangle(0,0, GetScreenWidth(), GetScreenHeight(),Fade(BLACK,0.4f));

    //Shop in rectangle background
    int shopWidth = 400;
    int shopHeight = 300;

    int shopX = (GetScreenWidth() - shopWidth) / 2;
    int shopY = (GetScreenHeight() - shopHeight) / 2;
    DrawRectangle(shopX,shopY,shopWidth,shopHeight,LIGHTGRAY);
    DrawRectangleLines(shopX,shopY,shopWidth,shopHeight,BLACK);

   DrawText("WEAPON SHOP",shopX + 100,shopY + 25,30,RED);

    DrawText("Q- Buy Shotgun ($200)",shopX + 40,shopY + 80,22,BLACK);

   DrawText("E Buy Machine Gun ($400)",shopX + 40,shopY + 120,22,BLACK);

    DrawText("R Health Upgrade by +25 ($80)",shopX + 40,shopY + 160,22,BLACK);

    DrawText("T Speed Upgrade by +1 ($60)",shopX + 40,shopY + 200,22,BLACK);

    DrawText("Press X to close shop",shopX + 60,shopY + 260,20,BLUE);
}