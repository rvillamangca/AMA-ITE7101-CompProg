/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Course Project
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/30 - 09:50 | Draft
 *  - 2023/09/01 - 00:43 | Final
 * ************************************************************************************/

#include <iostream>             // to basic input/output
#include "_helpers.h"           // to access the helper functions
#include "_reservation.h"       // to access the Hotel Reservation class

using namespace std;

//int main() { return Reservation::process(); }

void createReservation(vector<Reservation*> &);
void cancelReservation(vector<Reservation*> &, int);
void extendReservation(vector<Reservation*> &, int);
void printReservation(vector<Reservation*> &, int);

int main() {
	std::vector<Reservation*> resVec;
    int resNum = 0;

    auto isResNum = [&](std::string s) {
        if (s.substr(0,5) != "2023-") return false;
        if (s[5]<'1' || s[5]>'9') return false;
        resNum = std::stoi(s.substr(5,s.length()-5));
        if (isResNum > resVec.size()) return false;
        if (resVec[rn-1]==nullptr) return false;
        return true;
    };

    void(*menu[4])(vector<Reservation*> &) = {createReservation, cancelReservation, extendReservation, printReservation};

    do {
    	_clrscr();
        std::cout << "\n" << "---" << "\033[1;32m" << " Hotel Reservation Program "; 
        std::cout << "\033[1;0m" << "-----------------------\n\n";
        std::cout << "   1. Create New Reservation" << "\n";
        std::cout << "   2. Cancel an Existing Reservation" << "\n";
        std::cout << "   3. Extend an Existing Reservation" << "\n";
        std::cout << "   4. Print an Existing Reservation" << "\n";
        std::cout << "   Q: Exit Program" << "\n" << "\n";
        std::cout << "------------------------------------------------------\n\n";
        std::cout << "Select the number of the action you want to do or 'Q' to quit: ";
        char ans = (char) getchar();
        _flush_inputs();


    } while (true);

}