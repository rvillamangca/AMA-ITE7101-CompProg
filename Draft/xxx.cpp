/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise #009
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/30 - 09:50 | Draft
 *  - 2023/09/01 - 00:43 | Final
 * ************************************************************************************/

#include <iostream>             // to basic input/output

using namespace std;

int main() {
    
    //cout << sizeof(float);

    //char c[4] = {'i','t','!','\0'};
    //int *p = (int*) &c;

    //cout << *p << endl;

    //printf("%s",(uint8_t*) p);

    //__int128 n = 26122967082424701461208506624;
    //__int128 n = *(__int128*) "\x00\x21\x54\x69\x20\x73\x69\x20\x73\x69\x68\x54";
    //printf("%s\n", (uint8_t*) n);

    int i { 654321 };
    while (i > 27946) --i;
    cout << endl << "The value of the variable is: " << i << endl << endl;

    union vars { float first; int second; };
    vars v; v.second = 123;
    cout << "The value of the 1st variable is: " << v.first << " -> gibberish since uninitiated "<< endl; 
    cout << "The value of the 2nd variable is: " << v.second << endl;
    cout << "The address of the 1st variable is: " << &(v.first) << endl;
    cout << "The address of the 2nd variable is: " << &(v.second) << endl << endl;


    int n[3] = { 1936287828, 544434464, 2192489 };
    printf("%s\n\n",(uint8_t*) &n);
    //fputs((uint8_t*) &n,stdout);Week-12

    //[54] [68] [69] [73] | [20] [69] [73] [20] | [69] [74] [21] [00];

    //int n[4] = { 6907988, 6889587, 6889587, 2105716 };
    //for (int i = 0; i < 4; i++) printf("%s",(uint8_t*) &n[i]);
    //printf("\n");

    return 0;
}