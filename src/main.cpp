#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "raylib.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
#include "Weapon.h"
#include "Pistol.h"
#include "Shotgun.h"
#include  "MachineGun.h"
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

    //Vector Zombie created so that there is no size limit on creation of zombie
    vector <Zombie> zombies;

    //Bullets  Vector so that there are no limits on creation of bullets 
    vector<Bullet> bullets;

    int spawn = 0 ;
    
    while(!WindowShouldClose())
    {
        //==========Player==========
        //Player Move Logic
        player.move();

        //==========Zombie==========
        
        //Zombie Spawning Logic
        spawn++;
        if(spawn>300 && zombies.size() < 20) //5seconds at 60FPS and 20 max zombies spawn for now
        {
            int zombie = rand() % 4;
            float zombX  = 50;
            float zombY = 10; 

            switch(zombie)
            {
                case 0: // top
                    zombX = rand() % screenWidth;
                    zombY = 0;
                    break;
                    
                case 1: // bottom
                    zombX = rand() % screenWidth;
                    zombY = screenHeight;
                    break;
                    
                case 2: // left
                    zombX = 0;
                    zombY = rand() % screenHeight;
                    break;
                    
                case 3: // right
                    zombX = screenWidth;
                    zombY = rand() % screenHeight;
                    break;
            }
             zombies.push_back(Zombie(zombX,zombY));
             spawn = 0;
        }
        
        //Zombie Move Towards Player Logic
        //&z is used because we want to make change in the variables of z object
        for(auto &z: zombies)
        {
            z.moveTowards(player.getX(),player.getY());
            double dx = player.getX() - z.getX();
            double dy = player.getY() - z.getY();

            double length = sqrt(pow(dx,2)+ pow(dy,2));

            //To check for collision between zombie and player
            //The distance between the bodies should be equal to sum of radii of the bodies during collisiom
            if(length < ((player.getWidth())/2 + z.getRadius())) 
            {
                player.takeDamage(z.getDamage());
            }
        }
        /*Alternative of using auto
        for(vector<Zombie>::iterator it = zombies.begin(); it != zombies.end(); ++it) where 'it' is iterator that points towrards zombies[0] till the last  
        */

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


       //==========Drawing Logic==========
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        //Player
        player.draw();

        //Zombie
        for(auto &z: zombies)
        {
            z.draw();
        }

        //Bullets
        for(size_t i=0; i<bullets.size(); i++)
        {
            bullets[i].drawBullet();

        }

        //HP BAR
        DrawText(TextFormat("Health: %d", player.getHealth()), 10, 10, 20, RED);


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

            for(size_t j=0; j<zombies.size(); j++)
            {
               Vector2 zombiePos = zombies[j].getPosition();

                double dx = bulletPos.x - zombiePos.x;
                double dy = bulletPos.y - zombiePos.y;

                double length = sqrt(pow(dx,2)+ pow(dy,2)); //The distance between Zombie and Bullet
                int radius = bullets[i].getRadius() + zombies[j].getRadius();
                if(length <= radius )
                {
                    bullets.erase(bullets.begin() + i);
                    i--;
                    zombies.erase(zombies.begin() + j);
                    j--;

                    break; //because bullet doesnt exist so skip this bullet loop and move to next
                }
            }

            
        }

        
        EndDrawing();

    }

    CloseWindow();

    return 0;

}
