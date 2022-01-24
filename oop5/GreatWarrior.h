/*#ifndef GREATWARRIOR_H
#define MAIN_CPP_GREATWARRIOR_H
#endif //MAIN_CPP_GREATWARRIOR_H
*/
#include <iostream>
using namespace std;


class Land{
private:
    string name;
    string holding;
    Land* next;
public:
    Land();
    Land(Land& );
    Land* getNext();
    string getName();
    string getHolding();
    void setName(string);
    void setHolding(string);
    void setNext(Land*);

};

class Character{
private:
    string name;
    int manpower;
    int gold;
    int numOfLands;
    Land* lands;
    string general;
public:
    Character();
    Character(Character& );
    ~Character();
    Character(string);
    friend class CharacterList;
    string getGeneral() const;
    string getName();
    int getManPower();
    Land* getLands();
    int getNumOfLands();
    int getGold();
    void setName(string);
    void setManpower(int);
    void setGold(int);
    void setNumOfLands(int);
    void setLands(Land*);
    void addLand(Land*);
    void removeLand(Land*);
    void getTaxes();
};

class CharacterList{
private:
    Character* characters;
    int size;

public:

    CharacterList();
    ~CharacterList();
    Character* getCharacters();
    int getSize();
    void addCharacter(Character*);
    void delCharacter(int);
    Character getPlayer();
    Character getLandOwner(string );
};
