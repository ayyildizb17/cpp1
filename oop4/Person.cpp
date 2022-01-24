//Buse AYYILDIZ 150170099

#include "Person.h"
#include "Agency.h"

#include <iostream>
using namespace std;
//Person func

string Person::getName() {
    return name;
}
string Person::getSurname(){
    return surname;
}

void Person::setName(string n) {
    name = n;
}
void Person::setSurname( string s) {
    surname = s;
}

//Astronaut func

Astronaut::Astronaut() {

    numMissions = 0;
    sizeA = 0;
}

Astronaut::Astronaut(string n, string s, int numMissions ) {
    setName(n);
    setSurname(s);
    sizeA++;
    if(numMissions<0){
        cout<<"Number of missions that astronaut completed can't be negative. It is set to 0."<<endl;
        this->numMissions = 0;
    }
    else{
        this->numMissions = numMissions;
    }

}
int Astronaut::getSizea() {
    return sizeA;
}
int Astronaut::getNumMissions() {
    return numMissions;
}
void Astronaut::setNumMissions() {
    int a = getNumMissions();
    a++;
    numMissions = a;
}

//Passenger func

Passenger::Passenger(string n, string s, int c) {
    setName(n);
    setSurname(s);
    cash = c;
    sizeP++;


}

bool Passenger::buyTicket(int a) {

    for(int i=0; i<sizeP; i++){
        if(cash>=a){
            ticket = true;
        }
        else{
            ticket = false;
        }
    }
    return ticket;
}

int Passenger::getCash() {
    return cash;
}

bool Passenger::getTicket(){
    return ticket;
}