#include "FastZombie.h"

FastZombie::FastZombie() : Zombie()
{
    this->speed = 2.0f; 
    this->health = 75; 
}

FastZombie::FastZombie(float x, float y) : Zombie(x, y)
{
    this->speed = 2.0f; 
    this->health = 75; 
}

