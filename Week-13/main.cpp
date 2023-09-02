/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #012
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/09/02 - 12:25 | Draft
 *  - 2023/09/02 - 14:03 | Final
 * ************************************************************************************/

#include <iostream>

using namespace std;

int main() {
    cout << endl <<" -- solution #1 --------------" << endl << endl;

        int i { 654321 };
        while (i > 27946) --i;
        cout << " The value of the variable is: " << i << endl << endl;


    cout << endl <<" -- solution #2 --------------" << endl << endl;

        union vars { float first; int second; };
        vars v; v.second = 123;
        cout << " The value of the 1st variable is: " << v.first << " -> gibberish since uninitiated "<< endl; 
        cout << " The value of the 2nd variable is: " << v.second << endl;
        cout << " The address of the 1st variable is: " << &(v.first) << endl;
        cout << " The address of the 2nd variable is: " << &(v.second) << endl << endl;

    
    cout << endl <<" -- solution #3 --------------" << endl << endl;

        int n[3] = { 1936287828, 544434464, 2192489 };
        printf(" %s\n\n",(uint8_t*) &n);

    return 0;
}
