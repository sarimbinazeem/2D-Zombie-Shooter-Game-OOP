#include <iostream>
#include <cstdlib>
#include <vector>
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

    for(int i=0;i<5;i++)
    {
        float zombX = rand() % 800;
        float zombY= rand() % 600;

        zombies.push_back(Zombie(zombX,zombY));
    }

    while(!WindowShouldClose())
    {
        player.move();

        BeginDrawing();
        ClearBackground(RAYWHITE);
    
        player.draw();
        DrawText(TextFormat("Health: %d", player.getHealth()), 10, 10, 20, RED);
        DrawFPS(700,10);

        EndDrawing();

    }

    CloseWindow();

    return 0;

}
