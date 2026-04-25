#include "HUD.h"
#include "raylib.h"

HUD::HUD()
{

}

void HUD::draw(Player& player, WaveManager& waves)
{
    //HP Bar
    DrawText(TextFormat("Health: %d",player.getHealth()),20,20,20,BLACK);

    //Money Bar
    DrawText(TextFormat("Money: %d", player.getMoney()),20,50,20,BLACK);

    //Wave Counter
    DrawText(TextFormat("Wave: %d",waves.getWave()),20,80,20,BLACK);

    //Weapon Shower
    DrawText(TextFormat("Weapon: %s",player.getWeapon()->getName()),20,110,20,BLACK);

}