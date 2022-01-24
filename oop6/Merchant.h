//Buse AYYILDIZ 150170099

#include <iostream>
#include "Faction.h"

using namespace std;

class Merchant {
private:
    Faction *firstFact;
    Faction *secondFact;
    Faction *thirdFact;
    int startedWeaponP;
    int startedArmorP;
    int revenue;
    int weaponP;
    int armorP;

public:
    Merchant();
    Merchant(int,int);
    ~Merchant();
    int GetRevenue();
    int GetWeaponPoints();
    int GetArmorPoints();
    void SetWeaponPoints(int);
    void SetArmorPoints(int);
    void AssignFactions(Faction*,Faction*,Faction*);
    bool SellArmors(string,int);
    bool SellWeapons(string,int);
    void EndTurn();


};

