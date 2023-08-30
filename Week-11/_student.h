/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Student Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/30 - 11:03 | Draft
 *  - 2023/08/30 -  | Final
 * ************************************************************************************/

#pragma once    // instead of “#ifndef – #define – #endif” combination

#include "_person.h"

class Student : public Person
{
private:
    // regular properties
    std::string university;
    std::string program;
    short year;
    float units;


    // privatized parent methods
    using Person::setOccupation;
    using Person::ageRange;

public:
    // constructor
    Student(void);
    Student(std::string, bool, short, std::string, std::string, short, float);

    // setters/getters
    void setUniversity(std::string);
    void setProgram(std::string);
    void setYear(short);
    void setUnits(float);
    std::string getUniversity(void);
    std::string getProgram(void);
    short getYear(void);
    float getUnits(void);

    // methods
    std::string yearName(void);
    float totalTuition(void);

};


Student::Student() : Student("No Name",MALE,0,"No University","No Program",0,0) { }
Student::Student(std::string name, bool gender, short age, std::string university, std::string program, short year, float units)
    : Person::Person(name, gender, age, "Student") {
        this->setUniversity(university);
        this->setProgram(program);
        this->setYear(year);
        this->setUnits(units);
}


void Student::setUniversity(std::string university) { this->university = university; }
void Student::setProgram(std::string program) { this->program = program; }
void Student::setUnits(float units) { this->units = units; }
void Student::setYear(short year) { 
    this->year = year < 1 ? 1 : year; 
}

std::string Student::getUniversity() { return this->university; }
std::string Student::getProgram() { return this->program; }
short Student::getYear() { return this->year; }
float Student::getUnits() { return this->units; }

std::string Student::yearName() {
    const std::vector<std::string> yearNames = {"Freshman","Sophomore","Junior","Senior"};
    return yearNames[this->getYear() > 4 ? 3 : (this->getYear() - 1)];
}

float Student::totalTuition() {
    const std::vector<float> tuitionRates = {1500,1800,2000,2300};
    return tuitionRates[this->getYear() > 4 ? 3 : (this->getYear() - 1)] * this->getUnits();
}

Student studentFromInput() {
    auto s = Student();
    std::string t; char c; short i; float f;

    std::cout << " Student Name: ";
    std::getline(std::cin,t);
    s.setName(t);
    _flush_inputs();

    do {
        std::cout << " Gender (F/M): ";
        c = (char) std::getchar();
        _flush_inputs();
        if (c=='M' || c=='m') {
            s.setGender(MALE);
            break;
        } else if (c=='F' || c=='f') {
            s.setGender(FEMALE);
            break;
        }
    } while (true);

    std::cout << " Age: ";
    std::cin >> i;
    s.setAge(i);
    _flush_inputs();

    std::cout << " Student's University: ";
    std::getline(std::cin,t);
    s.setUniversity(t);
    _flush_inputs();

    std::cout << " Program/Course: ";
    std::getline(std::cin,t);
    s.setProgram(t);
    _flush_inputs();

    std::cout << " Year Level: ";
    std::cin >> i;
    s.setYear(i);
    _flush_inputs();

    std::cout << " Number of Units Enrolled: ";
    std::cin >> f;
    s.setUnits(f);
    _flush_inputs();

    return s;
 }

std::ostream &operator<<(std::ostream &o, Student &s) {
    o  << "------------------------------------------\n"
       << "      \033[1;31m" << s.getUniversity() << "\033[1;34m | Student Info \033[1;0m \n" 
       << "------------------------------------------\n"
       << "  Name:\t\t\t" << s.getName() << "\n"
       << "  Gender:\t\t" << (s.getGender() ? "Female" : "Male") << "\n"
       << "  Age:\t\t\t" << s.getAge() << "\n"
       << "  Year Level:\t\t" << s.getYear() << "\n"
       << "  Year Name:\t\t" << s.yearName() << "\n"
       << "  Units Enrolled:\t" << s.getUnits() << "\n"
       << "  Total Tuition Fee:\t" << s.totalTuition() << "\n"
       << "-------------------------------------------";
    return o;
}