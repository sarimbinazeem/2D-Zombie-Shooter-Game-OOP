#include "FileManager.h"
#include <fstream>

using namespace std;

FileManager::FileManager()
{
    highWave=0;
    highScore=0;
    recordDay="None";
    recordTime="None";
    bestWeapon="Pistol";
}

void FileManager::loadData()
{
    ifstream inFile("game.txt");

    if(inFile.is_open())
    {
        inFile >> highWave;
        inFile >> highScore;
        inFile >> recordDay;
        inFile >> recordTime;
        inFile >> bestWeapon;
        inFile.close();
    }
}