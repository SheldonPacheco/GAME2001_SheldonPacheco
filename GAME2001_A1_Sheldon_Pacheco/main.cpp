#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;
int main() {
    OrderedArray<int> orderedArray(5, true);


    orderedArray.push(10);
    orderedArray.push(5);
    orderedArray.push(15);
    orderedArray.push(10); 

    cout << "Ordered array: ";
    for (int i = 0; i < orderedArray.getSize(); ++i) {
        cout << orderedArray[i] << " ";
    }
    cout << endl;

    UnorderedArray<int> unorderedArray(5);
 
    unorderedArray.push(20);
    unorderedArray.push(25);
    unorderedArray.push(20); 
    unorderedArray.push(30);

    cout << "Unordered array: ";
    for (int i = 0; i < unorderedArray.getSize(); ++i) {
        cout << unorderedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
