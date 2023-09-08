#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int,10> arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // print the 7th element
    cout << arr[6];
    
    // change the 8th element
    arr[7] = 25;
    cout << endl << arr[7];
    arr[7] = arr[0] + 100;
    cout << endl << arr[7];
    
    return 0;
}