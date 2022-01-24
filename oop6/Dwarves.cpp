//Buse AYYILDIZ 150170099
#include "Dwarves.h"

#include <iostream>
using namespace std;


void Dwarves::Print() {
    cout<<"\"Taste the power of our axes!\""<<endl;
    Faction::Print();
}


int Dwarves::PurchaseArmors(Faction *dwarves, int armP) const {
    int a = dwarves->getHealth();
    dwarves->setHealth(a+armP*2);
    dwarves->setTotalH(dwarves->getHealth(),dwarves->getNumOfUnits());
    return armP*3;
}

int Dwarves::PurchaseWeapons(Faction *dwarves, int weaP) const {
    int a = dwarves->getAttack();
    dwarves->setAttack(a+weaP);
    return weaP*10;
}

void Dwarves::PerformAttack() {
    int a = (numOfUnits*50)/100;
    if(firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        ReceiveAttack(firstEnemy,attackPoint,a);
        ReceiveAttack(secondEnemy,attackPoint,numOfUnits-a);
    }
    if(firstEnemy->IsAlive() && secondEnemy->IsAlive()==0){
        ReceiveAttack(firstEnemy,attackPoint,numOfUnits);
    }
    if(firstEnemy->IsAlive()==0 && secondEnemy->IsAlive()){
        ReceiveAttack(secondEnemy,attackPoint,numOfUnits);
    }
}

void Dwarves::ReceiveAttack(Faction *f, int attackP,int unit) {
    if(f->getName()=="Orcs"){
        int attackingP = ((80*attackP)/100)*unit;
        int getUnit = f->getNumOfUnits();
        int newUnit = getUnit-((attackingP)/f->getHealth());
        f->setNumOfUnits(newUnit);
        f->setTotalH(f->getNumOfUnits(),f->getHealth());
    }
    else{
        int attackingP = ((75*attackP)/100)*unit;
        int getUnit= f->getNumOfUnits();
        int newUnit = getUnit-((attackingP)/f->getHealth());
        f->setNumOfUnits(newUnit);
        f->setTotalH(f->getNumOfUnits(),f->getHealth());
    }
}