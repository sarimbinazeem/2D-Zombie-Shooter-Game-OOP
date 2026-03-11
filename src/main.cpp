#include <raylib.h>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth,screenHeight,"2D-Zombie Shooter Game");

    SetTargetFPS(60);
    
    int playerX = 400;
    int playerY = 300;
    int playerSize = 50;
    int playerSpeed = 7;

    while(!WindowShouldClose())
    {
        if(IsKeyDown(KEY_W))
        {
            playerY -= playerSpeed;
        }

        if(IsKeyDown(KEY_S))
        {
            playerY += playerSpeed;
        }

        if(IsKeyDown(KEY_A))
        {
            playerX -= playerSpeed;
        }

        if(IsKeyDown(KEY_A))
        {
            playerX += playerSpeed;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(playerX,playerY,playerSize,playerSize,BLUE);
        EndDrawing();

    }

    CloseWindow();

    return 0;

}
