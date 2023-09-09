#include <iostream>
using namespace std;

void greeting1(int);
void greeting2(string);

int main() {
    greeting1(2);
    greeting2("There");
    return 0;
}

void greeting1(int n) {
    for (auto i=0;i<n;i++) {
        cout << "Hello OED!" << endl;
    }
    cout << endl;
}

void greeting2(string s) {
    cout << "Hello " << s << "!";
}