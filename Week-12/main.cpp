/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #011
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/09/01 - 21:25 | Draft
 *  - 2023/09/02 - 07:30 | Final
 * ************************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << endl <<"-- solution #1 --------------" << endl << endl;

        int i = 900;
        cout << "\033[1;31mvalue variable i:\033[1;0m\t" << i << endl;
        cout << "\033[1;31maddress of variable i:\033[1;0m\t" << &i << endl << endl;


    cout << endl <<"-- solution #2 --------------" << endl << endl;

        char c[10];
        auto *p = c;
        cout << "\033[1;31mvalue variable c:\033[1;0m\t" << c << endl;
        cout << "\033[1;31madress of variable c:\033[1;0m\t" << &c << endl;
        cout << "\033[1;31mvalue of pointer p:\033[1;0m\t" << (int *) p << endl;
        cout << "\033[1;31maddress of pointer p:\033[1;0m\t" << &p << endl << endl;

    cout << endl <<"-- solution #3 --------------" << endl << endl;

        float f[20];
        auto &r = f;
        cout << fixed << setprecision(0);
        cout << "\033[1;31mvalue variable f:\033[1;0m\t[ "; for(float e : f) cout << e << " "; cout << "]" << endl;
        cout << "\033[1;31madress of variable f:\033[1;0m\t" << &f << endl;
        cout << "\033[1;31mvalue of reference r:\033[1;0m\t[ "; for(float q : r) cout << q << " "; cout << "]" << endl;
        cout << "\033[1;31maddress of reference r:\033[1;0m\t" << &r << endl << endl;

    return 0;
}
