//Buse AYYILDIZ 150170099

#include "Agency.h"

#include <iostream>
using namespace std;
int Agency::getSizeNext() {

    return  sizeNext;
}
int Agency::getSizeComp() {
    return sizeCompleted;
}


int Agency::getTicketPrice() {
    return ticketPrice;
}

void Agency::setTicketPrice(int a) {
    if(a>=0){
        ticketPrice = a;


    }
    else{
        ticketPrice = 0;


    }

}

Agency::Agency(string agency_name, int agency_cash, int ticket_price ) {
    name = agency_name;
    cash = agency_cash;
    sizeNext=0;
    sizeCompleted=0;
    completedMissions = NULL;
    nextMissions = NULL;
    if(ticket_price>=0){
        ticketPrice = ticket_price;

    }
    else{
        cout<<"Ticket price can't be negative. It is set to 0"<<endl;
        ticketPrice = 0;
    }

}

Agency::~Agency(){
    delete[] nextMissions;
    delete[] completedMissions;
}

void Agency::addMission(Mission m) {

    if(sizeNext==0){
        sizeNext++;
        nextMissions = new Mission[sizeNext];
        nextMissions[0] = m;

    }
    else {

        sizeNext++;
        Mission *temp = new Mission[sizeNext];
        for (int i = 0; i < sizeNext-1; i++) {
            temp[i] = nextMissions[i];
        }

        temp[sizeNext-1] = m;
        delete[]nextMissions;
        nextMissions = temp;

    }
}
void Agency::addCompMission(Mission m) {
    if(getSizeComp()==0){
        sizeCompleted++;
        completedMissions = new Mission[sizeCompleted];
        completedMissions[0] = m;

    }
    else {

        Mission *temp = new Mission[sizeCompleted + 1];
        for (int i = 0; i < getSizeComp(); i++) {
            temp[i] = completedMissions[i];
        }
        temp[getSizeComp()] = m;
        sizeCompleted++;
        completedMissions = temp;
    }
}



ostream& operator<< (ostream &out, const Agency &agency){

    out <<"Agency name: "<<agency.name<<", "<<"Total cash: "<<agency.cash<<", "<<"Ticket price: "<<agency.ticketPrice<<endl;
    out<<"Next Missions:"<<endl;
    if(agency.sizeNext==0){
        out<<"No missions available."<<endl;
    }
    else {
        for(int i=0; i<agency.sizeNext; i++){
            out << "Mission number: " << agency.nextMissions[i].getNumMissions() << " Mission name: "
                << agency.nextMissions[i].getName()<< "Cost: " << agency.nextMissions[i].getCost() << endl;
        }

    }

    out<<"Completed Missions:"<<endl;
    if(agency.sizeCompleted== 0){
        out<<"No missions completed before."<<endl;
    }
    else{
        for(int i=0; i<agency.sizeCompleted;i++){
            out << "Mission number: " << agency.completedMissions[i].getNumMissions() << " Mission name: "
                << agency.completedMissions[i].getName() << "Cost: " << agency.completedMissions[i].getCost() << endl;
        }

    }

    return out;
}


void Agency::executeNextMission() {
    Mission temp;

    if(getSizeNext() == 0){
        cout<<"No available mission to execute!"<<endl;
    }
    else {
        temp = nextMissions[0];
        bool a = temp.executeMission(temp);
        if (a == true) {
            addCompMission(temp);
            for(int i=1; i<sizeNext; i++) {
                nextMissions[i-1] = nextMissions[i];
            }
            sizeNext--;
            int b = temp.calculateProfit(ticketPrice);
            cash = cash + b;
        }
        else {

            for(int i=1; i<sizeNext; i++){
                nextMissions[i-1] = nextMissions[i];
            }
            nextMissions[sizeNext-1] = temp;
            int c = temp.calculateProfit(ticketPrice);
            cash = cash + c - ticketPrice;
        }
    }
}

