#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int xs[] { 33, 155, 72, 101, 108, 108, 111, 32, 79, 69, 68, 33, 36, 75, 255 };
	
	auto int2char = [] (int x) { cout << char(x); };	
	// For-Each Loop
	for_each (xs+2,xs+12,int2char);
	
	return 0;
}

	for_each (start pointer, end pointer, function);
	
	