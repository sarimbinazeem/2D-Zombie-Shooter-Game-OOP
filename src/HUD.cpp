#include "HUD.h"
#include "raylib.h"

HUD::HUD()
{

}

void HUD::draw(Player& player, WaveManager& waves)
{
    //HP Bar
    //HP text
    DrawText(TextFormat("Health: %d",player.getHealth()),20,20,20,BLACK);


    //Draw rectangle take x,y,width,height,color 
    //Background of bar
    DrawRectangle(20,20,200,20,GRAY);

    //Changing of color of health bar accordinng to health
    string healthColor;
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

    //Preventation of bug that helps to limit the bar to a certain level (100% health = 200 pixels of bar)
    int barWidth=player.getHealth()*2;

    if(barWidth>200)
    {
        barWidth=200;
    }

    //Color filled bar that changes size based on health so that when health = 50 it fills 100 pixels of the bar (half bar)
    DrawRectangle(20,20,barWidth,20,GREEN);

    //Border of bar
    DrawRectangleLines(20,20,200,20,BLACK);

    //Left has money and health bar
    //Right has weapon and wave bar

    
    //Money Bar
    DrawText(TextFormat("Money: %d", player.getMoney()),20,50,20,BLACK);

    //Wave Counter
    DrawText(TextFormat("Wave: %d",waves.getWave()),620,20,20,BLACK);

    //Weapon Shower
    DrawText(TextFormat("Weapon: %s",player.getWeapon()->getName()),550,50,20,BLACK);

}