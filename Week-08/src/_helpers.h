/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Helper Functions Program
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *            
 * @history:
 *  - 2023/08/20 - 08:28 | Draft #1
 * ************************************************************************************/

#ifndef _HELPERS_H
#define _HELPERS_H

#ifndef _WIN32
#define _WIN32 0
#endif

#include <iostream>

void _clrscr() {
    if (_WIN32)  {
        system("CLS");
    } else {
        system("clear");
        printf( "\033[2J" );
    }
    std::cin.clear();
    fflush(stdin);
}

void _flush_inputs() {
    std::cin.clear();
    fflush(stdin);
}

#endif //_HELPERS_H
