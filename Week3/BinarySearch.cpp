#include <iostream>
#include "OrderedArray.h"
using namespace std;

int main() {
	cout << "Recursive Binary Search Example" << endl;

	OrderedArray<int> array(3);

	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23);
	array.push(32);
	array.push(1);
	array.push(89);
	array.push(30);
	array.push(100);
	array.push(45);

	cout << "Ordered array contents: ";

	for (int i = 0; i < array.GetSize(); i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < array.GetSize(); i++) {
		cout << "Search for " << i << " was found at index: ";
		cout << array.search(i) << endl;
	}


	cout << endl << endl;
}