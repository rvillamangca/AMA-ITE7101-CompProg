/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Polygon Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 14:52 | Draft 1
 *  - 2023/08/28 - 13:42 | Final
 * ************************************************************************************/

#ifndef _POLYGON_H
#define _POLYGON_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "_helpers.h"


class Polygon
{
private:
    // static properties
    static std::vector<std::string> pTypes;
    static std::vector<std::string> pColors;
    static std::vector<std::string> pColorCodes;

    // regular properties
    std::string pName;
    int pSideNum;
    double pSideLength;
    std::string pColor;
    
public:
    // constructor/destructor
    Polygon(void);
    Polygon(std::string, int, double, std::string);

    // setters/getters
    void setName(std::string);
    void setSideNum(int);
    void setSideLength(double);
    void setColor(std::string);
    std::string getName(void);
    int getSideNum(void);
    double getSideLength(void);
    std::string getColor(void);
    std::string getType(void);
    double getPerimeter(void);
    double getArea(void);

    // friends
    friend std::ostream &operator<<(std::ostream&, Polygon&); 
};

std::vector<std::string>Polygon::pTypes 
    { "Triangle","Quadrilateral","Pentagon","Hexagon", "Heptagon", "Octagon", "Nonagon", 
      "Decagon", "Hendecagon", "Dodecagon", "Tridecagon", "Tetradecagon", "Pentadecagon", 
      "Hexadecagon", "Heptadecagon", "Octadecagon", "Enneadecagon", "Icosagon" };

std::vector<std::string>Polygon::pColors {"Red","Green","Yellow","Blue","Magenta","Cyan"};
std::vector<std::string>Polygon::pColorCodes {"\033[1;31m","\033[1;32m","\033[1;33m","\033[1;34m","\033[1;35m","\033[1;36m"};

Polygon::Polygon(std::string name, int num=3, double len=1.0, std::string color="Red") {
    this->setName(name);
    this->setSideNum(num);
    this->setSideLength(len);
    this->setColor(color);
}
Polygon::Polygon() : Polygon("yourTriangle") { }

void Polygon::setName(std::string name) { this->pName = name; }
void Polygon::setSideLength(double len) { this->pSideLength= len; }
void Polygon::setColor(std::string color) { this->pColor = color; }
void Polygon::setSideNum(int num) { 
    if (num > 2) { 
        this->pSideNum = num; 
    } else {
        std::cout << "Number of sides will be set to minimum = 3";
        this->pSideNum = 3;
    }
}

std::string Polygon::getName() { return this->pName; }
double Polygon::getSideLength() { return this->pSideLength; }
std::string Polygon::getColor() { return this->pColor; }
int Polygon::getSideNum() { return this->pSideNum; }

std::string Polygon::getType() {
    auto i = this->pSideNum - 3;
    if (i < pTypes.size()) return pTypes[i];
    return std::to_string(this->pSideNum) + "-gon";
}

double Polygon::getPerimeter() { return double(this->pSideNum) * (this->pSideLength); }

double Polygon::getArea() {
    double n = this->pSideNum;
    double s = this->pSideLength;
    return (n * pow(s,2)) / (4 * tan(M_PI/n));   // pow(), tan() and M_PI are in cmath library
}

std::ostream &operator<<(std::ostream &o, Polygon &p) {
    std::string c = "\033[1;0m";
    for (int i = 0; i < Polygon::pColors.size();i++) {
        if (p.getColor() == Polygon::pColors[i]) c = Polygon::pColorCodes[i];
    }
    o  << "-----------------------------------\n"
       << "      Member of Polygon Class\n" 
       << "-----------------------------------\n"
       << "  Name:\t\t" << p.getName() << "\n"
       << "  Type:\t\t" << p.getType() << "\n"
       << "  Side Number:\t" << p.getSideNum() << "\n"
       << "  Side Length:\t" << p.getSideLength() << "\n"
       << "  Perimeter:\t" << p.getPerimeter() << "\n"
       << "  Area:\t\t" << p.getArea() << "\n"
       << "  Color:" << c << "\t" << p.getColor() << "\033[1;0m" << "\n"
       << "-----------------------------------";
    return o;
}

#endif // _POLYGON_H
