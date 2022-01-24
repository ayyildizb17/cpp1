//Buse AYYILDIZ 150170099

#include "Faction.h"
#include <iostream>
using namespace std;


Faction::Faction() {
    firstEnemy = NULL;
    secondEnemy = NULL;
    numOfUnits = 0;
    attackPoint = 0;
    healthPoint = 0;
    unitRegenerNum = 0;
    totalHealth = 0;

}
Faction::~Faction() {
    delete[] firstEnemy;
    delete[] secondEnemy;
}
void Faction::setTotalH(int u, int h) {
    totalHealth = h*u;
}


void Faction::Print() {
    cout<<"Faction Name:         "<<name<<endl;
    if(isAlive){
        cout<<"Status:               "<<"Alive"<<endl;
    }
    else{
        cout<<"Status:               "<<"Defeated"<<endl;
    }
    cout<<"Number of Units:      "<<numOfUnits<<endl;
    cout<<"Attack Point:         "<<attackPoint<<endl;
    cout<<"Health Point:         "<<healthPoint<<endl;
    cout<<"Unit Regen Number:    "<<unitRegenerNum<<endl;
    cout<<"Total Faction Health: "<<totalHealth<<endl;

}

void Faction::AssignEnemies(Faction *f1, Faction *f2) {
    firstEnemy = f1;
    secondEnemy = f2;
}
bool Faction::IsAlive() {
    if(isAlive){
        return true;
    }
    return false;
}

string Faction::getName() {
    return name;
}
int Faction::getHealth() {
    return healthPoint;
}
void Faction::setHealth(int newHealth) {
    healthPoint = newHealth;
}
int Faction::getAttack() {
    return attackPoint;
}
void Faction::setAttack(int newAttack) {
    attackPoint = newAttack;
}

int Faction::getNumOfUnits() {
    return numOfUnits;
}

void Faction::setNumOfUnits(int unitNum) {
    numOfUnits = unitNum;
}

void Faction::EndTurn() {
    if(numOfUnits<0){
        setNumOfUnits(0);
        isAlive = false;
        totalHealth = numOfUnits*healthPoint;
    }
    else{
        numOfUnits = unitRegenerNum + numOfUnits;
        totalHealth = numOfUnits*healthPoint;
        isAlive = true;
    }




}