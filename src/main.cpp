#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "raylib.h"
#include "Player.h"
#include "Zombie.h"
#include "Bullet.h"
using namespace std;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"2D-Zombie Shooter Game");
    SetTargetFPS(60);

    Player player;
    //Vector Zombie created so that there is no size limit on creation of zombie
    vector <Zombie> zombies;


    int spawn = 0 ;
    while(!WindowShouldClose())
    {
        //Player Move Logic
        player.move();
        
        //Zombie Spawning Logic
        spawn++;
        if(spawn>300 && zombies.size() < 20) //5seconds at 60FPS and 20 max zombies spawn for now
        {
            int zombie = rand() % 4;
            float zombX, zombY;

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

       //Bullets  Vector so that there are no limits on creation of bullets 
        vector<Bullet> bullets;

        //Bullet Shooting Logic
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 mouse = GetMousePosition();
            Vector2 playerPosition = {player.getX(), player.getY()};
            
            //The direction of bullet is normalized to cover equal distances in equal time
            Vector2 direction;
            direction.x = mouse.x = playerPosition.x;
            direction.y = mouse.y - playerPosition.y;

            double length = sqrt(pow(direction.x ,2)+ pow(direction.y ,2)); //The distance between Mouse and Player

            //Edge Case
             if(length!= 0)
            {
                direction.x = direction.x/length;
                direction.y  = direction.y /length;
            }

            //Create a bullet that goes where mouse aims at smoothly
            bullets.push_back(Bullet(playerPosition.x,playerPosition.y,direction.x,direction.y));
        }

        //Updating Bullet Position
        for(int i=0;i<bullets.size(); i++)
        {
            bullets[i].updateDirection();
        }

       //Drawing Logic
        BeginDrawing();
        ClearBackground(RAYWHITE);
    
        player.draw();
        for(auto &z: zombies)
        {
            z.draw();
        }
        DrawText(TextFormat("Health: %d", player.getHealth()), 10, 10, 20, RED);

        EndDrawing();

    }

    CloseWindow();

    return 0;

}
