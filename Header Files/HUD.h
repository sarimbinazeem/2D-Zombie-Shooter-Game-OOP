#ifndef HUD_H
#define HUD_H

#include "Player.h"
#include "WaveManager.h"

class HUD
{
    public:
        HUD();
        void draw(Player& player, WaveManager& waves);

};

#endif