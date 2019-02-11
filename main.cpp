#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Character.h"
#include "Weapon.h"
#include "Armour.h"

using namespace std;

void createNewCharacter(const vector<Weapon> &availableWeapons, const vector<Armour> &availableArmour, vector<Character> &characters);

void firstMenuOptions(int &menuCreationChoice);

void characterDetailMenu(vector<Character> &characters);

void characterCompareMenu(vector<Character> &characters);

int main() {

    vector<Character> characters;
    characters.reserve(3);

    vector<Weapon> availableWeapons { Weapon("Short sword of chaos", 12, {"Resistance to Poison", "Piercing and Slashing", "Lightweight"}),
                                      Weapon("Celestial Long Sword", 20, {"Resistance to Magic", "Slashing", "Divine Power"}),
                                      Weapon("Elvencourt Bow", 12, {"Multiple shot", "Piercing", "Lightweight"}) };

    vector<Armour> availableArmour { Armour("Armour of chaos", "This armour descent from the Abyss. Gives protection against Lawful characters.", 12),
                                     Armour("Celestial Armour", "This armour descent from the Heavens. Gives protection against Chaotic characters.", 15),
                                     Armour("Elvencourt Armour", "This armour descent from the Elven Kingdoms. Gives stealth bonus.", 10) };


    cout << "Hello, Welcome to character creation!" << endl;
    cout << "You can create up to 3 characters!" << endl;

    createNewCharacter(availableWeapons, availableArmour, characters);

    bool menuCreation = true;
    int menuCreationChoice = 0;

    while (menuCreation && !characters.empty()) {
        firstMenuOptions(menuCreationChoice);

        if (menuCreationChoice == 1) {
            if (characters.size() != 3) {
                cin.ignore();
                createNewCharacter(availableWeapons, availableArmour, characters);
            } else {
                cout << "You already have 3 characters!" << endl;
            }

        } else if (menuCreationChoice == 2) {
            if (characters.size() > 1) {
                characterCompareMenu(characters);
            } else {
                cout << "You need at least 2 characters!" << endl;
            }
        } else if (menuCreationChoice == 3) {
            characterDetailMenu(characters);

        } else if (menuCreationChoice == 4) {
            menuCreation = false;
        }
    }

    cout << "Exiting Application." << endl;
    return 0;
}

void characterDetailMenu(vector<Character> &characters) {
    int detailChoice = 0;

    for (auto &c : characters) { // access by reference to avoid copying
                cout << (&c - &characters[0] + 1) << " -> " << c.getName() << endl;
            }

    cout << "Choose a character from above: ";
    cin >> detailChoice;

    while (cin.fail() || (detailChoice < 1 || detailChoice > characters.size())) {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                cout << "You have entered wrong input! Enter again: ";
                cin >> detailChoice;
            }

    cout << endl;

    cout << characters.at((detailChoice - 1));
}

void characterCompareMenu(vector<Character> &characters) {
    int firstChoice = 0, secondChoice = 0;

    for (auto &c : characters) { // access by reference to avoid copying
        cout << (&c - &characters[0] + 1) << " -> " << c.getName() << endl;
    }

    cout << "Choose first character from above: ";
    cin >> firstChoice;

    while (cin.fail() || (firstChoice < 1 || firstChoice > characters.size())) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "You have entered wrong input! Enter again: ";
        cin >> firstChoice;
    }

    cout << "Choose second character from above: ";
    cin >> secondChoice;

    while (cin.fail() || (secondChoice < 1 || secondChoice > characters.size())) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "You have entered wrong input! Enter again: ";
        cin >> secondChoice;
    }

    cout << endl;

    characters.at((firstChoice - 1)) == characters.at((secondChoice - 1));
}

void firstMenuOptions(int &menuCreationChoice) {
    cout << "Character management: " << endl;
    cout << "1 - Create another character (up to 3)" << endl;
    cout << "2 - Compare your characters" << endl;
    cout << "3 - Show a character" << endl;
    cout << "4 - Exit" << endl;
    cout << "Choose your option: ";
    cin >> menuCreationChoice;

    while (cin.fail() || (menuCreationChoice < 1 || menuCreationChoice > 4)) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "You have entered wrong input! Enter again: ";
        cin >> menuCreationChoice;
    }

    cout << endl;
}

void createNewCharacter(const vector<Weapon> &availableWeapons, const vector<Armour> &availableArmour, vector<Character> &characters) {
    string newName, newSpecies, newBackstory;
    double newHealth;

    cout << "Enter the name of the character: ";
    getline(cin, newName);

    while (newName.length() < 3) {
        cout << endl;
        cout << "You must enter at least 3 characters! Enter again: ";
        getline(cin, newName);
    }

    cout << "Enter the name of the species: ";
    getline(cin, newSpecies);

    while (newSpecies.length() < 3) {
        cout << endl;
        cout << "You must enter at least 3 characters! Enter again: ";
        getline(cin, newSpecies);
    }

    cout << "Enter the name of the backStory: ";
    getline(cin, newBackstory);

    while (newBackstory.length() < 3) {
        cout << endl;
        cout << "You must enter at least 3 characters! Enter again: ";
        getline(cin, newBackstory);
    }

    cout << "Enter the health: ";
    cin >> newHealth;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<double>::max(), '\n');
        cout << "You have entered wrong input! Try again: ";
        cin >> newHealth;
    }

    for (auto &w : availableWeapons) { // access by reference to avoid copying
        cout << (&w - &availableWeapons[0] + 1) << " -> " << endl;
        cout << w << endl;
    }

    int weaponChoice = 0;
    cout << "Choose a weapon from above: ";
    cin >> weaponChoice;

    while (cin.fail() || (weaponChoice < 1 || weaponChoice > availableWeapons.size())) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "You have entered wrong input! Try again: ";
        cin >> weaponChoice;
    }

    Weapon selectedWeapon = availableWeapons[weaponChoice - 1];

    for (auto &a : availableArmour) { // access by reference to avoid copying
        cout << (&a - &availableArmour[0] + 1) << " -> " << endl;
        cout << a << endl;
    }

    int armourChoice = 0;
    cout << "Choose an armour from above: ";
    cin >> armourChoice;

    while (cin.fail() || (armourChoice < 1 || armourChoice > availableArmour.size())) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "You have entered wrong input! Try again: ";
        cin >> armourChoice;
    }

    Armour selectedArmour = availableArmour[weaponChoice - 1];

    Character newCharacter(newName, newSpecies, newBackstory, newHealth, selectedWeapon, selectedArmour);

    cout << "Your newly character - >" << endl;
    cout << newCharacter << endl;

    characters.push_back(newCharacter);
}