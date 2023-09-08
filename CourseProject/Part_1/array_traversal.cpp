#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int,10> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // print with imperative for-loop
    for (auto i=0; i<10; i++) cout << " " << arr[i];
    cout << endl;
    
    // print with functional for-loop
    for (auto i : arr) cout << " " << i;
    cout << endl;
    
    // mutate with imperative for-loop
    for (auto i=0; i<10; i++) arr[i]++;
    for (auto i=0; i<10; i++) cout << " " << arr[i];
    
    return 0;
}