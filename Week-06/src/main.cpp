/* **************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory 005
 * @app desc: Completion of a laboratory exercise for ITE-17101 (Computer Programming)
 * @history:
 *  - 2023/08/14 | Solutions for Lab Exercise
 *      -- Laboratory Exercise 005
 * ************************************************************************************/

#include <iostream>

using namespace std;

inline void _pause() {
    cout << "Press any key to continue...";
    cin.get();
    cout << endl;
}
inline void _flush_inputs() {
    cin.clear();
    fflush(stdin);
}

int main() {

    //Solution 01/1:
    /*int num;
    cout << endl << "Please enter an number (only \"Integers\" are allowed): ";
    cin >> num;
    cout << endl;
    if (cin.fail()) {
        cout << "Yeah, I will";
    } else if (num==0) {
        cout << "Hello World";
    } else if (num==1) {
        cout << "I am groot";
    } else if (num==2) {
        cout << "To the Top";
    } else if (num==3) {
        cout << "Where is the horizon";
    } else if (num==4) {
        cout << "I don't know";
    } else {
        cout << "Yeah, I will";
    }*/

    //Solution 01/2:
    /*int num;
    cout << "Please enter an number (only \"Integers\" are allowed): ";
    cin >> num;
    cout << endl;
    if (cin.fail() || num<4)  cout << "Yeah, I will";
    else if (num==0) cout << "Hello World";
    else if (num==1) cout << "I am groot";
    else if (num==2) cout << "To the Top";
    else if (num==3) cout << "Where is the horizon";
    else cout << "I don't know";*/

    //Solution 02:
    /*int num;
    cout << endl << "Please enter an number (only \"Integers\" are allowed): ";
    cin >> num;
    cout << endl;
    if (cin.fail()) {
        cout << "Yeah, I will";
    } else {
        switch (num) {
            case 0:
                cout << "Hello World";
                break;
            case 1:
                cout << "I am groot";
                break;
            case 2:
                cout << "To the Top";
                break;
            case 3:
                cout << "Where is the horizon";
                break;
            case 4:
                cout << "I don't know";
            default:
                cout << "Yeah, I will";
        }
    }*/

    //Solution 03:
    /*float num1;
    float num2;
    cout << endl;
    while (true) {
        cout << "Please enter the 1st number (only \"Numbers\" are allowed): ";
        cin >> num1;
        if (cin.fail()) _flush_inputs();
        else break;
    }
    cout << endl;
    while (true) {
        cout << "Please enter the 2nd number (only \"Numbers except 0\" are allowed): ";
        cin >> num2;
        if (cin.fail() || num2==0) _flush_inputs();
        else break;
    }
    cout << endl << "The first number (" << num1 << ") divided by the second number (" << num2 << ") is equal to: " << num1 / num2 << "." << endl;*/


    //Solution 04:
    int num;
    cout << endl << "Please enter an number (only \"Integers\" are allowed): ";
    cin >> num;
    cout << ((cin.fail() || num>4) ? "Yeah I will" : (num==0 ? "Hello World" :
            (num==1 ? "I am groot" : (num==2 ? "To the top" :
            (num==3 ? "Where is the horizon" : "I don't know")))));

    _flush_inputs();
    cout << endl << endl;
    _pause();

    return 0;
}
