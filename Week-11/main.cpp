/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #009
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/29 - 09:50 | Draft
 *  - 2023/08/XX - 13:42 | Final
 * ************************************************************************************/

#include <iostream>             // to basic input/output
#include <string>               // to access the STL string class methods
#include <array>                // to access the STL array class methods
#include <cmath>                // to access basic math functions
#include "_helpers.h"           // to access the helper functions
//#include "_legged_mammal.h"     // to access the Legged Mammal class
//#include "_person.h"            // to access the Person class
//#include "_polygon.h"           // to access the Polygon class
#include "_dog.h"
#include "_student.h"

using namespace std;

int main() {


    do {
        _clrscr();
        cout << endl << "---" << "\033[1;31m" << " SubClass Testing Program "; 
        cout << "\033[1;0m" << "----------------------------\n\n";
        cout << "   1. Dog Class (Inherited from Legged Mammal Class)" << endl;
        cout << "   2. Student Class (Inherited from Person Class)" << endl;
        cout << "   Q: Exit Program" << endl << endl;
        cout << "---------------------------------------------------------\n\n";
        cout << "Select the number of the SubClass you want to test or 'Q' to quit: ";
        char ans = (char) getchar();

        if (ans == '1') {
            _clrscr();
            auto dog1 = Dog("Bob","Saint Bernard","Thick",XLARGE,true,25,false);
            cout << endl << "Dog #1" << endl << dog1 << endl << endl; 
            auto dog2 = Dog("Jack","Hairless Terrier","None",SMALL,true,0,false);
            dog2.setNumBitten(5);
            cout << "Dog #2" << endl << dog2 << endl << endl;  
            auto dog3 = Dog();
            dog3.setName("Booby");
            dog3.setBreed("Mixed Breed");
            dog3.setSize(LARGE);
            dog3.setIsRegistered(false);
            dog3.setNumBitten(0);
            dog3.setIsRabid(false);
            cout << "Dog #3: " << dog3.getName() << " is " << dog3.threatLevel()
                 << ", it is " << _to_lower(dog3.getIsRegistered() ? "registered" : "unregistered")
                 << ", has bitten " << dog3.getNumBitten() << " people, and is "
                 << (dog3.getIsRabid() ? "rabid." : "not rabid.") << endl << endl;
            auto dog4 = Dog();
            dog4.setName("Pogi");
            dog4.setBreed("Askal");
            dog4.setIsRegistered(false);
            dog4.setNumBitten(100);
            dog4.setIsRabid(true);
            cout << "Dog #4: " << dog4.getName() << " is " << dog4.threatLevel()
                 << ", it is " << _to_lower(dog4.getIsRegistered() ? "registered" : "unregistered")
                 << ", has bitten " << dog4.getNumBitten() << " people, and is "
                 << (dog4.getIsRabid() ? "rabid." : "not rabid.") << endl << endl;
            _flush_inputs();
            _pause("Press any key to return to the Menu...");

        } else if (ans == '2') {
            Student s;

            cout << s;
            _flush_inputs();
            _pause();
            /*_clrscr();
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
            _pause("Press any key to return to the Menu... ");*/

        } else if (ans == 'q' || ans == 'Q') {
            break;
        }    
    } while (true);
    
    _nap();
    _clrscr();

    return 0;
}
