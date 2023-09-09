#include <iostream>
using namespace std;

typedef struct Greetings {
    void greeting1() {
        cout << "Hello OED???" << endl;
    }
    void greeting2() {
        cout << "Hello OED!!!" << endl;
    }
} Greetings;

int main() {
    Greetings my;
    my.greeting1();
    my.greeting2();
    return 0;
}