/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Employee Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/31 - 12:28 | Draft 1
 *  - 2023/08/xx - xxx | Final
 * ************************************************************************************/

#pragma once    // instead of “#ifndef – #define – #endif” combination

#include <iostream>
#include <string>
#include "_helpers.h"
#include "_payslip.h"

// genders
#define MALE false
#define FEMALE true

class Employee
{
private:
    // regular properties
    std::string name;
    bool gender;
    short age;
    std::string occupation;
    double basSal;
    PaySlip pSlip;


public:
    // constructor
    Employee(void);
    Employee(std::string, bool, short, std::string, double, double);

    // setters/getters
    void setName(std::string);
    void setGender(bool);
    void setAge(short);
    void setOccupation(std::string);
    void setBasSal(double);
    void setPaySlip(double);
    std::string getName(void);
    bool getGender(void);
    short getAge(void);
    std::string getOccupation(void);
    double getBasSal(void);
    PaySlip getPaySlip(void);

};

Employee::Employee() : Employee("No Name",MALE,0,"None",PaySlip::MIN_SAL,PaySlip::MIN_OT_HRS) { }
Employee::Employee(std::string name, bool gender, short age, std::string occupation, double basSal, double otHrs) {
    this->setName(name);
    this->setGender(gender);
    this->setAge(age);
    this->setOccupation(occupation);
    this->setBasSal(basSal);
    //this->setPaySlip(otHrs);
}

void Employee::setName(std::string name) { this->name = name; } 
void Employee::setGender(bool gender) { this->gender = gender; }
void Employee::setAge(short age) { this->age = age; }
void Employee::setOccupation(std::string occupation) { this->occupation = occupation; }
void Employee::setBasSal(double basSal) { this->basSal = basSal; }

void Employee::setPaySlip(double otHrs) {
    this->pSlip = PaySlip(this->name,this->basSal,otHrs);
}

std::string Employee::getName() { return this->name; }
bool Employee::getGender() { return this->gender; }
short Employee::getAge() { return this->age; }
std::string Employee::getOccupation() { return this->occupation; }


std::ostream &operator<<(std::ostream &o, Employee &p) {
    o  << "-------------------------------------\n"
       << "           Employee Info\n" 
       << "-------------------------------------\n"
       << "  Name:\t\t" << p.getName() << "\n"
       << "  Gender:\t" << (p.getGender() ? "Female" : "Male") << "\n"
       << "  Age:\t\t" << p.getAge() << "\n"
       << "  Occupation:\t" << p.getOccupation() << "\n"
       << "-------------------------------------";
    return o;
}
