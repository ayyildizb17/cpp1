//Buse AYYILDIZ 150170099
#include "Orcs.h"
#include <iostream>
using namespace std;

void Orcs::Print() {
    cout<<"\"Stop running, you'll only die tired!\""<<endl;
    Faction::Print();
}
int Orcs::PurchaseArmors(Faction *orcs,int armP) const {
    int a = orcs->getHealth();
    orcs->setHealth(a+armP*3);
    orcs->setTotalH(orcs->getNumOfUnits(),orcs->getHealth());
    return armP;

}
int Orcs::PurchaseWeapons(Faction *orcs, int weaP) const {
    int a = orcs->getAttack();
    orcs->setAttack(a+weaP*2);
    return 20*weaP;

}

void Orcs::PerformAttack()  {
    int a =(numOfUnits*70)/100; //for elves
    int b = numOfUnits-a; //for dwarves
    if(firstEnemy->IsAlive() && secondEnemy->IsAlive()){

        ReceiveAttack(firstEnemy,attackPoint,a);
        ReceiveAttack(secondEnemy,attackPoint,b);


    }
    if(firstEnemy->IsAlive() && secondEnemy->IsAlive()==0){
        ReceiveAttack(firstEnemy,attackPoint,numOfUnits);
    }
    if(firstEnemy->IsAlive()==0 && secondEnemy->IsAlive()){
        ReceiveAttack(secondEnemy,attackPoint,numOfUnits);
    }
}

void Orcs::ReceiveAttack(Faction *f,int attackP,int unit)  {

    if(f->getName() == "Elves"){
        int b =(attackP*125)/100; //attack point increased %125 for elves
        int getUnit = f->getNumOfUnits();
        int newUnit = (b*unit)/f->getHealth();
        f->setNumOfUnits(getUnit-newUnit);
        f->setTotalH(f->getNumOfUnits(),f->getHealth());
    }
    if(f->getName() == "Dwarves"){
        int b = attackP;
        int getUnit = f->getNumOfUnits();
        int newUnit = (b*unit)/f->getHealth();
        f->setNumOfUnits(getUnit-newUnit);
        f->setTotalH(f->getNumOfUnits(),f->getHealth());

    }

}