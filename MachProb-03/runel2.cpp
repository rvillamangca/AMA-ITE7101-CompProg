// -----------------------------------
// C++ Payslip Program by Runnel Cruz
// -----------------------------------

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Payslip {
private:
    string name; // employee name
    char payGrd; // pay grade
    double basSal; // basic salary
    double otHrs; // overtime hours
    double otPay; // overtime pay
    double grPay; // gross pay
    double ntPay; // net pay
    double rtTax; // tax rate
    double whTax; // witholding tax
    double netPay; // net pay
    void determinePayGradeAndTaxRate();
    void computePay();
public:
    Payslip(string, double, double);
    Payslip(string);
    void setName(string);
    void setBasSal(double);
    void setOtHrs(double);
    string getName();
    char getPayGrd();
    double getBasSal();
    double getOtHrs();
    double getOtPay();
    double getGrPay();
    double getWhTax();
    double getNetPay();
};

string dbl2str(double);
Payslip createPayslip();
void printPayslip(Payslip);

const double minSal = 10000.00; // minimum salary
const double minOtHrs = 1.00; // minimum overtime hours
const double dedVal = 800.00; // SSS, pagibig & philhealth deduction value

using namespace std;

int main() {
    
    cout << "--------------------------------------" << endl;
    cout << "  C++ Payslip Program by Runnel Cruz" << endl;
    cout << "--------------------------------------" << endl << endl;
    
    Payslip runelSlip = Payslip("Runnel Cruz",65000.00,100.00);
    printPayslip(runelSlip);
    
    Payslip ramonSlip = Payslip("Ramon Villamangca");
    printPayslip(ramonSlip);
    ramonSlip.setBasSal(5000);                                                   // salary input < 10,000
    cout << "Ramon's New Salary\t\t:\t\t" << dbl2str(ramonSlip.getBasSal()) << endl; // therefore salary output should be 10,000
    ramonSlip.setBasSal(12345.55);                                               // salary input < 10,000
    cout << "Ramon's New Salary\t\t:\t\t" << dbl2str(ramonSlip.getBasSal()) << endl; // therefore salary output should now change
    
    cout << endl << endl << endl << "--- Creating Payslip object at run-time ---" << endl;
    Payslip newPayslip = createPayslip();
    printPayslip(newPayslip);
    
    return 0;
}

string dbl2str(double x) {
    string s = "";
    int xi = int(x);
    string sd = to_string(int(round((x - xi) * 100)));
    do {
        string si = to_string(xi % 1000);
        s = (xi < 1000 ? "" : "," + string(3-si.length(),'0')) + si + s;
        xi /= 1000;
    } while (xi > 0);
    return s + "." + string(2-sd.length(),'0') + sd;
}

Payslip createPayslip() {
    string name = "";
    double basSal;
    double otHrs;
    string s = "";
    
    cout << endl;
    while (name.empty()) {
        cout << "Please enter Employee Name: ";
        getline(cin, name);
    }
    
    cout << "Please enter Basic Salary (minimum: Php 10,000.00): ";
    getline(cin,s);
    basSal = atof(s.c_str());
    
    cout << "Please enter Overtime Hours (minimum: 1 hour): ";
    getline(cin,s);
    otHrs = atof(s.c_str());
    
    Payslip pSlip = Payslip(name,basSal,otHrs);
    return pSlip;
}

void printPayslip(Payslip pslip) {
    cout << endl << "---" << endl;
    cout << "Employee Name\t\t:\t\t" << pslip.getName() << endl;
    cout << "Basic Salary\t\t:\t\t" << dbl2str(pslip.getBasSal()) << endl;
    cout << "Pay Grade\t\t\t:\t\t" << pslip.getPayGrd() << endl;
    cout << "No. of OT Hours\t\t:\t\t" << dbl2str(pslip.getOtHrs()) << endl;
    cout << "OT Pay\t\t\t\t:\t\t" << "Php " << dbl2str(pslip.getOtPay()) << endl;
    cout << "Gross Pay\t\t\t:\t\t" << "Php " << dbl2str(pslip.getGrPay()) << endl;
    cout << "Withholding Tax\t\t:\t\t" << "Php " << dbl2str(pslip.getWhTax()) << endl;
    cout << "Net Pay\t\t\t\t:\t\t" << "Php " << dbl2str(pslip.getNetPay()) << endl << endl << endl;
}

Payslip::Payslip(string name, double basSal, double otHrs) {
    this->name = name;
    this->basSal = basSal < minSal ? minSal : basSal;
    this->otHrs = otHrs < minOtHrs ? minOtHrs : otHrs;
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

Payslip::Payslip(string name) {
    this->name = name;
    this->basSal = minSal;
    this->otHrs = minOtHrs;
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

void Payslip::setName(string name) {
    this->name = name;
}

void Payslip::setBasSal(double basSal) {
    this->basSal = basSal < 10000.00 ? 10000.00 : basSal;
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

void Payslip::setOtHrs(double otHrs) {
    this->otHrs = otHrs < 1.00 ? 1.00 : otHrs;
    this->determinePayGradeAndTaxRate();
    this->computePay();
}

string Payslip::getName() { return this->name; }
char Payslip::getPayGrd() { return this->payGrd; }
double Payslip::getBasSal() { return this->basSal; }
double Payslip::getOtHrs() { return this->otHrs; }
double Payslip::getOtPay(){ return this->otPay; }
double Payslip::getGrPay() { return this->grPay;}
double Payslip::getWhTax() { return this->whTax; }
double Payslip::getNetPay() {return this->netPay; }

void Payslip::determinePayGradeAndTaxRate() { // (this is the longest 'method name' I've seen in my life :D ...
    switch (int(this->basSal)) {
        case 10000 ... 14999:
            this->payGrd = 'A';
            this->rtTax = 0.10;
            break;
        case 15000 ... 19999:
            this->payGrd = 'B';
            this->rtTax = 0.10;
            break;
        case 20000 ... 24999:
            this->payGrd = 'A';
            this->rtTax = 0.15;
            break;
        case 25000 ... 29999:
            this->payGrd = 'B';
            this->rtTax = 0.15;
            break;
        case 30000 ... 34999:
            this->payGrd = 'A';
            this->rtTax = 0.20;
            break;
        case 35000 ... 39999:
            this->payGrd = 'B';
            this->rtTax = 0.20;
            break;
        case 40000 ... 44999:
            this->payGrd = 'A';
            this->rtTax = 0.25;
            break;
        case 45000 ... 49999:
            this->payGrd = 'B';
            this->rtTax = 0.25;
            break;
        case 50000 ... 54999:
            this->payGrd = 'A';
            this->rtTax = 0.30;
            break;
        default:
            this->payGrd = 'B';
            this->rtTax = 0.30;
            break;
    }
}
void Payslip::computePay() {
    this->otPay = this->otHrs * 0.01 * this->basSal;
    this->grPay = this->basSal + this->otPay;
    this->whTax = this->grPay * this->rtTax;
    this->netPay = this->grPay - this->whTax - dedVal;
}