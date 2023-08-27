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
    std::string pType;
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
    std::string getColot(void);
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
   this->pName = 
   this->pType = 
   
}



#endif // _POLYGON_H
