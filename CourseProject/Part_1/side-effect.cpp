#include <iostream>

using namespace std;

int main(){
	auto x = 10;
	auto *p = &x;
	cout << "x = " << x << endl;
	cout << "*p = " << *p << endl;
	while (x > 5) {
		if (x == 10) p = nullptr;
		x--;
	}
	cout << endl;
	cout << "x = " << x << endl;
	cout << "*p = " << *p << endl;
	
	cout << "happy ending";
	return 0;
}