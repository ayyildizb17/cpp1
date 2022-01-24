//Buse AYYILDIZ 150170099

#pragma once
#include <iostream>
using namespace std;


class Faction {
protected:
    string name;
    int numOfUnits;
    int attackPoint;
    int healthPoint;
    int unitRegenerNum;
    int totalHealth;
    bool isAlive;
    Faction *firstEnemy;
    Faction *secondEnemy;

public:
    Faction();
    Faction(string name1, int numOfUnits, int attackP, int healthP, int unitRegen){
        name = name1;
        this->numOfUnits = numOfUnits;
        attackPoint = attackP;
        healthPoint = healthP;
        unitRegenerNum = unitRegen;
        totalHealth = numOfUnits*healthPoint;
        isAlive = true;
    };
    ~Faction();
    virtual void  Print();
    void AssignEnemies(Faction*, Faction*);
    bool IsAlive();
    string getName();
    int getHealth();
    void setHealth(int);
    int getAttack();
    void setAttack(int);
    virtual int PurchaseWeapons(Faction *Fact, int i) const=0;
    virtual int PurchaseArmors(Faction *Fact, int i) const=0;
    virtual void PerformAttack() =0;
    virtual void ReceiveAttack(Faction *Fact,int attackP,int unit) =0;
    void setNumOfUnits(int);
    int getNumOfUnits();
    void EndTurn();
    void setTotalH(int,int);
};

