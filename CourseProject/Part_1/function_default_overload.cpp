#include <iostream>
using namespace std;

void greeting(int n=1) {
    for (auto i=0;i<n;i++) {
        cout << "Hello OED!" << endl;
    }
    cout << endl;
}

void greeting(string s) {
    cout << "Hello " << s << "!";
}

int main() {
    greeting(2);
    greeting();
    greeting("There");
    return 0;
}