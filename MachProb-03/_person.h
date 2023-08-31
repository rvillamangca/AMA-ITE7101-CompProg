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
    // constructor
    Person(void);
    Person(std::string, bool, short, std::string);

    // setters/getters
    void setName(std::string);
    void setGender(bool);
    void setAge(short);
    void setOccupation(std::string);
    std::string getName(void);
    bool getGender(void);
    short getAge(void);
    std::string getOccupation(void);

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
bool Person::getGender() { return this->gender; }
short Person::getAge() { return this->age; }
std::string Person::getOccupation() { return this->occupation; }


std::ostream &operator<<(std::ostream &o, Person &p) {
    o  << "-------------------------------------\n"
       << "        Member of Person Class\n" 
       << "-------------------------------------\n"
       << "  Name:\t\t" << p.getName() << "\n"
       << "  Gender:\t" << (p.getGender() ? "Female" : "Male") << "\n"
       << "  Age:\t\t" << p.getAge() << "\n"
       << "  Occupation:\t" << p.getOccupation() << "\n"
       << "-------------------------------------";
    return o;
}

#endif // _PERSON_H
