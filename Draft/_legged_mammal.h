/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Legged Mammal Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 08:05 | Draft 1
 * ************************************************************************************/

#ifndef _LEGGED_MAMMAL_H
#define _LEGGED_MAMMAL_H

#include <iostream>
#include <string>
#include <vector>
#include "_helpers.h"


class LeggedMammal 
{
private:
    // static properties
   static std::vector<std::string> furKinds;

    // regular properties
    std::string species;
    short legNumber;
    std::string furKind;
    bool hasTail;

    // methods
    bool isFurKind(std::string);

public:
    // constructor/destructor
    LeggedMammal(void);
    LeggedMammal(std::string, short, std::string, bool);
    ~LeggedMammal(void);

    // setters/getters
    void setSpecies(std::string);
    void setLegNumber(short);
    void setFurKind(std::string);
    void setHasTail(bool);
    std::string getSpecies(void);
    short getLegNumber(void);
    std::string getFurKind(void);
    std::string getHasTail(void);  
};

bool LeggedMammal::isFurKind(std::string furKind) {
    std::string F = _to_lower(furKind);     // _to_lower() function is in _helpers.h
    for (std::string f : furKinds) {
        if (_to_lower(f) == F) return true;  
    }
    return false;
}

std::vector<std::string>LeggedMammal::furKinds{"None","Light","Medium","Thick"}; 

LeggedMammal::LeggedMammal() {
    this->setSpecies("");
    this->setLegNumber(0);
    this->setFurKind("none");
    this->setHasTail(false);
}

LeggedMammal::LeggedMammal(std::string species, short legNumber, std::string furKind, bool hasTail) {
    this->setSpecies(species);
    this->setLegNumber(legNumber);
    this->setFurKind(furKind);
    this->setHasTail(hasTail);
}

LeggedMammal::~LeggedMammal() { }

void LeggedMammal::setSpecies(std::string species) { this->species = species; }
void LeggedMammal::setLegNumber(short legNumber) { this->legNumber = legNumber; }
void LeggedMammal::setHasTail(bool hasTail) { this->hasTail = hasTail; }
void LeggedMammal::setFurKind(std::string furKind) {
    if (isFurKind(furKind)) {
        this->furKind = furKind;
    } else {
        std::cout << "\"" << furKind << "\" Fur Kind does not exist. Fur Kind set to \"Thick\"...";
        this->furKind = "Thick";
    }
}


std::string LeggedMammal::getSpecies() { return this->species; }
short LeggedMammal::getLegNumber() { return this->legNumber; }
std::string LeggedMammal::getFurKind() { return this->furKind; }
std::string LeggedMammal::getHasTail() {
    if (this->hasTail) {
        return "Yes";
    } else {
        return "No";
    }
}

std::ostream &operator<<(std::ostream &o, LeggedMammal &m) {
    o  << "---------------------------------\n"
       << "  Member of Legged Mammal Class\n" 
       << "---------------------------------\n"
       << "  Species:\t" << m.getSpecies() << "\n"
       << "  Leg Number:\t" << m.getLegNumber() << "\n"
       << "  Fur Kind:\t" << m.getFurKind() << "\n"
       << "  Has Tail:\t" << m.getHasTail() << "\n"
       << "---------------------------------";
    return o;
}

#endif // _LEGGED_MAMMAL_H
