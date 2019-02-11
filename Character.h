//
// Created by Brunno Tripovichy on 2019-02-04.
//

#ifndef GAME1011_LAB2_TRIPOVICHYBRUNNO_CHARACTER_H
#define GAME1011_LAB2_TRIPOVICHYBRUNNO_CHARACTER_H

#include <string>
#include <iostream>
#include "Weapon.h"
#include "Armour.h"

using namespace std;

class Character {

private:
    string name;
    string species;
    string backStory;
    double health;
    Weapon weapon;
    Armour armour;

public:
    Character();

    Character(const string &name, const string &species, const string &backStory, double health, const Weapon &weapon, const Armour &armour);

    virtual ~Character();

    const string &getName() const;

    void setName(const string &name);

    const string &getSpecies() const;

    void setSpecies(const string &species);

    const string &getBackStory() const;

    void setBackStory(const string &backStory);

    double getHealth() const;

    void setHealth(double health);

    const Weapon &getWeapon() const;

    void setWeapon(const Weapon &weapon);

    const Armour &getArmour() const;

    void setArmour(const Armour &armour);

    friend ostream & operator << (ostream &cout, const Character &c);

    void operator == (const Character &other) const;

};


#endif //GAME1011_LAB2_TRIPOVICHYBRUNNO_CHARACTER_H
