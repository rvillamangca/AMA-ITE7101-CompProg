/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Employee Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/31 - 12:28 | Draft 1
 *  - 2023/09/01 - 00:39 | Final
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
    // fields
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
    Employee(std::string, bool, short, std::string, double);

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

    // overloaded operators
    friend std::ostream &operator<<(std::ostream&, Employee&);

    // our unfortunate main function
    static int main(void);
};

Employee::Employee() : Employee("No Name",MALE,0,"None",PaySlip::MIN_SAL,PaySlip::MIN_OT_HRS) { }

Employee::Employee(std::string name, bool gender, short age, std::string occupation, double basSal)
    : Employee(name, gender, age, occupation, basSal, PaySlip::MIN_OT_HRS) { }

Employee::Employee(std::string name, bool gender, short age, std::string occupation, double basSal, double otHrs) {
    this->setName(name);
    this->setGender(gender);
    this->setAge(age);
    this->setOccupation(occupation);
    this->setBasSal(basSal);
    this->setPaySlip(otHrs);
    //std::cout << this->pSlip << "\n";
}

void Employee::setName(std::string name) { this->name = name; } 
void Employee::setGender(bool gender) { this->gender = gender; }
void Employee::setAge(short age) { this->age = age; }
void Employee::setOccupation(std::string occupation) { this->occupation = occupation; }
void Employee::setBasSal(double basSal) { this->basSal = basSal; }

void Employee::setPaySlip(double otHrs) {   
    //auto p = PaySlip(this->name,this->basSal,otHrs);
    this->pSlip = PaySlip(this->name,this->basSal,otHrs);
    std::cout << this->pSlip << "\n";
}

std::string Employee::getName() { return this->name; }
bool Employee::getGender() { return this->gender; }
short Employee::getAge() { return this->age; }
std::string Employee::getOccupation() { return this->occupation; }
PaySlip Employee::getPaySlip() { return this->pSlip; }


std::ostream &operator<<(std::ostream &o, Employee &p) {
    o  << "-----------------------------------------------------\n"
       << "                 Employee Information\n" 
       << "-----------------------------------------------------\n"
       << "  Name:\t\t" << p.name << "\n"
       << "  Gender:\t" << (p.gender ? "Female" : "Male") << "\n"
       << "  Age:\t\t" << p.age << "\n"
       << "  Occupation:\t" << p.occupation << "\n"
       << "-----------------------------------------------------\n";
    return o;
}

int Employee::main() {
    std::string name;
    bool gender;
    short age;
    std::string occupation;
    double basSal;
    double otHrs;

    bool stop = false;
    do {
        _clrscr();
        std::cout << "\nPlease provide Employee info...\n\n";
        _nap();

        std::cout << " Employee Name: ";
        std::getline(std::cin,name);
        _flush_inputs();

        do {
            std::cout << " Gender (F/M): ";
            auto c = (char) std::getchar();
            _flush_inputs();
            if (c=='M' || c=='m') {
                gender = MALE;
                break;
            } else if (c=='F' || c=='f') {
                gender = FEMALE;
                break;
            }
        } while (true);

        std::cout << " Age: ";
        std::cin >> age;
        _flush_inputs();

        std::cout << " Occupation: ";
        std::getline(std::cin,occupation);
        _flush_inputs();

        std::cout << " Basic Salary: ";
        std::cin >> basSal;
        _flush_inputs();

        std::cout << " Overtime Hours: ";
        std::cin >> otHrs;
        _flush_inputs();

        auto em = Employee(name, gender, age, occupation, basSal, otHrs);
        auto ps = em.getPaySlip();

        _clrscr();
        std::cout << em << "\n" << ps << "\n\n"; 

        do {
            std::cout << "Do you want to continue (Y/N)? ";
            auto c = (char) std::getchar();
            _flush_inputs();
            if (c=='N' || c=='n') {
                stop = true;
                break;
            } else if (c=='Y' || c=='y') {
                break;
            }
        } while (true);
        if (stop) break;
    } while (true);

    std::cout << "Thank you for using the program. Goodbye...";

    _sleep();
    _clrscr();

    return 0;
}
