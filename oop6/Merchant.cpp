//Buse AYYILDIZ 150170099

#include "Merchant.h"
#include <iostream>
using namespace std;
#include "Faction.h"

Merchant::Merchant() {
    firstFact = NULL;
    secondFact = NULL;
    thirdFact = NULL;
    revenue = 0;
    weaponP = 0;
    armorP = 0;
    startedWeaponP = 0;
    startedArmorP = 0;

}

Merchant::Merchant(int weaponP, int armP) {
    startedWeaponP = weaponP;
    startedArmorP = armP;
    firstFact = NULL;
    secondFact = NULL;
    thirdFact = NULL;
    this->weaponP = startedWeaponP;
    armorP = startedArmorP;
    revenue = 0;

}
Merchant::~Merchant() {
    delete[] firstFact;
    delete[] secondFact;
    delete[] thirdFact;
}
int Merchant::GetRevenue() {
    return revenue;
}

int Merchant::GetArmorPoints() {
    return armorP;
}

int Merchant::GetWeaponPoints() {
    return weaponP;
}

void Merchant::SetWeaponPoints(int a) {
    a = weaponP;
}

void Merchant::SetArmorPoints(int a) {
    a = armorP;
}
void Merchant::AssignFactions(Faction* orcs, Faction* dwarves, Faction* elves) {
    firstFact = orcs;
    secondFact = dwarves;
    thirdFact = elves;
}

bool Merchant::SellArmors(string fact, int armP) {
    if (firstFact->getName() == fact) {
        if (firstFact->IsAlive()) {
            if (GetArmorPoints() >= armP) {
                cout << "Armors sold!" << endl;
                revenue += firstFact->PurchaseArmors(firstFact,armP);
                armorP = armorP-armP;
                return true;
            }
            cout<< "You try to sell more armors than you have in possession." <<endl;
            return false;
        }
        cout<< "The faction you want to sell armors is dead!" <<endl;
        return false;
    }

    if(secondFact->getName()==fact){
        if(secondFact->IsAlive()){
            if(GetArmorPoints() >= armP){
                cout<<"Armors sold!"<<endl;
                revenue += secondFact->PurchaseArmors(secondFact,armP);
                armorP = armorP-armP;
                return true;
            }
            cout<< "You try to sell more armors than you have in possession." <<endl;
            return false;
        }
        cout<< "The faction you want to sell armors is dead!" <<endl;
        return false;

    }
    if(thirdFact->getName()==fact){
        if(thirdFact->IsAlive()){
            if(GetArmorPoints() >= armP){
                cout<<"Armors sold!"<<endl;
                revenue += thirdFact->PurchaseArmors(thirdFact,armP);
                armorP = armorP-armP;
                return true;
            }
            cout<< "You try to sell more armors than you have in possession." <<endl;
            return false;
        }
        cout<< "The faction you want to sell armors is dead!" <<endl;
        return false;

    }
    return false;
}

bool Merchant::SellWeapons(string fact, int weaP) {
    if(firstFact->getName() == fact){
        if(firstFact->IsAlive()){
            if(GetWeaponPoints() >= weaP){
                cout<<"Weapons sold!"<<endl;
                revenue += firstFact->PurchaseWeapons(firstFact,weaP);
                weaponP = weaponP-weaP;
                return true;
            }
            cout<< "You try to sell more weapons than you have in possession." <<endl;
            return false;
        }
        cout<< "The faction you want to sell weapons is dead!" <<endl;
        return false;
    }
    if(secondFact->getName() == fact){
        if(secondFact->IsAlive()){
            if(GetWeaponPoints() >= weaP){
                cout<< "Weapons sold!" <<endl;
                revenue += secondFact->PurchaseWeapons(secondFact,weaP);
                weaponP = weaponP-weaP;
                return true;
            }
            cout<< "You try to sell more weapons than you have in possession." <<endl;
            return false;
        }
        cout<< "The faction you want to sell weapons is dead!" <<endl;
        return false;
    }
    if(thirdFact->getName() == fact){
        if(thirdFact->IsAlive()){
            if(GetWeaponPoints() >= weaP){
                cout<< "Weapons sold!" <<endl;
                revenue += thirdFact->PurchaseWeapons(thirdFact,weaP);
                weaponP = weaponP-weaP;
                return true;
            }
            cout<< "You try to sell more weapons than you have in possession." <<endl;
            return false;
        }
        cout<< "The faction you want to sell weapons is dead!" <<endl;
        return false;
    }
    return false;
}

void Merchant::EndTurn() {
    weaponP = startedWeaponP;
    armorP = startedArmorP;
}