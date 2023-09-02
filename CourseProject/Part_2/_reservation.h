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
    int age             // customer age
    int guestNum        // number of reservation guests
    double days         // number of days to reserve
    double totPay       // total reservation amount
    double downPay      // downpayment to be paid
    double balPay       // balance amount for payment
    int resNo;          // set a reservation number
    

    // methods
    void calcPayments(void);

public:
    // constructor
    Reservation(void);                            // default constructor
    Reservation(std::string, int, int, double);   // complete constructor

    // setters
    void setName(std::string);
    void setAge(int);
    void setOtHrs(double);

    // getters
    std::string getName(void);
    int getAge(void);
    int getGuestNum(void);
    double getDays(void);

    // methods
    static int proc(void); // main class method

    // overloaded operators
    void operator=(const Reservation&);
    friend std::ostream &operator<<(std::ostream&, PaySlip&);
};

const int Reservation::MIN_AGE = 18;
const double Reservation::DP_RATE = 0.40;
const double Reservation::DAILY_RATES[5] = {1000 1800 2700 3600 4500};


void Reservation::operator=(const Reservation& p) {
    this->name = p.name;
    this->basSal = p.basSal;
    this->otHrs = p.otHrs; 
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

std::ostream &operator<<(std::ostream &o, PaySlip &p){
    o  << "-----------------------------------------------------\n"
       << "                   Employee Pay Slip\n" 
       << "-----------------------------------------------------\n"
       << "  Employee Name\t\t:\t" << p.name << "\n"
       << "  Basic Salary\t\t:\t" << "Php " << _dbl2str(p.basSal) << "\n"
       << "  Pay Grade\t\t:\t" << p.payGrd << "\n"
       << "  No. of OT Hours\t:\t" << _dbl2str(p.otHrs) << "\n"
       << "  OT Pay\t\t:\t" << "Php " << _dbl2str(p.otPay) << "\n"
       << "  Gross Pay\t\t:\t" << "Php " << _dbl2str(p.grPay) << "\n"
       << "  Withholding Tax\t:\t" << "Php " << _dbl2str(p.whTax) << "\n"
       << "  Net Pay\t\t:\t" << "Php " << _dbl2str(p.netPay) << "\n"
       << "------------------------------------------------------\n";
    return o;
}
