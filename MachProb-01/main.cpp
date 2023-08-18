/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Enrollment Slip Program
 * @app desc: Completion of a laboratory exercise for ITE-17101 (Computer Programming)
 *            Solutions for Machine Problem #1
 * @history:
 *  - 2023/08/16 - 13:55 | Draft #1
 *  - 2023/08/17 - 07:24 | Draft #2
 *  - 2023/08/18 - 07:45 | Final Version
 * ************************************************************************************/

#include <iostream>         // to basic input/output
#include <vector>           // to make a list of year names and tuition rates
#include <string>           // to be able to declare strings
#include <unistd.h>         // to have access to the sleep() function

#ifndef _WIN32              // to enable cross-platform support
    #define _WIN32 0
#endif

using namespace std;

struct student {
    string name;
    string course;
    int level;
    float units;
};

// helper functions declaration
void _clrscr(void);         // to clear the terminal screen
void _flush_inputs(void);   // to flush out all "cin" inputs


//problem functions declaration
struct student getInfo(void);               // to get the the student information
void printSlip(struct student);             // to print the student's payment slip

int main() {
    cout << endl << string(36,'-') << endl;
    cout << " Enrollment Payment Slip Program" << endl;
    cout << string(36,'-') << endl << endl;

    do {
        cout << "Do you want to enroll a new student (Y/N)? ";
        auto ans  = (char) getchar();
        _flush_inputs();
        if (ans=='y' || ans=='Y') {
            _clrscr();
            cout << endl << string(40,'-') << endl;
            cout << " Please enter the Student's Information " << endl;
            cout << string(40,'-') << endl << endl;
            auto s = getInfo(); // enrolls a new student
            cout << endl << string(40,'-') << endl << endl;
            sleep(2);
            printSlip(s);
        } else if (ans=='n' || ans=='N')  {
            cout << endl << endl << "Thank you for using the program. See you next time!" << endl;
            sleep(2);  // delays execution of next line for 2 seconds
            break;
        }
    } while (true);

    _clrscr();
    return 0;
}

void _clrscr() {
    if (_WIN32)  {
        system("CLS");
    } else {
        system("clear");
        //printf( "\033[2J" );
    }
    cin.clear();
    fflush(stdin);
}

void _flush_inputs() {
    cin.clear();
    fflush(stdin);
}

student getInfo() {
    struct student s;
    cout << " Student Name: ";
    getline(cin,s.name);
    _flush_inputs();

    cout << " Program/Course: ";
    getline(cin,s.course);
    _flush_inputs();

    cout << " Year Level: ";
    cin >> s.level;
    _flush_inputs();

    cout << " Number of Units: ";
    cin >> s.units;
    _flush_inputs();

    return s;
}

void printSlip(student s) {
    const vector<float> tuitionRate = {1500,1800,2000,2300};
    const vector<string> yearName = {"Freshman","Sophomore","Junior","Senior"};

    auto i = (s.level > 4 ? 4 : s.level) - 1; // vector index;
    auto t = s.units * tuitionRate[i]; // total tuition fee
    auto bar = string(s.name.length()>s.course.length()?s.name.length()+38:s.course.length()+38,'-'); // decoration


    _clrscr();
    cout << endl << bar << endl;
    cout << " " << s.name << " | ENROLLMENT SLIP" << endl;
    cout << bar << endl << endl;
    cout << "  Student Name\t\t: " << s.name << endl;
    cout << "  Program/Course\t: " << s.course << endl;
    cout << "  Year Name\t\t: " << yearName[i] << endl;
    cout << "  No. of Units\t\t: " << s.units << endl;
    cout << "  Tuition Fee\t\t: " << t << endl;
    cout << "  Down Payment\t\t: " << 0.3 * t << endl;
    cout << "  Balance\t\t: " << 0.7 * t << endl;
    cout << endl << bar << endl << endl;
}

