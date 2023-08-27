/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #009
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/26 - 13:02 | Draft 1
 * ************************************************************************************/

#include <iostream>         // to basic input/output
#include <string>           // to access the STL string class methods
#include <array>            // to access the STL array class methods
#include <cmath>            // to access basic math functions
#include "_helpers.h"       // to access the helper functions


using namespace std;


// programs functions prototype
array<int,3> prob1(array<int,6>);   // solution function for problem #1
string prob2(short);                // solution function for problem #2
int prob3(int);                     // solution function for problem #3

int main() {
    do {
        _clrscr();
        cout << "--- MAIN MENU ---------------------------\n\n";
        cout << "   1. Pair-wise Division of Six Numbers." << endl;
        cout << "   2. Separation of Digits." << endl;
        cout << "   3. Nth Fibonacci Number." << endl;
        cout << "   Q: Exit Program" << endl << endl;
        cout << "-----------------------------------------\n\n";
        cout << "Select the problem number you want to execute or 'Q' to quit: ";
        char ans = (char) getchar();

        if (ans == '1') {
            _clrscr();
            array<int,6> ns;
            cout << "\n-- Pair-wise Division of Six Numbers --\n\n";
            for (int i = 0; i < ns.size(); i++) {
                cout << "Enter integer # " << i+1 << ": ";
                cin >> ns[i];
                cout << endl;
            }
            auto qs = prob1(ns);
            cout << "\nBehold the Mathematics...\n\n";
            cout << "---------------------------\n\n";
            for (int i = 0; i < qs.size(); i++) {
                cout << "   " << ns[i*2] << " / " << ns[i*2+1] << " = " << qs[i] << endl;
            }
            cout << endl << endl;
            _flush_inputs();
            _pause();

        } else if (ans == '2') {
            _clrscr();
            short n;
            cout << "\n-- Separation of Digits --\n\n";
            cout << "Enter a number from 10 to 99: ";
            cin >> n;
            cout << "\n-------------------------------------------------\n";
            cout << "Your number is: " << n << " and separated shall be: '" << prob2(n) << "'.";
            cout << "\n-------------------------------------------------\n\n";
            _flush_inputs();
            _pause();

        } else if (ans == '3') {
            _clrscr();
            short n;
            cout << "\n-- Nth Fibonacci Number --\n\n";
            cout << "Enter a number: ";
            cin >> n;
            cout << "\n---------------------------------------\n";
            cout << " The " << n << (n==1 ? "st" : n==2 ? "nd" : n==3 ? "rd" : "th"); 
            cout << " Fibonacci Number is: " << prob3(n);  
            cout << "\n---------------------------------------\n\n";
            _flush_inputs();
            _pause();
        } else if (ans == 'q' || ans == 'Q') {
            break;
        }    
    } while (true);
    
    _nap();
    _clrscr();
    
    return 0;
}

array<int,3> prob1(array<int,6> xs) {
    array<int,3> ys;
    for (int i = 0; i < ys.size(); i++) ys[i] = xs[i*2] / xs[i*2+1];
    return ys;
}

string prob2(short x) {
    string s;
    for (auto c : to_string(int(x))) {
        s.push_back(c);
        s.push_back(' ');
    }
    s.pop_back();
    return s;
}

int prob3(int x) {
    // Using Binet's Formula
    auto s = sqrt(5.0);
    auto p = (s + 1.0) / 2.0;
    return int(((pow(p,x) - pow(-p,-x))/s));
}
