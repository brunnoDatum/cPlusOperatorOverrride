//
// Created by Brunno Tripovichy on 2019-02-04.
//

#include "Character.h"

Character::Character() = default;

Character::Character(const string &name, const string &species, const string &backStory, double health, const Weapon &weapon, const Armour &armour) : name(name), species(species),
                                                                                                                                                      backStory(backStory),
                                                                                                                                                      health(health),
                                                                                                                                                      weapon(weapon),
                                                                                                                                                      armour(armour) {}

Character::~Character() = default;

const string &Character::getName() const {
    return name;
}

void Character::setName(const string &name) {
    Character::name = name;
}

const string &Character::getSpecies() const {
    return species;
}

void Character::setSpecies(const string &species) {
    Character::species = species;
}

const string &Character::getBackStory() const {
    return backStory;
}

void Character::setBackStory(const string &backStory) {
    Character::backStory = backStory;
}

double Character::getHealth() const {
    return health;
}

void Character::setHealth(double health) {
    Character::health = health;
}

const Weapon &Character::getWeapon() const {
    return weapon;
}

void Character::setWeapon(const Weapon &weapon) {
    Character::weapon = weapon;
}

const Armour &Character::getArmour() const {
    return armour;
}

void Character::setArmour(const Armour &armour) {
    Character::armour = armour;
}

ostream &operator<<(ostream &cout, const Character &c) {
    cout << "Character details: " << endl;
    cout << "Name: " << c.getName() << endl;
    cout << "Species: " << c.getSpecies() << endl;
    cout << "Health: " << c.getHealth() << endl;
    cout << "Epic Backstory: " << c.getBackStory() << endl;
    cout << c.getWeapon() << endl;
    cout << c.getArmour() << endl;

    return cout;
}

void Character::operator==(const Character &other) const {
    cout << "Character One: " << endl;
    cout << *this << endl;
    cout << "Character Two: " << endl;
    cout << other << endl;
}