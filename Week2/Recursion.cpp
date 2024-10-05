#include <iostream>
using namespace std;

void PrintNumReverse(int x) {
	if (x <= 0) {
		return;
	}
	cout << " " << x;

	PrintNumReverse(x - 1);
}
//int main() {
//	cout << "Recursion Example " << endl;
//	cout << "Here is a recursive call: " << endl;
//
//	PrintNumReverse(5);
//
//	return 0; 
//}