//Buse AYYILDIZ 150170099

#include "Mission.h"
#include "Agency.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int Mission::getCost() {
    return cost;
}



string Mission::getName() {
    return name;
}

Passenger* Mission::getPassengers() {
    return passengers;
}

Mission::Mission(string name, int cost,int fault) {

    this->name = nameErrorDetect(name);
    if(name != nameErrorDetect(name)){
        cout<<"Given name does not satisfy the mission naming convention. Please set a new name!"<<endl;
    }
    faultProbability = fault;
    this->cost = cost;
    c_size = 0;
    p_size = 0;
    Passenger* passengers = NULL;
    Astronaut* crew = NULL;
    numMissions++;
    missionNumber = numMissions;
    missionNumber++;
}

string Mission::nameErrorDetect(string name) {
    int pos = name.find('-');
    string str1 = name.substr(0,1);
    string str3 = name.substr(1,1);
    string str2 = name.substr(3,2);
    if(pos!=2){
        name = "AA-00";
        return name;

    }

    else if(!(str1<="Z" && str1>="A")){
        name = "AA-00";
        return name;
    }

    else if(!(str2<="99" && str2>="00")){
        name ="AA-00";
        return name;
    }
    else if(!(str3<="Z" && str3>="A")){
        name = "AA-00";
        return name;
    }
    else{
        return name;
    }
}

void Mission::setName(string n) {
    nameErrorDetect(n);
    name = n;
}
void Mission::operator+=( Astronaut* a) {
    if(c_size==0){
        c_size++;
        crew = new Astronaut[c_size+1];
        crew[0] = *a;
    }
    else{
        c_size++;
        Astronaut* temp;
        temp = new Astronaut[c_size];
        for(int i=0; i<c_size-1; i++){
            temp[i] = crew[i];
        }
        temp[c_size-1] = *a;
        delete[]crew;
        crew = temp;

    }
}
void Mission::operator+=(Passenger* p){
    if(p->getTicket()){
        if(p_size == 0){
            p_size++;
            passengers = new Passenger[p_size + 1];
            passengers[0] = *p;

        }
        else{
            p_size++;
            Passenger* temp = new Passenger[p_size+1];
            for(int i=0; i<p_size; i++){
                temp[i] = passengers[i];
            }
            temp[p_size] = *p;
            delete[]passengers;
            passengers = temp;
        }

    }
    else{
        cout<<"Passenger "<<p->getName()<<" "<<p->getSurname()<<" does not have a valid ticket!"<<endl;
    }


}

bool Mission::executeMission(Mission  miss) {

    int random_prob = rand() %100 + 1;
    if(random_prob>=faultProbability){
        cout<<"MISSION "<<miss.name<< " SUCCESSFUL!"<<endl;
        for(int i=0; i<c_size; i++){
            miss.crew[i].setNumMissions();

            cout<<"Astronaut "<<miss.crew[i].getName()<<" "<<miss.crew[i].getSurname()<<" successfully completed "<< miss.crew[i].getNumMissions() <<" missions."<<endl;
        }
        completed = true;
    }
    else{
        cout<<"MISSION "<<miss.name<<" FAILED!"<<endl;
        cout<<"Agency reschedules the mission."<<endl;
        completed = false;
    }
    return completed;
}

int Mission::calculateProfit(int tic) {
    int a = (tic*p_size)-cost;

    return a;
}