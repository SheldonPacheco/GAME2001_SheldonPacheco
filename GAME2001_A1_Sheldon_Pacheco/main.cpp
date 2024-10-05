#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;
int main() {
    OrderedArray<int> orderedArray(3, true);


    orderedArray.push(5);
    orderedArray.push(1);
    orderedArray.push(15);
    orderedArray.push(15); 

    cout << "Ordered array: ";
    for (int i = 0; i < orderedArray.getSize(); ++i) {
        cout << orderedArray[i] << " ";
    }
    cout << endl;

    UnorderedArray<int> unorderedArray(3);
 
    unorderedArray.push(5);
    unorderedArray.push(10);
    unorderedArray.push(10); 
    unorderedArray.push(50);
    unorderedArray.push(50);
    unorderedArray.push(50);
    unorderedArray.push(50);
    unorderedArray.push(50);
    unorderedArray.push(50);
    cout << "Unordered array: ";
    for (int i = 0; i < unorderedArray.getSize(); ++i) {
        cout << unorderedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
