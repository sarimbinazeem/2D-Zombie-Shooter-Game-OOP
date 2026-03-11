#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "raylib.h"
#include "Player.h"
#include "Zombie.h"
using namespace std;

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"2D-Zombie Shooter Game");
    SetTargetFPS(60);

    Player player;
    vector <Zombie> zombies;


    while(!WindowShouldClose())
    {
        int spawn = 0 ;
        player.move();

        spawn++;
        if(spawn>300) //5seconds at 60FPS
        {
             float zombX = rand() % 800;
             float zombY= rand() % 600;

             zombies.push_back(Zombie(zombX,zombY));
        }
        //&z is used because we want to make change in the variables of z object
        for(auto &z: zombies)
        {
            z.moveTowards(player.getX(),player.getY());
            double dx = player.getX() - z.getX();
            double dy = player.getY() - z.getY();

            double length = sqrt(pow(dx,2)+ pow(dy,2));

            //To check for collision between zombie and player
            //The distance between the bodies should be equal to sum of radii of the bodies during collisiom
            if(length> ((player.getWidth())/2 + z.getRadius())) 
            {
                player.takeDamage(z.getDamage());
            }
        }

        /*Alternative of using auto
        for(std::vector<Zombie>::iterator it = zombies.begin(); it != zombies.end(); ++it) where 'it' is iterator that points towrards zombies[0] till the last  
        */

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
