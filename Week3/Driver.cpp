#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"
using namespace std;
//
//int main() {
//	UnorderedArray<int> array(3);
//
//	array.push(3);
//	array.push(53);
//	array.push(83);
//	array.push(23);
//	array.push(82);
//
//	array[2] = 112;
//	array.pop();
//	array.remove(2);
//
//	cout << "Ordered array contents: ";
//
//	for (int i = 0; i < array.GetSize(); i++) {
//		cout << array[i] << " ";
//	}
//
//	cout << endl;
//
//	cout << "Search for 53 was found at index: ";
//	cout << array.search(53) << endl;
//	cout << "Search for 23 was found at index: ";
//	cout << array.search(23) << endl;
//
//	OrderedArray<int> array2(3);
//
//	array2.push(3);
//	array2.push(53);
//	array2.push(83);
//	array2.push(23);
//	array2.push(82);
//
//	//array2[2] = 112;
//	array2.pop();
//	array2.remove(2);
//
//	cout << "Ordered array contents: ";
//
//	for (int i = 0; i < array2.GetSize(); i++) {
//		cout << array2[i] << " ";
//	}
//
//	cout << endl;
//
//	cout << "Search for 53 was found at index: ";
//	cout << array2.search(53) << endl;
//	cout << "Search for 23 was found at index: ";
//	cout << array2.search(23) << endl;
//}