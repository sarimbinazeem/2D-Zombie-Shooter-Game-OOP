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
        int wave;

    public:

        WaveManager();

        void startWave(vector<Enemy*>& enemies,int screenWidth,int screenHeight);

        void checkWaveComplete(vector<Enemy*>& enemies,int screenWidth, int screenHeight);

        int getWave();

};

#endif