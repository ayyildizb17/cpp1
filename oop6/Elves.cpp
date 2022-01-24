//Buse AYYILDIZ 150170099


#include "Elves.h"
#include <iostream>
using namespace std;

void Elves::Print() {
    cout<<"\"You cannot reach our elegance!\""<<endl;
    Faction::Print();
}

int Elves::PurchaseArmors(Faction *elves, int armP) const {
    int a = elves->getHealth();
    elves->setHealth(a+armP*4);
    elves->setTotalH(elves->getNumOfUnits(),elves->getHealth());
    return armP*5;
}

int Elves::PurchaseWeapons(Faction *elves, int weaP) const {
    int a = elves->getAttack();
    elves->setAttack(a+weaP*2);
    return weaP*15;
}

void Elves::ReceiveAttack(Faction *f, int attackP,int unit) {
    if(f->getName()=="Orcs"){
        int attackingP = (75*attackP)/100*unit;
        int getUnit = f->getNumOfUnits();
        int newUnit = getUnit-((attackingP)/f->getHealth());
        f->setNumOfUnits(newUnit);
        f->setTotalH(f->getNumOfUnits(),f->getHealth());
    }
    else{
        int attackingP = (attackP)*unit;
        int getUnit= f->getNumOfUnits();
        int newUnit = getUnit-((attackingP)/f->getHealth());
        f->setNumOfUnits(newUnit);
        f->setTotalH(f->getNumOfUnits(),f->getHealth());
    }
}

void Elves::PerformAttack() {
    int a = (numOfUnits*60)/100; // for orcs
    int b = numOfUnits-a; //for dwarves (for case of both of them alive)
    int d = (attackPoint*150)/100; //for dwarves
    if(firstEnemy->IsAlive() && secondEnemy->IsAlive()){
        if(firstEnemy->getName()=="Orcs"){
            ReceiveAttack(firstEnemy,attackPoint,a);
            ReceiveAttack(secondEnemy,d,b);
        }
        else{
            ReceiveAttack(firstEnemy,d,b);
            ReceiveAttack(secondEnemy,attackPoint,a);
        }
    }
    if(firstEnemy->IsAlive() && secondEnemy->IsAlive()==0){
        if(firstEnemy->getName()=="Orcs"){
            ReceiveAttack(firstEnemy,attackPoint,numOfUnits);
        }
        else{
            ReceiveAttack(secondEnemy,d,numOfUnits);
        }
    }
    if(firstEnemy->IsAlive()==0 && secondEnemy->IsAlive()){
        if(secondEnemy->getName()=="Orcs"){
            ReceiveAttack(secondEnemy,attackPoint,numOfUnits);
        }
        else{
            ReceiveAttack(secondEnemy,d,numOfUnits);
        }
    }
}