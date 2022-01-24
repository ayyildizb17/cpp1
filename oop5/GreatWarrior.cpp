#include "GreatWarrior.h"

#include <iostream>
using namespace std;

//charlist func

CharacterList::CharacterList() {
    characters = NULL;
    size = 0;
}

CharacterList::~CharacterList() {
    delete[] characters;
}

Character* CharacterList::getCharacters() {
    return characters;
}

int CharacterList::getSize() {
    return size;
}

void CharacterList::addCharacter(Character* c) {

    if(size == 0){
        size++;
        characters = new Character[size];
        characters[0] = *c;
    }
    else{
        Character* temp = new Character[size+1];
        for(int i = 0; i<size; i++){
            temp[i] = characters[i];
        }
        temp[size] = *c;
        size++;
        //delete[] characters;
        characters = temp;
    }
}

void CharacterList::delCharacter(int index) {
    Character* temp = new Character[size-1];

    for(int i=0; i<index; i++){
        temp[i] = characters[i];
    }

    for (int i=index+1; i<size; i++){
        temp[i-1] = characters[i];
    }

    //delete[] characters;
    size--;
    characters = temp;

}

Character CharacterList::getPlayer() {
    return characters[size-1];
}

Character CharacterList::getLandOwner(string l) {
    for(int i=0; i<size-1;i++){
        if(characters[i].lands->getName() == l){
            return characters[i];
        }
    }
}

// character func

Character::Character() {
    lands = NULL;
    numOfLands = 0;
    manpower = 3;
    gold = 20;

}

Character::~Character() {
    Land* temp = lands;
    Land* temp2;

    while(temp != NULL){
        temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }
}

string Character::getName() {
    return name;
}

Land* Character::getLands() {
    return lands;
}

int Character::getManPower() {
    return manpower;
}

int Character::getGold() {
    return gold;
}

void Character::setName(string s) {
    name = s;
}

void Character::setManpower(int m) {
    manpower = m;
}

void Character::setGold(int g) {
    gold = g;
}

void Character::setNumOfLands(int n) {
    numOfLands = n;
}

void Character::addLand(Land* l) {
    if(lands == NULL){
        lands = l;
    }
    else{
        Land* temp = lands;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }

        temp->setNext(l);

    }
    numOfLands++;
}


void Character::removeLand(Land* l){
    if(lands->getName() == l->getName()){
        if(numOfLands>1){
            lands = lands->getNext();
        }
        else{
            lands = NULL;
        }
    }
    else{
        Land* temp = lands;
        while(temp->getNext()->getName() != l->getName()){
            temp = temp->getNext();
        }
        if(temp->getNext()->getNext() == NULL){
            temp->setNext(NULL);
        }
        else{
            temp->setNext(temp->getNext()->getNext());
        }
    }
    numOfLands--;
}

int Character::getNumOfLands() {
    return numOfLands;
}

void Character::getTaxes() {
    Land* temp = lands;
    while(temp){
        if(temp->getHolding()[0] == 'v'){
            gold += 5;
        }
        else if(temp->getHolding()[1] == 'a'){
            gold += 7;
        }
        else{
            gold += 10;
        }
        temp = temp->getNext();
    }
}
//copy constructor
Character::Character(Character& c) {
    name = c.name;
    manpower = c.manpower;
    gold = c.gold;
    numOfLands = c.numOfLands;
    lands = c.lands;
    general = c.general;
}
Character::Character(string gen) {
    general = gen;
}
string Character::getGeneral() const {
    return general;
}
//land func

Land::Land() {
    next = NULL;
}

string Land::getName() {
    return name;
}
Land::Land(Land& l) {
    name = l.name;
    holding = l.holding;
    next = l.next;
}
string Land::getHolding() {
    return holding;
}

Land* Land::getNext() {
    return next;
}

void Land::setName(string n){
    name = n;
}
void Land::setHolding(string h){
    holding = h;
}

void Land::setNext(Land * l) {
    next = l;
}
