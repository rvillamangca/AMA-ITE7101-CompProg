/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Dog Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/29 - 10:05 | Draft
 *  - 2023/08/30 - 09:24 | Final
 * ************************************************************************************/

#pragma once    // instead of “#ifndef – #define – #endif” combination

#include "_legged_mammal.h"

typedef enum { SMALL, MEDIUM, LARGE, XLARGE, } DogSize;

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

    // other methods
    bool isDangerous(void);

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
    std::string threatLevel(void);

// friends:
    friend std::ostream &operator<<(std::ostream&, Dog&);
};


Dog::Dog() : Dog("No Name","No Breed","Medium",MEDIUM,false,0,false) { }
Dog::Dog(std::string name, std::string breed, std::string furKind, DogSize size, bool isRegistered, short numBitten, bool isRabid)
    : LeggedMammal("Canis Familiaris",4,furKind,true) {
        this->setName(name);
        this->setBreed(breed);
        this->setSize(size);
        this->setIsRegistered(isRegistered);
        this->setNumBitten(numBitten);
        this->setIsRabid(isRabid);
}

    void Dog::setName(std::string name) { this->name = name; }
    void Dog::setBreed(std::string breed) { this->breed = breed; }
    void Dog::setSize(DogSize size) { this->size = size; }
    void Dog::setIsRegistered(bool isRegistered) { this->isRegistered = isRegistered; }

    void Dog::setNumBitten(short numBitten) { 
        this->numBitten = numBitten;
        this->isDangerous(); 
    }

    void Dog::setIsRabid(bool isRabid) { 
        this->isRabid = isRabid; 
        this->isDangerous();
    }

    std::string Dog::getName(void) { return this->name; }
    std::string Dog::getBreed(void) { return this->breed; }
    DogSize Dog::getSize(void) { return this->size; }
    bool Dog::getIsRegistered(void) { return this->isRegistered; }
    short Dog::getNumBitten(void) { return this->numBitten; }
    bool Dog::getIsRabid(void) {return this->isRabid; }

    bool Dog::isDangerous() {
        return (this->numBitten >= 10) || (this->isRabid);
    }

    std::string Dog::threatLevel() {
        return this->isDangerous() ? "\033[1;31mDangerous\033[1;0m" : "\033[1;34mBenign\033[1;0m";
    }

    std::ostream &operator<<(std::ostream &o, Dog &d) {
        std::vector<std::string> dogSize = {"Small Dog", "Medium-built Dog", "Large Dog", "Huge Dog"};
        std::string c = "\033[1;0m";
        o  << "---------------------------------------------\n"
           << "\033[1;32m" << "            Member of Dog Class" << "\033[1;0m" << "\n" 
           << "---------------------------------------------\n"
           << "  Name:\t\t\t" << d.getName() << "\n"
           << "  Species:\t\t" << d.getSpecies() << "\n"
           << "  Breed:\t\t" << d.getBreed() << "\n"
           << "  Fur Kind:\t\t" << d.getFurKind() << "\n"
           << "  Stature:\t\t" << dogSize[d.getSize()] << "\n"
           << "  Registered:\t\t" << (d.getIsRegistered() ? "Yes" : "No") << "\n"
           << "  Threat Level:\t\t" << d.threatLevel() << "\n"
           << "----------------------------------------------";
        return o;
    }