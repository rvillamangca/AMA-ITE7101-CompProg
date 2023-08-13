/* **************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory 003
 * @app desc: Completion of a laboratory exercise for ITE-17101 (Computer Programming)
 * @history:
 *  - 2023/08/12 | Solutions for Lab Exercise
 *      -- Laboratory Exercise 004
 * ***********************************************************************************/

#include <iostream>
#include <iomanip>

// following #define statement only works in MacOS(arm64)
// please comment this #define if in Windows(x86)
#define _pause() system("read -n 1 -s -p \"Press any key to continue...\"" );

using namespace std;

int main() {

    //Solution 01:
    /*short section;
    cout << endl << "Please enter your section: ";
    cin >> section;
    cout << endl << "*** Section: " << section << " ***" << endl;*/

    //Solution 02:
    /*float dailyBudget;
    cout << endl << "Please enter your daily budget: ";
    cin >> dailyBudget;
    cout << fixed << setprecision(2);
    cout << endl << "Your daily budget squared is: "
         << dailyBudget * dailyBudget << endl;*/

    //Solution 03:
    string userName, userPass, userAddress; // only 3 variables
    cout << endl << "Please enter your name: ";
    getline(cin,userName);
    cout << "Please enter your password: ";
    getline(cin,userPass);
    cout << "Please enter your address: ";
    getline(cin,userAddress);
    cout << endl << "Hi, I am " << userName << ". I live at "
         << userAddress << "." << endl;

    cin.clear();
    fflush(stdin);
    cout << endl;
    _pause();
    return 0;
}
