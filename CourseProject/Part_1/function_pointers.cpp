#include <iostream>
using namespace std;

void greeting1(int n, string s) {
    for (auto i=0;i<n;i++)
        cout << "Hello " << s << "!" << endl;
    cout << endl;
}

void greeting2(int n, string s) {
    for (auto i=0;i<n;i++)
        cout << "Hello There, " << s << "!" << endl;
    cout << endl;
}

int main() {
    void (*greetOED)(int,string);
    
    greetOED = &greeting1;
    greetOED(3,"OED Student");
    
    greetOED = &greeting2;
    greetOED(3,"OED STUDENT");
    
    return 0;
}