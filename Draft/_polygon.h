/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Polygon Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 14:52 | Draft 1
 * ************************************************************************************/

#ifndef _POLYGON_H
#define _POLYGON_H

#include <iostream>
#include <string>
#include <vector>
#include "_helpers.h"


class Polygon
{
private:
    // static properties
   static std::vector<std::string> pTypes;

    // regular properties
    std::string pName;
    int pSideNum;
    double pSideLength;
    std::string pColor;
    
public:
    // constructor/destructor
    Polygon(void);
    Polygon(std::string, int, double, std::string);
    ~LeggedMammal(void);

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
};

std::vector<std::string>Polygon::pTypes {
    "Triangle","Quadrilateral","Pentagon","Hexagon", "Heptagon",
    "Octagon", "Nonagon", "Decagon", "Hendecagon", "Dodegacon",
    "Tridecagon", "Tetradecagon", "Pentadecagon", "Hexadecagon",
    "Heptadecagon", "Octadecagon", "Enneadecagon", "Icosagon"
};

Polygon:Polygon() {
    this->setName("");
    this->setSideNum(3);
    this->setSideLength(1.0);
    this->setColor("White");
}

Polygon::Polygon(std::string name, int num; double len; std::string color) {
    this->setName(name);
    this->setSideNum(num);
    this->setSideLength(len);
    this->setColor(color);
}

void Polygon::setName(std::string name) { this->pName = name; }
void Polygon::setSideLength(double len) { this->pSideLength= len; }
void Polygon::setColor(std::string color) { this->pColor = color; }
void Polygon::setSideNum(int num) { 
    if (num > 2) { 
        this->sideNum = num; 
    } else {
        std::cout << "Polygon side number will be set to minimum: 3";
        this->sideNum = 3;
    }
}

std::string Polygon::getName() { return this->pName; }
double Polygon::getSideLength { return this->sideLength; }
std::string Polygon::getColor { return this->pColor; }
int Polygon::getSideNum() { return this->sideNum; }

std::string Polygon::getType() {
    int i = this->pSideNum - 3;
    if (i >= pTypes.size) return "" + (this->pSideNum) + "-gon";
    return pTypes[i];
}

double Polygon::getPerimeter() { return double(this->pSideNum) * (this->pSideLength); }

#endif // _POLYGON_H
