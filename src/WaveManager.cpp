#include "WaveManager.h"
#include <cstdlib>

WaveManager::WaveManager() 
{
    wave = 1;
}

void WaveManager::startWave(vector<Enemy>& enemies, int screenWidth, int screenHeight) 
{
     int zombiesNum = wave * 3;

    for(int i=0;i<numZombies;i++)
    {
            int side = rand()%4;
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
                    break;
                

            }

            if(wave >= 3 && rand()%5 == 0)  // rand%5 == 0 means 20% chance to spawn a fast zombie
            {
                enemies.push_back(new TankZombie(zombX,zombY));

            }

            else if(wave >= 2 && rand()%3 == 0) //rand%3 == 0 means 33% chance to spawn a fast zombie 
            {

                enemies.push_back(new FastZombie(zombX,zombY));
            }

            else
            {
                enemies.push_back(new Zombie(zombX,zombY));

            }
            
             spawn = 0;
        }
    }
}