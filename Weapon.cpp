//
// Created by Brunno Tripovichy on 2019-02-04.
//

#include "Weapon.h"

Weapon::Weapon() = default;

Weapon::Weapon(const string &name, double damage, const vector<string> &abilities) : name(name), damage(damage), abilities(abilities) {}

Weapon::~Weapon() = default;

const string &Weapon::getName() const {
    return name;
}

void Weapon::setName(const string &name) {
    Weapon::name = name;
}

double Weapon::getDamage() const {
    return damage;
}

void Weapon::setDamage(double damage) {
    Weapon::damage = damage;
}

const vector<string> &Weapon::getAbilities() const {
    return abilities;
}

void Weapon::setAbilities(const vector<string> &abilities) {
    Weapon::abilities = abilities;
}

ostream &operator<<(ostream &cout, const Weapon &w) {
    cout << "Weapon details: " << endl;
    cout << "Name: " << w.getName() << endl;
    cout << "Damage: " << w.getDamage() << endl;

    for (auto &abi : w.getAbilities()) { // access by reference to avoid copying
        cout << " Ability -> " << abi << endl;
    }

    return cout;
}

void Weapon::operator==(const Weapon &other) const {
    cout << "Weapon One: " << endl;
    cout << this << endl;
    cout << "Weapon Two: " << endl;
    cout << other << endl;
}
