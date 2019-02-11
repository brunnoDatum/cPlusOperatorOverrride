//
// Created by Brunno Tripovichy on 2019-02-04.
//

#ifndef GAME1011_LAB2_TRIPOVICHYBRUNNO_WEAPON_H
#define GAME1011_LAB2_TRIPOVICHYBRUNNO_WEAPON_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Weapon {

private:
    string name;
    double damage;
    vector<string> abilities;

public:
    Weapon();

    Weapon(const string &name, double damage, const vector<string> &abilities);

    virtual ~Weapon();

    const string &getName() const;

    void setName(const string &name);

    double getDamage() const;

    void setDamage(double damage);

    const vector<string> &getAbilities() const;

    void setAbilities(const vector<string> &abilities);

    friend ostream & operator << (ostream &cout, const Weapon &w);

    void operator == (const Weapon &other) const;

};


#endif //GAME1011_LAB2_TRIPOVICHYBRUNNO_WEAPON_H
