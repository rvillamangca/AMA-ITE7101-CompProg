/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Person Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 13:09 | Draft 1
 *  - 2023/08/28 - 13:42 | Final
 * ************************************************************************************/

#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
#include <string>
#include "_helpers.h"

// genders
#define MALE 0
#define FEMALE 1

class Person
{
private:
    // regular properties
    std::string name;
    bool gender;
    short age;
    std::string occupation;

public:
    // constructor/destructor
    Person(void);
    Person(std::string, bool, short, std::string);

    // setters/getters
    void setName(std::string);
    void setGender(bool);
    void setAge(short);
    void setOccupation(std::string);
    std::string getName(void);
    std::string getGender(void);
    short getAge(void);
    std::string getOccupation(void);

    // methods
    std::string ageRange();  
};

Person::Person() : Person("No Name",MALE,0,"None") { }
Person::Person(std::string name, bool gender, short age, std::string occupation) {
    this->setName(name);
    this->setGender(gender);
    this->setAge(age);
    this->setOccupation(occupation);
}

void Person::setName(std::string name) { this->name = name; }
void Person::setGender(bool gender) { this->gender = gender; }
void Person::setAge(short age) { this->age = age; }
void Person::setOccupation(std::string occupation) { this->occupation = occupation; }

std::string Person::getName() { return this->name; }
std::string Person::getGender() { return this->gender ? "Female" : "Male"; }
short Person::getAge() { return this->age; }
std::string Person::getOccupation() { return this->occupation; }

std::string Person::ageRange() {
    if (this->age < 2) return "Baby";
    if (this->age < 13) return "Child";
    if (this->age < 21) return "Adolescent";
    return "Adult";
}


std::ostream &operator<<(std::ostream &o, Person &p) {
    o  << "-------------------------------------\n"
       << "        Member of Person Class\n" 
       << "-------------------------------------\n"
       << "  Name:\t\t" << p.getName() << "\n"
       << "  Gender:\t" << p.getGender() << "\n"
       << "  Age:\t\t" << p.getAge() << "\n"
       << "  Age Range:\t" << p.ageRange() << "\n"
       << "  Occupation:\t" << p.getOccupation() << "\n"
       << "-------------------------------------";
    return o;
}

#endif // _PERSON_H
