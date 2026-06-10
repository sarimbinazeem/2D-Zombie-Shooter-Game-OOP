#include "../Header Files/WaveManager.h"
#include <cstdlib>

WaveManager::WaveManager() 
{
    wave = 1;
    zombiesRemaining = 0;
    spawnTimer = 0.0f;
    spawnDelay = 1.0f;
}

void WaveManager::startWave() 
{
    //Increasing zombies number per wave number
    zombiesRemaining = wave * 3;
  
    spawnTimer = 0.0f;  
}

void WaveManager::checkWaveComplete( vector<Enemy*>& enemies,int screenWidth,int screenHeight)
{
    //If Zombies Are All Dead Start New Wave
    if(enemies.empty() && zombiesRemaining<=0)
    {
        //Move to Next Wave
        wave++;

        startWave();
    }
}

int WaveManager::getWave()
{
    return wave;
}

void WaveManager::spawnGradually( vector<Enemy*>& enemies,int screenWidth,int screenHeight)
{
     // Add elapsed frame time
    spawnTimer += GetFrameTime();

    // Spawn timer should pass SPAWN delay
    if(spawnTimer < spawnDelay)
    {
        return;
    }

    // Stop if all zombies for this wave have spawned
    if(zombiesRemaining <= 0)
    {
        return;
    }

    // reset timer for next spawn
    spawnTimer = 0;


    // -------- Spawn ONE zombie only --------

    int side = rand()%4;

    float zombX =screenWidth;
    float zombY = screenHeight;
    float margin = 50; // safe spawn distance outside screen

    //Randomly decide the side of the screen to spawn the zombie
    switch(side)
    {
        case 0: // top
            zombX = rand() % screenWidth; 
            zombY = -margin; // negative to spawn above the screen
            break;

        case 1: // bottom
            zombX = rand() % screenWidth;
            zombY = screenHeight + margin; 
            break;

        case 2: // left
            zombX = -margin;
            zombY = rand() % screenHeight;
            break;

        case 3: // right
            zombX = screenWidth + margin;
            zombY = rand() % screenHeight;
            break;
    }


    if(wave >=3 && rand()%5==0)
    {
        enemies.push_back(new TankZombie(zombX,zombY));
    }

    else if(wave>=2 && rand()%3==0)
    {
        enemies.push_back(new FastZombie(zombX,zombY));
    }

    else
    {
        enemies.push_back( new Zombie(zombX,zombY));
    }


    zombiesRemaining--;
}
    
