/* Buse AYYILDIZ 150170099
*/


#include "Person.h"
#include "Mission.h"
#pragma once

#include <iostream>
using namespace std;

class Agency{
private:
    string name;
    int cash;
    int ticketPrice;
    Mission* completedMissions;
    Mission* nextMissions;
    int sizeNext;
    int sizeCompleted;
public:
    Agency(){
        cash = 0;
        ticketPrice = 0;
        sizeNext = 0;
        sizeCompleted = 0;
        completedMissions = NULL;
        nextMissions = NULL;

    };
    Agency(string,int,int tPrice=0);
    ~Agency();
    void setTicketPrice(int);
    void addMission(Mission);
    void addCompMission(Mission);
    int getTicketPrice();
    friend ostream& operator<< (ostream &out, const Agency &agency);
    void executeNextMission();
    int getSizeNext();
    int getSizeComp();
};