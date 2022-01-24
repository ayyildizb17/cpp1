/* Buse AYYILDIZ 150170099
*/
#include <iostream>
using namespace std;
#pragma once

class Person{
private:
    string name;
    string surname;
public:
    string getName();
    string getSurname();
    void setName(string);
    void setSurname(string);
};

class Passenger : public Person{
private:
    int cash;
    bool ticket;
    int sizeP=0;
public:
    Passenger(){
        cash = 0;
        sizeP = 0;
    }
    Passenger(string,string,int c=0);
    bool buyTicket(int);
    int getCash();
    bool getTicket();


};

class Astronaut : public Person {
private:
    int numMissions;
    int sizeA;
public:
    Astronaut();
    int getSizea();
    Astronaut(string, string, int numM = 0);
    int getNumMissions();
    void setNumMissions();

};