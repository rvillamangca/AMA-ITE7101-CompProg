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
    
    //cout << sizeof(int);

    //char c[4] = {'i','t','!','\0'};
    //int *p = (int*) &c;

    //cout << *p << endl;

    //printf("%s",(uint8_t*) p);

    int n[3] = { 1936287828, 544434464, 2192489 };
    printf("%s\n",(uint8_t*) &n);
    //fputs((uint8_t*) &n,stdout);

    //[54] [68] [69] [73] [20] [69] [73] [20] [69] [54] [21] [00];

    //int n[4] = { 6907988, 6889587, 6889587, 2105716 };
    //for (int i = 0; i < 4; i++) printf("%s",(uint8_t*) &n[i]);
    //printf("\n");

    return 0;
}