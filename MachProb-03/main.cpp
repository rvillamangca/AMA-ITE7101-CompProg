/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #009
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/29 - 09:50 | Draft
 *  - 2023/08/30 - 20:42 | Final
 * ************************************************************************************/

#include <iostream>             // to basic input/output
#include "_helpers.h"           // to access the helper functions
#include "_employee.h"          // to access the Employee class
#include "_paySlip.h"           // to access the Pay Slip class

using namespace std;

int main() {

    //auto p = PaySlip();
    PaySlip p;

    cout << p;

    p = PaySlip("ramon", 10000, 10);
    
    cout << p;

    p.setBasSal(55000);

    cout << endl << p;


    /*do {
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
            for (auto i = 1; i <= 3; i++) {
                _clrscr();
                cout << "Please provide Student #" << i << " info..." << endl << endl;
                _nap();
                auto s = studentFromInput();
                cout << endl << s << endl;
                _sleep();
                _flush_inputs();
            }
            _flush_inputs();
            _pause("Press any key to return to the Menu... ");
            
        } else if (ans == 'q' || ans == 'Q') {
            break;
        }    
    } while (true);*/
    
    //_sleep();
    _pause();
    _clrscr();

    return 0;
}
