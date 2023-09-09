#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    array<int,10> arr {34,-5,6,78,2,89,-25,3,1,-100};
    
    sort(arr.begin(),arr.end());
    for (auto i : arr) cout << i << " ";
    
    auto desc = [](int cur, int nex) { return (cur>nex); }; 
    sort(arr.begin(),arr.end(),desc);
    cout << endl;
    for (auto i : arr) cout << i << " ";
    
    return 0;
}