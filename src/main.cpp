#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include "raylib.h"
#include "Player.h"

#include "Enemy.h"
#include "FastZombie.h"
#include "TankZombie.h"
#include "Zombie.h"

#include "Bullet.h"

#include "Weapon.h"
#include "Pistol.h"
#include "Shotgun.h"
#include  "MachineGun.h"

#include "WaveManager.h"

#include "Shop.h"

#include "HUD.h"

#include "FileManager.h"

using namespace std;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"2D-Zombie Shooter Game");
    SetTargetFPS(60);

    //Player Creation
    Player player;

    //Weapon Creation
    Pistol pistol;
    Shotgun shotgun;
    MachineGun machineGun;
    player.setWeapon(&pistol); // Default weapon is pistol

    //PolyMorphsim By Base Pointer 
    //Vector Enemy created so that there is no size limit on creation of Enemies
    vector<Enemy*> enemies;

    //Bullets  Vector so that there are no limits on creation of bullets 
    vector<Bullet> bullets;


    //Wave Object Creation
    WaveManager waveManager;

    // starting first wave
    waveManager.startWave(enemies,screenWidth,screenHeight);

    //HUD object
    HUD hud;

    //Shop object Creation
    Shop shop;
    
    //File Manager Object Creation
     FileManager file;
     file.loadData();  
    //time_t is used to store time in unreadable form
    time_t now = time(0); //time(0) gives time right now
    
    //tm is a structure having day of week, hour, mins, seconds
    tm *ltm = localtime(&now); //This converts time in unreadable parts into readable parts
    
    //days array
    string days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

    //ltm->tm_wday tells current day of the week
    string currentDay = days[ltm->tm_wday];
    
    //it tells hour and minutes that are stored in the respective ltm structure
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    
    //Hard Coding Am at first
    string ampm="AM";
    
    //if greater than 12 than it is pm
    if(hour>=12)
    {
        ampm="PM";
    }
    
    //if it is greater than 12 than minus by 12 (in no 24 hours format)
    if(hour>12)
    {
        hour-=12;
    }
    
    //if hour is 0 than it means it is 12 am
    if(hour==0)
    {
        hour=12;
    }
    
    //FOr minute
    string minuteText;

    if(minute<10)
    {
       minuteText="0"+to_string(minute); //gives minute in 05 format
    }
    
    else
    {
       minuteText=to_string(minute); 
    }
    
    string currentTime=to_string(hour)+":"+minuteText+ampm; //concatened string for format 5:00pm
    while(!WindowShouldClose())
    {
        //==========Player==========
        //Player Move Logic
        player.move();

        //==========Enemy==========
       
        //Enemy Move Towards Player Logic
        //&e is used because we want to make change in the variables of e object
        for(auto &e : enemies)
        {
            //Arrow operator used because e is base pointer
            e->update(player.getX(), player.getY());
        }

        /*Alternative of using auto
        for(vector<Zombie>::iterator it = zombies.begin(); it != zombies.end(); ++it) where 'it' is iterator that points towrards zombies[0] till the last  
        */
        // ZOMBIES DAMAGE PLAYER
        
        //After Every Cetain Time The Zombie Hit Player ( NOt evry frame but at a certain time now) 
         static double lastDamageTime = 0;


        for(size_t i=0; i<enemies.size(); i++)
        {
            Vector2 enemyPos = enemies[i]->getPosition();

            double dx = player.getX() - enemyPos.x;
            double dy = player.getY() - enemyPos.y;

            double distance = sqrt(dx*dx + dy*dy);

            if(distance <= player.getWidth()/2 + enemies[i]->getRadius())
            {
                 double currentTime = GetTime();
                    
                //Every Half A SECOND later hits player
                if(currentTime - lastDamageTime >= 0.5)
                {
                    player.takeDamage(enemies[i]->getDamage());
                    lastDamageTime = currentTime;
                }
            }
            
        }

        //==========Bullet==========

        //Bullet Shooting Logic
 

        //Updating Bullet Position
        for(size_t i=0;i<bullets.size(); i++)
        {
            bullets[i].updateDirection();
        }

        //==========Weapon==========
        //Weapon Switching Logic
        if(IsKeyPressed(KEY_ONE))
        {
            player.setWeapon(&pistol);
        }
        else if(IsKeyPressed(KEY_TWO))        
        {
            player.setWeapon(&shotgun);
        }
        else if(IsKeyPressed(KEY_THREE))
        {
            player.setWeapon(&machineGun);
        }

        //Fire Rate Logic
        static double lastShotTime = 0.0;

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            double currentTime = GetTime();

            if(currentTime - lastShotTime >= player.getWeapon()->getRate())
            {
                Vector2 mouse = GetMousePosition();

                float dx = mouse.x - player.getX();
                float dy = mouse.y - player.getY();

                float length = sqrt(dx*dx + dy*dy);

                if(length != 0)
                {
                    dx /= length;
                    dy /= length;
                }

                player.shoot(bullets, dx, dy);

                lastShotTime = currentTime;
            }
        }

        //==========Shop==========
        //Open shop with keyboard shortcut X
        if(IsKeyPressed(KEY_X))
        {
            shop.toggleShop();
        }
        
        //Shope Buying Shortcut
        if(shop.isOpen())
        {
            if(IsKeyPressed(KEY_ONE))
            {
                shop.buyShotgun(player);
            }

            if(IsKeyPressed(KEY_TWO))
            {
                shop.buyMachineGun(player);
            }

            if(IsKeyPressed(KEY_THREE))
            {
                shop.upgradeHealth(player);
            }

            if(IsKeyPressed(KEY_FOUR))
            {
                shop.upgradeHealth(player);
            }
        }

        //==========Erasing==========
        //Erasing The Useless Bulllets And Zombies
        for(size_t i=0; i<bullets.size(); i++)
        {

             //To Check If Bullet and Zombies Have Collided Or Not
             Vector2 bulletPos = bullets[i].getPosition();

             //Removing the ofscreen bullets (so that it doesnt exist forever)
            if(bullets[i].getPosition().x >800 || bullets[i].getPosition().x <0 || bullets[i].getPosition().y > 600 || bullets[i].getPosition().y < 0)
            {
                bullets.erase(bullets.begin() + i);
                i--; //Skipped so that the next bullet of the one that is removed is not skipped (Due To Vector Removing in between)
                continue;
             }

            for(size_t j=0; j<enemies.size(); j++)
            {
               Vector2 zombiePos = enemies[j]->getPosition();

                double dx = bulletPos.x - zombiePos.x;
                double dy = bulletPos.y - zombiePos.y;

                double length = sqrt(pow(dx,2)+ pow(dy,2)); //The distance between Zombie and Bullet
                int radius = bullets[i].getRadius() + enemies[j]->getRadius();
                if(length <= radius )
                {
                    bullets.erase(bullets.begin()+i);
                    i--;

                    enemies[j]->takeDamage(50);


                    if(!enemies[j]->isAlive())
                    {
                        player.addMoney(enemies[j]->getReward());

                        delete enemies[j];
                        enemies.erase(enemies.begin()+j);
                    }

                    break; //because bullet doesnt exist so skip this bullet loop and move to next
                }
            }

            
        }

        //==========Next Wave Logic==========
        waveManager.checkWaveComplete( enemies,screenWidth,screenHeight);
        
        //Saving the data into the file
        file.saveData(waveManager.getWave(),player.getMoney(),player.getWeapon()->getName(),currentDay,currentTime);

       //==========Drawing Logic==========
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        //Player
        player.draw();

        //Enemy
        for(auto &e : enemies)
        {
            e->draw();
        }

        //Bullets
        for(size_t i=0; i<bullets.size(); i++)
        {
            bullets[i].drawBullet();

        }

        //HUD drawing
        hud.draw(player,waveManager);

        DrawRectangle(560,15,220,110,LIGHTGRAY);
        DrawRectangleLines(560,15,220,110,BLACK);

        DrawText("=== RECORDS ===",590,25,20,DARKBLUE);

        DrawText(
        TextFormat("Wave: %i",file.getHighWave()),
        580,55,20,BLACK);

        DrawText(
        TextFormat("Weapon: %s",
        file.getBestWeapon().c_str()),
        580,80,20,BLACK);

        DrawText(
        TextFormat("%s %s",
        file.getRecordDay().c_str(),
        file.getRecordTime().c_str()),
        580,105,18,BLACK);

        //Shop
        if(shop.isOpen())
        {
            shop.drawShop();
        }
        
        
        EndDrawing();
    
    }

    //Memory Cleanup

    for(auto e: enemies)
    {
        delete e;
    }
    





    CloseWindow();

    return 0;

}
