/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Customer Reservation Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/09/02 - 08:55 | Draft
 *  - 2023/09/0X -    XX | Final
 * ************************************************************************************/

#pragma once    // instead of “#ifndef – #define – #endif” combination

#include <iostream>
#include <string>
#include <vector>
#include "_helpers.h"

class Reservation
{
private:
    // constants
    static const int MIN_AGE;           // minimum age of customer
    static const double DP_RATE;        // percent rate of downpayment
    static const double DAILY_RATES[];  // reservation rates per day

    // fields
    std::string name;   // customer name
    int age;            // customer age
    int guestNo;        // number of reservation guests
    double days;        // number of days to reserve
    double totPay;      // total reservation amount
    double downPay;     // downpayment to be paid
    double balPay;      // balance amount for payment
    short resNo;        // reservation number
    

    // methods
    void calcPayments(void);

public:
    // constructor
    Reservation(void);                                  // default constructor
    Reservation(std::string, int, int, double, short);   // complete constructor

    // setters
    void setName(std::string);
    void setAge(int);
    void setGuesNo(int);
    void setDays(double);
    void setResNo(short);

    // getters
    std::string getName(void);
    int getAge(void);
    int getGuestNo(void);
    double getDays(void);
    short getResNo(void);

    // methods
    static int process(void); // main class method

    // overloaded operators
    friend std::ostream &operator<<(std::ostream&, Reservation&);
};

const int Reservation::MIN_AGE = 18;
const double Reservation::DP_RATE = 0.40;
const double Reservation::DAILY_RATES[5] = {1000, 1800, 2700, 3600, 4500};

Reservation::Reservation() : Reservation("",0,0,0,0) { }
Reservation::Reservation(std::string name, int age, int guestNo, double days, short resNo) {
    this->setName(name);
    this->setAge(age);
    this->setGuesNo(guestNo);
    this->setDays(days);
    this->setResNo(resNo);
    this->calcPayments();
}

void Reservation::setName(std::string name) { this->name = name; }
void Reservation::setAge(int age) { this->age = age; }
void Reservation::setGuesNo(int guestNo) {
    this->guestNo = guestNo;
    this->calcPayments();
}
void Reservation::setDays(double days) {
    this->days= days;
    this->calcPayments();
}
void Reservation::setResNo(short resNo) { this->resNo = resNo; }

std::string Reservation::getName() { return this->name; }
int Reservation::getAge() { return this->age; }
int Reservation::getGuestNo() { return this->guestNo; }
double Reservation::getDays() { return this->days; }
short Reservation::getResNo() { return this->resNo; }

void Reservation::calcPayments() {
    int i = days > 5 ? 4 : (days-1);
    this->totPay = (this->days) * Reservation::DAILY_RATES[i];
    this->downPay = (this->totPay) * Reservation::DP_RATE;
    this->balPay = (this->totPay) - (this->downPay);
}

int Reservation::process() {
    std::vector<Reservation> vr;
    int rn;
    auto isResNum = [&rn,vr](std::string s) {
        if (s.substr(0,5) != "2023-") return false;
        if (s[5]<'1' || s[5]>'9') return false;
        int rn = std::stoi(s.substr(5,s.length()-5));
        std::cout << "vr=" << vr.size();
        if (rn > vr.size()) return false;
        if (vr[rn-1].name == "") return false;
        return true;
    };

    do {
        _clrscr();
        std::cout << "\n" << "---" << "\033[1;32m" << " Hotel Reservation Program "; 
        std::cout << "\033[1;0m" << "-----------------------\n\n";
        std::cout << "   1. Create New Reservation" << "\n";
        std::cout << "   2. Cancel an Existing Reservation" << "\n";
        std::cout << "   3. Show an Existing Reservation" << "\n";
        std::cout << "   Q: Exit Program" << "\n" << "\n";
        std::cout << "------------------------------------------------------\n\n";
        std::cout << "Select the number of the action you want to do or 'Q' to quit: ";
        char ans = (char) getchar();


        if (ans == '1') {
            _clrscr();
            std::string name; int age; int guestNo; double days;

            std::cout << "Please Enter Your Name: ";
            std::getline(std::cin,name);
            _flush_inputs();
            std::cout << "\n";

            std::cout << "Please Enter Your Age: ";
            std::cin >> age;
            _flush_inputs();
            if (age < Reservation::MIN_AGE) {
                std::cout << "You are too young to do reservation. Goodbye...\n";
                _nap();
                continue;
            }
            std::cout << "\n";

            std::cout << "Please Enter the Number of Guest/s: ";
            std::cin >> guestNo;
            _flush_inputs();

            std::cout << "Please Enter the Number of Day/s to reserve: ";
            std::cin >> days;
            _flush_inputs();

            vr.push_back(Reservation(name,age,guestNo,days,vr.size()+1));

            std::cout << "Your reservation has been registered successfully...\n"
                      << "Please take note of your reservation number: " << "\033[1;4m" << "2023-" << vr.size() << "\033[1;0m" << "\n";

            std::cout << (vr[0].name=="") << "\n";

            _flush_inputs();
            _pause("Press any key to return to the Menu...");

        } else if (ans == '2') {
            _clrscr();
            std::string s;
            //Reservation p = nullptr;
            std::cout << "Please enter your Reservation Number (format is \"2023-X\"): ";
            std::getline(std::cin,s);
            _flush_inputs();
            std::cout << "\n";
            if (!isResNum(s)) {
                //std::cout << s.substr(5,s.length()-5) << "   ";
                std::cout << "That's and invalid Reservation Number. Goodbye...\n";
                _nap();
                continue;
            }
            vr[rn-1].name = "";
            std::cout << "Reservation no. " << s << " is succefully cancelled.\n";
            _flush_inputs();            
        } else if (ans == '3') {
            _flush_inputs();
            _pause("Press any key to return to the Menu... ");
            
        } else if (ans == 'q' || ans == 'Q') {
            break;
        } 
    } while(true);

    _sleep();
    _clrscr();

    return 0;
}

std::ostream &operator<<(std::ostream &o, Reservation &r){
    o  << "-------------------------------------------------\n"
       << "\033[1;31m" << "              Hotel Reservation Slip" << "\033[1;0m" << "\n" 
       << "-------------------------------------------------\n"
       << "  Reservation No.\t:\t" << "\033[1;4m" << "2023-" << r.resNo << "\033[1;0m" << "\n"
       << "  Customer Name\t\t:\t" << r.name << "\n"
       << "  Customer Age\t\t:\t" << r.age << "\n"
       << "  Number of Guests\t:\t" << r.guestNo << "\n"
       << "  Number of Days\t:\t" << _dbl2str(r.days) << "\n"
       << "-------------------------------------------------\n"
       << "  Total Payment\t\t:\t" << "Php " << _dbl2str(r.totPay) << "\n"
       << "  Downpayment\t\t:\t" << "Php " << _dbl2str(r.downPay) << "\n"
       << "-------------------------------------------------\n"
       << "  Balance Payment\t:\t" << "Php " << _dbl2str(r.balPay) << "\n"
       << "-------------------------------------------------\n";
    return o;
}
