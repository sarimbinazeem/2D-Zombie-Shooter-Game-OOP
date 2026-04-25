#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
using namespace std;

class FileManager
{
    private:
        int highWave;
        int highScore;

        string recordDay;
        string recordTime;

        string bestWeapon;

    public:
        FileManager();

        void loadData();
        void saveData( int currentWave, int currentScore, string currentWeapon,  string day,string time);

        int getHighWave();
        int getHighScore();
        string getRecordDay();
        string getRecordTime();
        string getBestWeapon();

};

#endif