#include <iostream>
#include <cassert>
using namespace std;

int TriNumLoop(int term) {
	assert(term >= 1);

	int value = 0; 

	for (; term > 0; term--) {
		value += term;

	}
	return value;
}
int TriNumRecursion(int term) {
	assert(term >= 1);

	if (term == 1) {
		return 1;
	}

	return(TriNumRecursion(term - 1) + term);
}
//int main() {
//	cout << "Triangle number example! " << endl;
//
//	cout << "The value of the 18th term using a loop is: ";
//	cout << TriNumLoop(18) << endl;
//
//	cout << "The value of the 18th term using recursion is: ";
//	cout << TriNumRecursion(18) << endl;
//
//	return 0;
//}