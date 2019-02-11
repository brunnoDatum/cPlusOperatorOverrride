//
// Created by Brunno Tripovichy on 2019-02-04.
//

#ifndef GAME1011_LAB2_TRIPOVICHYBRUNNO_ARMOUR_H
#define GAME1011_LAB2_TRIPOVICHYBRUNNO_ARMOUR_H

#include <string>
#include <vector>
#include <iostream>

using  namespace std;

class Armour {

private:
    string name;
    string description;
    double armourValue;

public:
    Armour();

    Armour(const string &name, const string &description, double armourValue);

    virtual ~Armour();

    const string &getName() const;

    void setName(const string &name);

    const string &getDescription() const;

    void setDescription(const string &description);

    double getArmourValue() const;

    void setArmourValue(double armourValue);

    friend ostream & operator << (ostream &cout, const Armour &a);

    void operator == (const Armour &other) const;

};


#endif //GAME1011_LAB2_TRIPOVICHYBRUNNO_ARMOUR_H
