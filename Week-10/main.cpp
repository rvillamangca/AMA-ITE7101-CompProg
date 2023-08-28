/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #009
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 13:02 | Draft 1
 *  - 2023/08/28 - 13:42 | Final
 * ************************************************************************************/

#include <iostream>             // to basic input/output
#include <string>               // to access the STL string class methods
#include <array>                // to access the STL array class methods
#include <cmath>                // to access basic math functions
#include "_helpers.h"           // to access the helper functions
#include "_legged_mammal.h"     // to access the Legged Mammal class
#include "_person.h"            // to access the Person class
#include "_polygon.h"           // to access the Polygon class

using namespace std;

int main() {

    do {
        _clrscr();
        cout << "--- Class Testing Program ---------------\n\n";
        cout << "   1. Legged Mammal Class" << endl;
        cout << "   2. Person Class" << endl;
        cout << "   3. Polygon Class" << endl;
        cout << "   Q: Exit Program" << endl << endl;
        cout << "-----------------------------------------\n\n";
        cout << "Select the number of the Class you want to test or 'Q' to quit: ";
        char ans = (char) getchar();

        if (ans == '1') {
            _clrscr();
            auto dog = new LeggedMammal("Dog",2,"medium",true);
            cout<< "Here is a dog for you: " << endl << *dog << endl << endl; 
            auto cat = new LeggedMammal("Kat",2,"liGht",true);;
            cat->setSpecies("Cat");
            cout << "Here is a cat for you: " << "This " << cat->getSpecies() << " has " << _to_lower(cat->getFurKind()) << " fur." << endl << endl;
            cout << "Creating a monster...\t";
            auto monster = new LeggedMammal();
            monster->setLegNumber(25);
            monster->setHasTail(false);
            monster->setFurKind("Horible");
            cout << endl << endl << "Here is a monster for you: " << endl << *monster;
            monster->setSpecies("Monster");
            cout << endl;    
            delete(monster);   
            cout << endl;     
            _flush_inputs();
            _pause("Press any key to return to the Menu...");

        } else if (ans == '2') {
            _clrscr();
            for (auto i = 1; i <= 3; i++) {
                string name; string gens; bool genb; short age; string occu; 
                cout << endl << "Enter your name: ";
                getline(cin,name);
                _flush_inputs();
                cout << endl << "Enter your gender: ";
                cin >> gens;
                if (_to_lower(gens)=="woman" || _to_lower(gens)=="lady" 
                    || _to_lower(gens)=="girl" || _to_lower(gens)=="female") {
                    genb = FEMALE;
                } else {
                    genb = MALE;
                }
                _flush_inputs();
                cout << endl << "Enter your age: ";
                cin >> age;
                _flush_inputs();
                cout << endl << "Enter your occupation: ";
                cin >> occu;
                _flush_inputs();
                auto person = Person(name,genb,age,occu);
                cout << endl << "Here is your Bio: " << endl << person << endl << endl;
                if (i < 3) _pause();
            }
            _flush_inputs();
            _pause("Press any key to return to the Menu... ");

        } else if (ans == '3') {
            do {
                _clrscr();
                string tmp;
                auto p = Polygon();
                cout << endl << "Enter polygon name: ";
                getline(cin,tmp);
                p.setName(tmp);
                cout << endl << "Enter number of sides: ";
                cin >> tmp;
                p.setSideNum(stoi(tmp));
                cout << endl << "Enter length of sides: ";
                cin >> tmp;
                p.setSideLength(stod(tmp));
                cout << endl << "Enter polygon color: ";
                cin >> tmp;
                p.setColor(tmp);
                cout << endl << "Here is your Polygon: " << endl << p << endl << endl;
                _flush_inputs();
                cout << "Press Q to return to the Menu or any other key to continue: ";
                char a = (char) getchar();
                if (a == 'q' || a == 'Q') break;
            } while (true);
            _flush_inputs();
        } else if (ans == 'q' || ans == 'Q') {
            break;
        }    
    } while (true);
    
    _nap();
    _clrscr();

    return 0;
}
