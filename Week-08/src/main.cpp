/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Laboratory Exercise 007
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *            
 * @history:
 *  - 2023/08/21 - 13:02 | Final
 * ************************************************************************************/

#include <iostream>         // to basic input/output
#include <unistd.h>         // to access the sleep() function
#include "_helpers.h"       // to access the helper functions

using namespace std;

int main() {
    cout << endl << string(48,'-') << endl;
    cout << " Array Printing Program" << endl;
    cout << string(48,'-') << endl;
    cout << " Array 1. Array of 5 Integers." << endl;
    cout << " Array 2. Equilateral Triangle of Alpha Chars." << endl;
    cout << " Array 3. Sorting Array of Integers." << endl;
    cout << string(48,'-') << endl;

    int ans;
    cout << endl << "Which array do you want to display (1/2/3)? ";
    cin >> ans;

    if (ans == 1) {

        // Array 1 - Array of 5 Integers.
        // NOTE: 2 variables are used (arr1, and i).
        auto arr1 = new int[5];
        cout << endl << "Enter 5 integers separated by space: ";
        for (int i = 0; i < 5; i++) cin >> arr1[i];
        cout << endl << "Your array is: [";
        for (int i = 0; i < 5; i++) cout << " " << arr1[i];
        cout << " ]" << endl << endl;

    } else if (ans == 2) {

        // Array 2 - Equilateral Triangle of Alpha Chars.
        // NOTE: 4 variables are used (arr2, n, i and j).
        auto arr2 = new char[10][21];
        memset(arr2,' ',10*21);
        int n;
        cout << endl << "Enter an integer from 1 to 10: ";
        cin >> n;
        for (int i = 0; i <= n; i++) {
            for (int j = n - i;j <= n+i; j += 2) arr2[i][j] = i + 'A';
            arr2[i][n+i+1] = '\0';
        }
        cout << endl << "Behold, your Equilateral Triangle:" << endl;
        for (int i = 0; i < n; i++) cout << arr2[i] << endl;
        cout << endl << endl;

    } else if (ans == 3) {

        // Array 3 - Sorting Array of Integers.
        // NOTE: 3 variables are used (arr3, i and j).
        auto arr3 = new int[6];
        cout << endl << "Enter 6 integers separated by space: ";
        for (int i = 0; i < 6; i++) cin >> arr3[i];
        for (int i = 0; i < 6; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (arr3[i] > arr3[j]) {
                    arr3[i] += arr3[j];
                    arr3[j] = arr3[i] - arr3[j];
                    arr3[i] -= arr3[j];
                }
            }
        }
        cout << endl << "Your sorted array is: [";
        for (int i = 0; i < 6; i++) cout << " " << arr3[i];
        cout << " ]" << endl << endl;

    } else {
        cout << endl << endl << "There is no option like that..." << endl << endl;
    }

    cout << "Thanks for using the program. Goodbye...";

    sleep(8);
    _clrscr();
    return 0;
}
