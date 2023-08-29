/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Dog Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 08:05 | Draft 1
 *  - 2023/08/28 - 13:42 | Final
 * ************************************************************************************/

#pragma once    // instead of “#ifndef – #define – #endif” combination

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "_legged_mammal.h"
#include "_helpers.h"


typedef enum { SMALL, MEDIUM, LARGE, HUMONGOUS, } DogSize;

class Dog : LeggedMammal
{
private:
    // regular properties
    std::string name;
    std::string breed;
    DogSize size;
    bool isRegistered;
    short numBitten;
    bool isRabid;

    // privatized parent methods
    using LeggedMammal::setSpecies;
    using LeggedMammal::setLegNumber;
    using LeggedMammal::setHasTail;

public:
    // constructor
    Dog(void);
    Dog(std::string, std::string, std::string, DogSize, bool, short, bool);

    // setters/getters
    void setName(std::string);
    void setBreed(std::string);
    void setSize(DogSize);
    void setIsRegistered(bool);
    void setNumBitten(short);
    void setIsRabid(bool);
    std::string getName(void);
    std::string getBreed(void);
    DogSize getSize(void);
    bool getIsRegistered(void);
    short getNumBitten(void);
    bool getIsRabid(void);

    // other methods
    bool isLethal(void);

// friends:
    friend std::ostream &operator<<(std::ostream&, Dog&);
};


Dog::Dog() : Dog("No Name","No Breed","Medium",MEDIUM,false,0,false) { }
Dog::Dog(std::string name, std::string breed, std::string furKind, DogSize size, bool isRegistered, short numBitten, bool isRabid){
    this->setSpecies("Canis Familiaris");
    this->setLegNumber(4);
    this->setHasTail(true);
    this->setName(name);
    this->setBreed(breed);
    this->setFurKind(furKind);
    this->setSize(size);
    this->setIsRegistered(isRegistered);
    this->setNumBitten(numBitten);
    this->setIsRabid(isRabid);
}

    void Dog::setName(std::string name) { this->name = name; }
    void Dog::setBreed(std::string breed) { this->breed = breed; }
    void Dog::setSize(DogSize size) { this->size = size; }
    void Dog::setIsRegistered(bool isRegistered) { this->isRegistered = isRegistered; }
    void Dog::setNumBitten(short numBitten) { this->numBitten = numBitten; }
    void Dog::setIsRabid(bool isRabid) { this->isRabid = isRabid; }
    std::string Dog::getName(void) { return this->name; }
    std::string Dog::getBreed(void) { return this->breed; }
    DogSize Dog::getSize(void) { return this->size; }
    bool Dog::getIsRegistered(void) { return this->isRegistered; }
    short Dog::getNumBitten(void) { return this->numBitten; }
    bool Dog::getIsRabid(void) {return this->isRabid; }

    bool Dog::isLethal() {
        return (this->numBitten >= 10) || (this->isRabid);
    }


    std::ostream &operator<<(std::ostream &o, Dog &d) {
        std::vector<std::string> dogSize = {"Small", "Medium", "Large", "Huge"};
        std::string c = "\033[1;0m";
        o  << "-------------------------------------\n"
           << c << "    Member of Dog Class" << c << "\n" 
           << "-------------------------------------\n"
           << "  Name:\t\t" << d.getName() << "\n"
           << "  Species:\t\t" << d.getSpecies() << "\n"
           << "  Breed:\t" << d.getBreed() << "\n"
           << "  Fur Kind:\t\t" << d.getFurKind() << "\n"
           << "  Stature:\t\t" << dogSize[d.getSize()] << "\n"
           << "  Is Registered:\t\t" << (d.getIsRegistered() ? "Yes" : "No") << "\n"
           << "  Threat Level:\t\t" << (d.isLethal() ? "Lethal" : "Benign") << "\n"
           << "-------------------------------------";
        return o;
    }