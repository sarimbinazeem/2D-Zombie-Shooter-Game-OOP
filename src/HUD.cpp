#include "../Header Files/HUD.h"
#include "raylib.h"

HUD::HUD()
{

}

void HUD::draw(Player& player, WaveManager& waves)
{
    // Main HUD Bar at top
    DrawRectangle(10,10,780,90,Fade(LIGHTGRAY,0.85));
    DrawRectangleLines(10,10,780,90,BLACK);


    // HEALTH 

    // Label
    DrawText(TextFormat("Health: %d",player.getHealth()),20,20,20,BLACK);

    // Health bar background
    DrawRectangle(20,45,200,20,GRAY);


    // Dynamic HP color
    Color healthColor;

    if(player.getHealth()>50)
    {
        healthColor=GREEN;
    }
    else if(player.getHealth()>20)
    {
        healthColor=YELLOW;
    }
    else
    {
        healthColor=RED;
    }


    // Health bar width
    int barWidth = player.getHealth()*2;

    if(barWidth>200)
    {
        barWidth=200;
    }


    // Filled health bar
    DrawRectangle(20,45,barWidth,20,healthColor);

    // Border
    DrawRectangleLines(20,45,200,20,BLACK);


    //MONEY 

    DrawText(
    TextFormat("Money: %d",player.getMoney()),20,72,20,DARKGREEN);


    // WAVE 

    DrawText(TextFormat("Wave: %d",waves.getWave()),560,20,20,RED);


    //  WEAPON

    DrawText(TextFormat("Weapon: %s",player.getWeapon()->getName()),500,50,20,DARKBLUE);

}