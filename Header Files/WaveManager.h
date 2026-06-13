#ifndef WAVEMANAGER_H
#define WAVEMANAGER_H

#include <vector>
#include "Zombie.h"
#include "FastZombie.h"
#include "TankZombie.h"

using namespace std;

class WaveManager
{
    private:
        int zombiesRemaining;
        float spawnTimer;
        float spawnDelay;
        int wave;

        bool waveBreak;
        float breakTimer;


    public:

        WaveManager();

        void startWave();

        void checkWaveComplete( vector<Enemy*>& enemies,int screenWidth,int screenHeight);

        int getWave();

        void spawnGradually(vector<Enemy*>& enemies,int screenWidth,int screenHeight);

        bool isWaveBreak();
        float getWaveBreakTimer();
};

#endif