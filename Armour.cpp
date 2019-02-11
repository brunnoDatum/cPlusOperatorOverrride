//
// Created by Brunno Tripovichy on 2019-02-04.
//

#include "Armour.h"

Armour::Armour() = default;

Armour::Armour(const string &name, const string &description, double armourValue) : name(name), description(description), armourValue(armourValue) {}

Armour::~Armour() = default;

const string &Armour::getName() const {
    return name;
}

void Armour::setName(const string &name) {
    Armour::name = name;
}

const string &Armour::getDescription() const {
    return description;
}

void Armour::setDescription(const string &description) {
    Armour::description = description;
}

double Armour::getArmourValue() const {
    return armourValue;
}

void Armour::setArmourValue(double armourValue) {
    Armour::armourValue = armourValue;
}

ostream &operator<<(ostream &cout, const Armour &a) {
    cout << "Armour details: " << endl;
    cout << "Name: " << a.getName() << endl;
    cout << "Armour Value: " << a.getArmourValue() << endl;
    cout << "Description: " << a.getDescription() << endl;

    return cout;
}

void Armour::operator==(const Armour &other) const {
    cout << "Armour One: " << endl;
    cout << this << endl;
    cout << "Armour Two: " << endl;
    cout << other << endl;
}