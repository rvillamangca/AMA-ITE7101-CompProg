#include <iostream>

int fixAge(int age) {
    return age / 2;
}

int main() {
    int old = 60;
    std::cout << "Your real age: " << fixAge(old);

    return 0;
}