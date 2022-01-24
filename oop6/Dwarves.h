#include <iostream>
#include "Faction.h"

using namespace std;


class Dwarves:public Faction {

public:
    Dwarves(string name1, int numOfUnits, int attackP, int healthP, int unitRegen): Faction(name1,numOfUnits,attackP,healthP,unitRegen){}
    void Print();
    int PurchaseArmors(Faction*,int) const;
    int PurchaseWeapons(Faction*,int) const;
    void ReceiveAttack(Faction*,int,int);
    void PerformAttack();
};

