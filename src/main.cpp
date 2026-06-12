#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>
#include "raylib.h"
#include "../Header Files/Player.h"

#include "../Header Files/Enemy.h"
#include "../Header Files/FastZombie.h"
#include "../Header Files/TankZombie.h"
#include "../Header Files/Zombie.h"

#include "../Header Files/Bullet.h"

#include "../Header Files/Weapon.h"
#include "../Header Files/Pistol.h"
#include "../Header Files/Shotgun.h"
#include  "../Header Files/MachineGun.h"

#include "../Header Files/WaveManager.h"

#include "../Header Files/Shop.h"

#include "../Header Files/HUD.h"

#include "../Header Files/FileManager.h"

using namespace std;


enum GameState
{
    MENU, //0th index
    PLAYING, //1st index
    SHOP, //2nd index
    GAME_OVER
};

//Default start with MENU
GameState gameState = MENU;


int main()
{
     int screenWidth = 1200;
     int screenHeight = 800;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE); //To make the window resizable
    InitWindow(screenWidth,screenHeight,"2D-Zombie Shooter Game");
    SetTargetFPS(60);
    InitAudioDevice();
    

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
    waveManager.startWave();

    //HUD object
    HUD hud;

    //Shop object Creation
    Shop shop;
    
    //File Manager Object Creation
     FileManager file;
     file.loadData();  

     //File Times
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

    //Background Image
    Texture2D background= LoadTexture("Assets/background.png");
     Texture2D homepage= LoadTexture("Assets/homepage.png");

    Texture2D zombie = LoadTexture("Assets/zombie.png");

    Texture2D fastZombie = LoadTexture("Assets/fastZombie.png");

    Texture2D tankZombie= LoadTexture("Assets/tankZombie.png");

    Zombie::setTexture(zombie);

    FastZombie::setTexture(fastZombie);

    TankZombie::setTexture(tankZombie);


    Font zombieFont = LoadFont("Assets/Zombie.otf");
    Font instructionsFont = LoadFont("Assets/Instructions.ttf");

    //Audio
    Music bgMusic = LoadMusicStream("Assets/music.mp3");

    Sound zombieHitSound = LoadSound("Assets/zombiehit.wav");

    Sound gameOverSound = LoadSound("Assets/gameover.wav");

    PlayMusicStream(bgMusic);

    //Instruction Variables
    bool showInstructions = false;
    float instructionWidth = 40.0f;
    Rectangle instructionButton = {0, 150, instructionWidth, 300};

    while(!WindowShouldClose())
    {
        UpdateMusicStream(bgMusic);
        BeginDrawing();

        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
            // player.updateScale(); // Update player scale when toggling fullscreen
        }
        

        if(gameState == MENU)
        {
             DrawTexturePro(homepage, Rectangle{0, 0, (float)homepage.width, (float)homepage.height},Rectangle{0, 0, (float)screenWidth, (float)screenHeight},Vector2{0, 0},0.0f,WHITE);

            DrawRectangle(0,0,screenWidth,screenHeight,Fade(BLACK,0.35f));

            const char* title = "NUCES OUTBREAK";

            Vector2 size =  MeasureTextEx(zombieFont, title, 100, 2);
            
            float x = (GetScreenWidth() - size.x) / 2;
            float y = 30;

            DrawTextEx(zombieFont, title, Vector2{x+3, y+3}, 100, 2, MAROON);

            DrawTextEx(zombieFont, title, Vector2{x, y}, 100, 2, RED);

            const char* startText = "PRESS ENTER TO START";

            Vector2 startSize = MeasureTextEx(zombieFont, startText, 50, 2);

            float startX = (GetScreenWidth() - startSize.x) / 2;
            float startY = GetScreenHeight() - 120;

            // blinking effect
            float alpha = (sin(GetTime() * 5) + 1) / 2;

            DrawTextEx(zombieFont,startText, Vector2{startX, startY},  50, 2, Fade(WHITE, alpha));
            
            // Instructions Button
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), instructionButton))
            {
                showInstructions = !showInstructions;
            }

            if(showInstructions && instructionWidth <350)
            {
                instructionWidth += 10; // Increase width to reveal instructions
            }
            else if(!showInstructions && instructionWidth > 40)
            {
                instructionWidth -= 10; // Decrease width to hide instructions
            }

            DrawRectangle(0, 100, (int)instructionWidth, 300, GRAY);
            
                DrawTextEx(instructionsFont, "I", {12, 110}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "N", {12, 135}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "S", {12, 160}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "T", {12, 185}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "R", {12, 210}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "U", {12, 235}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "C", {12, 260}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "T", {12, 285}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "I", {12, 310}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "O", {12, 335}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "N", {12, 360}, 20, 1, MAROON);
                DrawTextEx(instructionsFont, "S", {12, 385}, 20, 1, MAROON);

                if(instructionWidth > 300)
                {
                    DrawTextEx(instructionsFont, "CONTROLS", {60, 120}, 30, 1, MAROON);

                    DrawTextEx(instructionsFont, "LEFT MB - Shoot", {60, 170}, 25, 1, WHITE);
                    DrawTextEx(instructionsFont, "X - Open Shop", {60, 210}, 25, 1, WHITE);
                    DrawTextEx(instructionsFont, "TAB - Open Last Records", {60, 250}, 25, 1, WHITE);
                    DrawTextEx(instructionsFont, "1 - Pistol", {60, 290}, 25, 1, WHITE);
                    DrawTextEx(instructionsFont, "2 - Shotgun", {60, 320}, 25, 1, WHITE);
                    DrawTextEx(instructionsFont, "3 - Machine Gun", {60, 350}, 25, 1, WHITE);
                }

            if(IsKeyPressed(KEY_ENTER))
            {
                StopMusicStream(bgMusic);
                gameState = PLAYING;
            }
        }
        else if(gameState == PLAYING)
        {
            DrawTexturePro(background, Rectangle{0, 0, (float)background.width, (float)background.height},Rectangle{0, 0, (float)screenWidth, (float)screenHeight},Vector2{0, 0},0.0f,WHITE);
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
                        if(player.getHealth() <= 0)
                        {
                            gameState = GAME_OVER;
                            PlaySound(gameOverSound);
                        }
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
                if(player.hasShotgun())
                {
                    player.setWeapon(&shotgun);

                }
            }
            else if(IsKeyPressed(KEY_THREE))
            {
                if(player.hasMachineGun())
                {
                    player.setWeapon(&machineGun);

                }
            }

            //Fire Rate Logic
            static double lastShotTime = 0.0;

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                double currentTime = GetTime();

                if(player.getWeapon() != nullptr && (currentTime - lastShotTime) >= player.getWeapon()->getRate())
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
                
                if(shop.isOpen())
                {
                    gameState =SHOP;
                }
            }
            
             
            

            //==========Erasing==========
            //Erasing The Useless Bulllets And Zombies
            for(size_t i=0; i<bullets.size(); i++)
            {

                //To Check If Bullet and Zombies Have Collided Or Not
                Vector2 bulletPos = bullets[i].getPosition();

                //Removing the ofscreen bullets (so that it doesnt exist forever)
                if(bullets[i].getPosition().x > screenWidth  || bullets[i].getPosition().x <0 || bullets[i].getPosition().y > screenHeight || bullets[i].getPosition().y < 0)
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
                        PlaySound(zombieHitSound);

                        if(!enemies[j]->isAlive())
                        {
                            player += enemies[j]->getReward(); 

                            delete enemies[j];
                            enemies.erase(enemies.begin()+j);
                        }

                        break; //because bullet doesnt exist so skip this bullet loop and move to next
                    }
                }

                
            }

            //==========Next Wave Logic==========
            waveManager.spawnGradually(enemies,screenWidth,screenHeight);
            waveManager.checkWaveComplete( enemies,screenWidth,screenHeight);
            
            //Saving the data into the file
            file.saveData(waveManager.getWave(),player.getMoney(),player.getWeapon()->getName(),currentDay,currentTime);

             //==========Drawing Logic==========
            
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



            //======File-======

            if(IsKeyDown(KEY_TAB))
            {
                int recordWidth = 270;
                int recordHeight = 110;
                
                //Midpoint
                int x = (screenWidth -recordWidth)/2;
                int y = (screenHeight - recordHeight)/2;
                
                DrawRectangle(x,y,recordWidth,recordHeight,LIGHTGRAY);
                DrawRectangleLines(x,y,recordWidth,recordHeight,BLACK);
                
                DrawText("=== RECORDS ===",x + 40, y + 10,20,DARKBLUE);

                DrawText(TextFormat("Wave: %d",file.getHighWave()),x + 20, y + 40,20,BLACK);

                //c_str() turns string to const char* because DrawText only accepts const char* and not string
                DrawText( TextFormat("Weapon: %s",file.getBestWeapon().c_str()),x + 20,y + 65,20,BLACK);

                DrawText(TextFormat("%s %s",file.getRecordDay().c_str(),file.getRecordTime().c_str()),x + 20,y + 90,18,BLACK);

            }

            //Shop
            if(shop.isOpen())
            {
                shop.drawShop();
            }
            
        }
            
        else if(gameState == SHOP)
        {
            // Background when the shop is open
            DrawTexturePro(background,Rectangle{0, 0, (float)background.width, (float)background.height},Rectangle{0, 0, (float)screenWidth, (float)screenHeight}, Vector2{0, 0}, 0.0f, WHITE);
            
            //Frozen entities
            // Draw player 
            player.draw();

            // Draw enemies
            for(auto &e : enemies)
            {
                e->draw();
            }

            // Draw  bullets
            for(size_t i=0; i<bullets.size(); i++)
            {
                bullets[i].drawBullet();
            }

            // Draw HUD
            hud.draw(player,waveManager);

            // Draw shop menu
            shop.drawShop();

            DrawText("GAME PAUSED",300,20,30,YELLOW);


            // The Shope Meny
            if(IsKeyPressed(KEY_Q))
            {
                shop.buyShotgun(player);
            }
            
            if(IsKeyPressed(KEY_E))
            {
                shop.buyMachineGun(player);
            }
            
            if(IsKeyPressed(KEY_R))
            {
                shop.upgradeHealth(player);
            }
            
            if(IsKeyPressed(KEY_T))
            {
                 shop.upgradeSpeed(player);
            }

            // Press X again to go out of the shop
            if(IsKeyPressed(KEY_X))
            {
                shop.toggleShop();
                gameState = PLAYING;
            }
        }    
        else if(gameState == GAME_OVER)
        {
            ClearBackground(DARKGREEN);
            DrawText("GAME OVER",  screenWidth/2 - MeasureText("GAME OVER", 60)/2,  screenHeight/3, 60, RED);

            DrawText("PRESS Z TO RESTART",screenWidth/2 - MeasureText("PRESS Z TO RESTART", 30)/2, screenHeight/2,30,BLACK);
            DrawText(TextFormat("Wave Reached: %d",waveManager.getWave()),265,260,30,BLACK);
            

            if(IsKeyPressed(KEY_Z))
            {
                //Resetting everything
                //  PLAYER
                player.reset();

                //  WEAPON
                player.setWeapon(&pistol);

                //  ENEMIES
                for(auto e: enemies)
                {

                    delete e;
                }

                enemies.clear();

                //  BULLETS
                bullets.clear();

                //  WAVES
                waveManager = WaveManager();
                waveManager.startWave();

                // Start playing agaibn
                gameState = PLAYING;
            }
        }
         EndDrawing();
        
    }

    //Memory Cleanup

    for(auto e: enemies)
    {
        delete e;
    }
    
    UnloadFont(zombieFont);
    UnloadFont(instructionsFont);

    UnloadTexture(background);
    UnloadTexture(homepage);
    UnloadMusicStream(bgMusic);
    UnloadTexture(zombie);
    UnloadTexture(fastZombie);
    UnloadTexture(tankZombie);

   
    UnloadSound(zombieHitSound);
    UnloadSound(gameOverSound);
    CloseWindow();
    CloseAudioDevice();
    return 0;

}
