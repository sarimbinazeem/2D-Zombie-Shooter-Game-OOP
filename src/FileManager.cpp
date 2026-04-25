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

void FileManager::saveData(int currentWave,int currentScore,string currentWeapon,string day,string time)
{

    if(currentWave > highWave)
    {
        highWave = currentWave;
        bestWeapon = currentWeapon;
        recordDay = day;
        recordTime = time;
    }


    if(currentScore > highScore)
    {
        highScore=currentScore;
    }


    ofstream outFile("save.txt");

    outFile << highWave << endl;
    outFile << highScore << endl;
    outFile << recordDay << endl;
    outFile << recordTime << endl;
    outFile << bestWeapon << endl;

    outFile.close();

}

int FileManager::getHighWave()
{
   return highWave;
}

int FileManager::getHighScore()
{
   return highScore;
}

string FileManager::getRecordDay()
{
   return recordDay;
}

string FileManager::getRecordTime()
{
   return recordTime;
}

string FileManager::getBestWeapon()
{
   return bestWeapon;
}