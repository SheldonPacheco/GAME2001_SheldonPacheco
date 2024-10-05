#include <iostream>
#include <cassert>
using namespace std;

int factorial(int x) {
	assert(x >= 0);

	if (x == 0) {
		return 1;
	}

	return (factorial(x - 1) * x);
}

int doubleFactorial(int x) {
	assert(x >= 0);

	if (x == 0 || x == 1) {
		return 1;
	}
	return (doubleFactorial(x - 2) * x);
}
//int main() {
//	cout << "factorials: " << endl;
//
//	cout << " The factorial of 5: ";
//	cout << factorial(5) << endl;
//
//	cout << "The double factorial of 7: ";
//	cout << doubleFactorial(7) << endl;
//
//	return 0;
//}