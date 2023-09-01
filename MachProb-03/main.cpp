/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Machine Problem 003
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/30 - 09:50 | Draft
 *  - 2023/09/01 - 00:43 | Final
 * ************************************************************************************/

#include <iostream>             // to basic input/output
#include "_helpers.h"           // to access the helper functions
#include "_employee.h"          // to access the Employee class
#include "_payslip.h"           // to access the Pay Slip class

using namespace std;

int main() {
    _clrscr();

    cout << endl << "-------------------------------------" << endl;
    cout << "      Employee Payslip Program" << endl;
    cout << "-------------------------------------" << endl << endl;
    
    _pause();

    return Employee::main();
}