/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Helper Function Programs
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/20 - 08:28 | Completed
 * ************************************************************************************/

#ifndef _WIN32
#define _WIN32 0
#endif

#ifndef _HELPERS_H
#define _HELPERS_H

#define BARLENGTH 40
#define _nap() sleep(2)
#define _sleep() sleep(5)

#include <iostream>
#include <string>
#include <algorithm>
#include <unistd.h>

void _pause() {
    std::cout << "Press any key to continue...";
    std::cin.get();
}
void _pause(std::string s) {
    std::cout << s;
    std::cin.get();
}

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

std::string _to_lower(std::string s) {
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    return s;
}

#endif //_HELPERS_H
