/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #009
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/27 - 13:02 | Draft 1
 * ************************************************************************************/

#include <iostream>             // to basic input/output
#include <string>               // to access the STL string class methods
#include <array>                // to access the STL array class methods
#include <cmath>                // to access basic math functions
#include "_helpers.h"           // to access the helper functions
#include "_legged_mammal.h"     // to access the Legged Mammal class
#include "_person.h"            // to access the Person class
#include "_polygon.h"


using namespace std;


int main() {

    auto m = LeggedMammal("Dog",4,"medium",true);

    cout << endl << m;

    auto p = Person("Ramon Villamangca",MALE,50,"Engineer");

    cout << endl << p;

    //auto pn = Polygon("Your Polygon",4,1,"Blue");
    auto pn = Polygon();

    cout << endl << pn;

    /*
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
            
            _flush_inputs();
            _pause();

        } else if (ans == '2') {
            _clrscr();
            
            _flush_inputs();
            _pause();

        } else if (ans == '3') {
            _clrscr();
            
            _flush_inputs();
            _pause();
        } else if (ans == 'q' || ans == 'Q') {
            break;
        }    
    } while (true);
    
    _nap();
    _clrscr();
    */

    return 0;
}
