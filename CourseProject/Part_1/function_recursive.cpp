#include <iostream>
using namespace std;

int greetings (int count) {
    if (count > 1) {
        cout << "Hello OED???" << endl;
        greetings(count-1);
    } else {
        cout << "Hello OED!!!";
        return count;
    }
}

int main() {
    greetings(5);
    return 0;
}