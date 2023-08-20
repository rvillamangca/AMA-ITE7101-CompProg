/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Enrollment Slip Program
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *            Laboratory Exercise 006
 * @history:
 *  - 2023/08/20 - 08:28 | Draft #1
 * ************************************************************************************/

#include <iostream>         // to basic input/output
#include <unistd.h>         // to have access to the sleep() function

#ifndef _WIN32              // to enable cross-platform support
    #define _WIN32 0
#endif

using namespace std;

// helper functions declaration
void _clrscr(void);         // to clear the terminal screen
void _flush_inputs(void);   // to flush out all "cin" inputs


int main() {
    int i, c, j = 0;
    string s;

    cout << endl << string(48,'-') << endl;
    cout << " Triangle Printing Program" << endl;
    cout << string(48,'-') << endl;
    cout << " 1. Right Triangle with height at left corner." << endl;
    cout << " 2. Right Triangle with height at right corner." << endl;
    cout << " 3. Inverted Equilateral Triangle." << endl;
    cout << string(48,'-') << endl;
    cout << endl << "Which kind of Triangle do you want to see? ";
    cin >> c;
    cout << "What is the Triangle Height? ";
    cin >> i;
    s = string(2*i, '*');
    for (int k = 0; k < 2*i; k+=2) s[k] = ' ';
    sleep(1);

    switch (c) {

        case (1):
            cout << endl << endl << "Right Triangle with height at left corner (using 'while-loop'):" << endl;
            while (j < i) cout << string(++j,'*') << endl;
            cout << endl << endl << "Good bye..." << endl << endl;
            break;

        case (2):
            cout << endl << endl << "Right Triangle with height at right corner (using 'for-loop'):" << endl << endl;
            for (j; j<=i; ++j) cout << string(i-j+1,' ') << string(j,'*') << endl;
            cout << endl << endl << "Good bye..." << endl << endl;
            break;

        case (3):
            cout << endl << endl << "Inverted Equilateral Triangle (using 'do-while-loop'):" << endl << endl;
            do { cout << string(j,' ') << s.substr(0,2*(i-(j++))) << endl; } while(j < i);
            cout << endl << endl << "Good bye..." << endl << endl;
            break;

        default:
            cout << endl << endl << "There is no option like that... Good bye..." << endl << endl;
    }

    sleep(10);
    _clrscr();
    return 0;
}

void _clrscr() {
    if (_WIN32)  {
        system("CLS");
    } else {
        system("clear");
        printf( "\033[2J" );
    }
    cin.clear();
    fflush(stdin);
}

void _flush_inputs() {
    cin.clear();
    fflush(stdin);
}

