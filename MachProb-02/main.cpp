/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Machine Problem No. 002
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/23 - 13:02 | Draft 1
    - 2023/08/24 - 08:40 | Completed
 * ************************************************************************************/

#include <iostream>         // to basic input/output
#include <string>           // to access the STL string class methods
#include <cctype>           // to access the isdigit() function
#include "_helpers.h"       // to access the helper functions

#define ROW 5               // defines the number of rows
#define COL 7            // defines the number of columns

using namespace std;

auto seat = new int[ROW][COL];

// programs functions declaration
void showMenu(void);         // shows the main program menu
void createSeats(void);      // creates a new seating arrangement
void showSeats(void);        // prints the current seating
void bookSeat(void);         // books a seat (needs validation here)
void cancelSeat(void);       // cancels a booked seat

int main() {
    createSeats();

    _clrscr();
    cout << string(BARLENGTH,'-') << endl;
    cout << "          Seat Booking Program" << endl;

    showMenu();

    return 0;
}

void showMenu() {
    string menu = string(BARLENGTH, '-')
                + "\n 1. Display current seating."
                + "\n 2. Book a seat."
                + "\n 3. Cancel a booked seat."
                + "\n 4. Quit the program.\n"
                + string(BARLENGTH, '-') + "\n";
    string retMenu = "Press any key to return to Main Menu...";
    cout << menu;
    do {
        cout << "What do you want to do today (1/2/3/4)? ";
        int ans;
        cin >> ans;
        switch (ans) {
            case 1:
                showSeats();
                _flush_inputs();
                _pause(retMenu);
                _clrscr();
                cout << menu;
                break;
            case 2:
                bookSeat();
                _flush_inputs();
                _pause(retMenu);
                _clrscr();
                cout << menu;
                break;
            case 3:
                cancelSeat();
                _flush_inputs();
                _pause(retMenu);
                _clrscr();
                cout << menu;
                break;
            case 4:
                cout << endl << "Thanks for using the program. Goodbye...";
                _sleep();
                _clrscr();
                return;
        }
    } while (true);
}

void createSeats() {
    for (int n = 0; n < ROW*COL; n++) seat[n/COL][n%COL] = n + 1;
}

void showSeats() {
    _clrscr();
    cout << endl << "This is the current seating arrangement:" << endl;
    cout << string(BARLENGTH+12,'-') << endl;
    for (int n = 0; n < ROW*COL; n++) {
        if (n%COL == 0) cout << "  ";
        cout << seat[n/COL][n%COL] << "\t";
        if (n%COL == COL-1) cout << endl;

    }
    cout << string(BARLENGTH+12,'-') << endl << endl;
}

void bookSeat() {
    showSeats();
    string s; int n;
    string msg = "\nEnter a seat number to reserve, from 1 to 35: ";
    cout << msg;
    do {
        getline(cin,s);
        if (s.empty()) {
            cout << msg;

        } else if (!isdigit(s.at(0))) {
            cout << endl << "ERROR: What you entered is not a number." << msg;
        } else {
            n = stoi(s);
            if (n < 1 || n > ROW*COL) {
                cout << endl << "ERROR: What you entered is out of range." << msg;
            } else {
                int r = (n-1) / COL;
                int c = (n-1) % COL;
                if (seat[r][c] == 0) {
                    cout << endl << "ERROR: Seat is taken." << msg;
                } else {
                    seat[r][c] = 0;
                    cout << endl << "Seat succefully reserved!" << endl;
                    return;
                }
            }
        }

    } while (true);
}

void cancelSeat() {
    showSeats();
    string s; int n;
    string msg = "\nEnter a seat number to cancel, from 1 to 35: ";
    cout << msg;
    do {
        getline(cin,s);
        if (s.empty()) {
            cout << msg;

        } else if (!isdigit(s.at(0))) {
            cout << endl << "ERROR: What you entered is not a number." << msg;
        } else {
            n = stoi(s);
            if (n < 1 || n > ROW*COL) {
                cout << endl << "ERROR: What you entered is out of range." << msg;
            } else {
                int r = (n-1) / COL;
                int c = (n-1) % COL;
                if (seat[r][c] != 0) {
                    cout << endl << "ERROR: Seat is still available." << msg;
                } else {
                    seat[r][c] = n;
                    cout << endl << "Seat succefully cancelled!" << endl;
                    return;
                }
            }
        }

    } while (true);
}