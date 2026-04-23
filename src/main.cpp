#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
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

    int spawn = 0 ;
    
    while(!WindowShouldClose())
    {
        //==========Player==========
        //Player Move Logic
        player.move();

        //==========Enemy==========
        
        //Enemy Spawning Logic
        spawn++;
        if(spawn>300 && enemies.size() < 20) //5seconds at 60FPS and 20 max Enemy spawn for now
        {
            int type = rand() % 3;
            int side  = rand() % 4;

            float zombX  = 50;
            float zombY = 10; 

            switch(side)
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
                

            }

            if(type==0)
            {
                enemies.push_back(new Zombie(zombX,zombY));

            }

            else if(type==1)
            {

                enemies.push_back(new FastZombie(zombX,zombY));
            }

            else
            {
                enemies.push_back(new TankZombie(zombX,zombY));

            }
            
             spawn = 0;
        }
        
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
        double damageTimer = 0;
        damageTimer++;
         static double lastDamageTime = 0;


        for(size_t i=0; i<enemies.size(); i++)
        {
    
            for(size_t i=0; i<enemies.size(); i++)
            {
                Vector2 enemyPos = enemies[i]->getPosition();

                double dx = player.getX() - enemyPos.x;
                double dy = player.getY() - enemyPos.y;

                double dist = sqrt(dx*dx + dy*dy);

                if(dist <= player.getWidth()/2 + enemies[i]->getRadius())
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
                        delete enemies[j];
                        enemies.erase(enemies.begin()+j);
                    }

                    break; //because bullet doesnt exist so skip this bullet loop and move to next
                }
            }

            
        }

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

        //HP BAR
        DrawText(TextFormat("Health: %d", player.getHealth()), 10, 10, 20, RED);



        
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
