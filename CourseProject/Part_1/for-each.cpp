#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int xs[15] = { 33,155,72,101,108,108,111,32,87,111,114,108,100,33,36 };
	
	auto int2char = [] (int x) { cout << char(x); };	
	
	// For-Each Loop
	for_each (xs+2,xs+13,int2char);
	
	return 0;
}

	for_each (start pointer, end pointer, function);
	
	