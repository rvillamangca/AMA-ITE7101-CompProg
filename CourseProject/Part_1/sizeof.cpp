#include <iostream>
#include <cmath>
using namespace std;

int main(){
	
	cout << "Size of Float Type: " << sizeof(float) << endl;
	cout << "Size of Char Type: " << sizeof(char) << endl;
	cout << "Size of Bool Type: " << sizeof(bool) << endl;
	
	char text[] = "Hellox OEDX!!!";
	cout << endl << "Size of \"text\": " << sizeof(text) << endl;
	
	auto x = 55.55;
	cout << "Type of \"x\": " << typeid(x).name();
	cout << endl << "Size of \"x\": " << sizeof(x) << endl;
	cout << "Size of Double Type: " << sizeof(double) << endl;
	
	auto szs = sizeof(int);
	cout << endl << "Size of Int Type: " << szs << endl;
	cout << "Range of Int Type is: " << -int(pow(2,szs*8-1))
	     << " to " << int(pow(2,szs*8-1))-1;
	
	return 0;
}
