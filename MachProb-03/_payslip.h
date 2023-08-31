/* ************************************************************************************
 * @author: Ramon Villamangca
 * @app name: Pay Slip Class Header
 * @app desc: Completion of a laboratory exercise for ITE-7101 (Computer Programming)
 *
 * @history:
 *  - 2023/08/31 - 09:21 | Draft 1
 *  - 2023/08/31 - 11:56 | Final
 * ************************************************************************************/

#pragma once    // instead of “#ifndef – #define – #endif” combination

#include <iostream>
#include <string>
#include "_helpers.h"

class PaySlip
{
private:
    // constants
    static const double DED_VAL;                                // SSS, pagibig & philhealth deduction value
    const double TAX_RATES[5] = {0.10, 0.15, 0.20, 0.25, 0.30}; // tax rates

    // fields
    std::string name;   // employee name
    char payGrd;        // pay grade
    double basSal;      // basic salary
    double otHrs;       // overtime hours
    double otPay;       // overtime pay
    double grPay;       // gross pay
    double ntPay;       // net pay
    double rtTax;       // tax rate
    double whTax;       // witholding tax
    double netPay;      // net pay

    // methods
    void determinePayGradeAndTaxRate(void);
    void computePay(void);

public:
    // constants
    static const double MIN_SAL;        // minimum salary
    static const double MIN_OT_HRS;     // minimum overtime hours

    // constructor
    PaySlip(void);                          // default constructor
    PaySlip(std::string, double, double);   // complete constructor

    // setters
    void setName(std::string);
    void setBasSal(double);
    void setOtHrs(double);

    // getters
    std::string getName(void);
    char getPayGrd(void);
    double getBasSal(void);
    double getOtHrs(void);
    double getOtPay(void);
    double getGrPay(void);
    double getWhTax(void);
    double getNetPay(void);

    // overloaded assignment operator
    void operator=(const PaySlip&);
};

const double PaySlip::DED_VAL = 500 + 200 + 100;
const double PaySlip::MIN_SAL = 10000.00;
const double PaySlip::MIN_OT_HRS = 1.00;

PaySlip::PaySlip() : PaySlip("No Name",PaySlip::MIN_SAL,PaySlip::MIN_OT_HRS) { }
PaySlip::PaySlip(std::string name, double basSal, double otHrs) {
    this->setName(name);
    this->setBasSal(basSal);
    this->setOtHrs(otHrs);
    this->determinePayGradeAndTaxRate();
    this->computePay();
}
// PaySlip::PaySlip(PaySlip &p) {
//     this->setName(p.getName());
//     this->setBasSal(p.getBasSal());
//     this->setOtHrs(p.getOtHrs());
//     this->determinePayGradeAndTaxRate();
//     this->computePay();
// }

void PaySlip::setName(std::string name) { this->name = name; }

void PaySlip::setBasSal(double basSal) { 
    this->basSal = basSal < PaySlip::MIN_SAL ? PaySlip::MIN_SAL : basSal;
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

void PaySlip::setOtHrs(double otHrs) { 
    this->otHrs = otHrs < PaySlip::MIN_OT_HRS ? PaySlip::MIN_OT_HRS : otHrs; 
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

std::string PaySlip::getName() { return this->name; }
char PaySlip::getPayGrd() { return this->payGrd; }
double PaySlip::getBasSal() { return this->basSal; }
double PaySlip::getOtHrs() { return this->otHrs; }
double PaySlip::getOtPay(){ return this->otPay; }
double PaySlip::getGrPay() { return this->grPay;}
double PaySlip::getWhTax() { return this->whTax; }
double PaySlip::getNetPay() { return this->netPay; }

void PaySlip::determinePayGradeAndTaxRate() {
    int i;
    i = int(basSal) / 1000 % 10;
    this->payGrd = basSal > 55000 ? 'B' : (i < 5 ? 'A' : 'B');
    i = int(basSal) / 10000;
    this->rtTax = TAX_RATES[i > 5 ? 4 : (i-1)];
}

void PaySlip::computePay() {
    this->otPay = this->otHrs * 0.01 * this->basSal;
    this->grPay = this->basSal + this->otPay;
    this->whTax = this->grPay * this->rtTax;
    this->netPay = this->grPay - this->whTax - PaySlip::DED_VAL;
}

void PaySlip::operator=(const PaySlip& p) {
    this->name = p.name;
    this->basSal = p.basSal;
    this->otHrs = p.otHrs;
}

// PaySlip operator=(PaySlip p1, PaySlip p2) {
//     p1.setName(p2.getName());
//     p1.setBasSal(p2.getBasSal());
//     p1.setOtHrs(p2.getOtHrs());
//     return p1;
// }

std::ostream &operator<<(std::ostream &o, PaySlip &p){
    o  << "-----------------------------------------------\n"
       << "                Employee Pay Slip\n" 
       << "-----------------------------------------------\n"
       << "  Employee Name\t\t:\t" << p.getName() << "\n"
       << "  Basic Salary\t\t:\t" << _dbl2str(p.getBasSal()) << "\n"
       << "  Pay Grade\t\t:\t" << p.getPayGrd() << "\n"
       << "  No. of OT Hours\t:\t" << _dbl2str(p.getOtHrs()) << "\n"
       << "  OT Pay\t\t:\t" << "Php " << _dbl2str(p.getOtPay()) << "\n"
       << "  Gross Pay\t\t:\t" << "Php " << _dbl2str(p.getGrPay()) << "\n"
       << "  Withholding Tax\t:\t" << "Php " << _dbl2str(p.getWhTax()) << "\n"
       << "  Net Pay\t\t:\t" << "Php " << _dbl2str(p.getNetPay()) << "\n"
       << "------------------------------------------------\n";
    return o;
}
