/* Buse AYYILDIZ 150170099
*/

#include <iostream>
#include "Person.h"
#pragma once
using namespace std;


class Mission{
private:
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed;
    Passenger* passengers;
    Astronaut* crew;
    static int numMissions;
    int c_size; //crew array size
    int p_size; //passenger array size
public:
    Mission(){
        missionNumber = 0;
        cost = 0;
        faultProbability = 0;
        passengers = NULL;
        crew = NULL;
        c_size = 0;
        p_size = 0;
    }

    int getNumMissions(){
        return missionNumber-1;
    }
    Mission(string,int, int);
    string getName();
    Passenger* getPassengers();
    string nameErrorDetect(string);
    void setName(string);
    void operator+=(Astronaut*);
    void operator+=(Passenger*);
    bool executeMission(Mission);
    int calculateProfit(int);
    int getCost();

};
