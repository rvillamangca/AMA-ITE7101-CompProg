#include <iostream>
#include <array>
using namespace std;

int main() {
    // 2-dimensional Array (10x20)
    array<array<int,10>,15> arr;
    
    for (auto i=0; i<15; i++) {
        for (auto j=0; j<10; j++) arr[i][j] = (i+1) * (j+1);
    }
    
    for (auto a : arr) {
        for (auto i : a) cout << i << "\t";
        cout << endl;
    }
    
    return 0;
}