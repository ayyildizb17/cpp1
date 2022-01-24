//Buse AYYILDIZ 150170099

#include <iostream>
#include "Faction.h"



using namespace std;

class Orcs:public Faction {

public:
    Orcs(string name1, int numOfUnits, int attackP, int healthP, int unitRegen): Faction(name1,numOfUnits,attackP,healthP,unitRegen){}
    void Print();
    int PurchaseArmors(Faction*,int) const;
    int PurchaseWeapons(Faction*,int) const;
    void PerformAttack() ;
    void ReceiveAttack(Faction*,int,int);

};


