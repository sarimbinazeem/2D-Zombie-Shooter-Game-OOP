#include "raylib.h"
#include "Player.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"2D-Zombie Shooter Game");

    SetTargetFPS(60);
    
    Player player;

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
