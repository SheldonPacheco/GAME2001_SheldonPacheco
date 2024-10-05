#pragma once
#include "Array.h"
#include <cassert>

template <class T>
class OrderedArray : public Array<T> {
public:
    OrderedArray(int size, bool duplicateCheck = false, int growBy = 1) :
        Array<T>(size, growBy), m_duplicateCheck(duplicateCheck) {}

    void push(T val) {
        assert(this->m_array != nullptr);

        if (this->m_numElements >= this->m_maxSize) {
            this->Expand();
        }

        if (m_duplicateCheck && search(val) != -1) {
            return; 
        }

        int i, k;
        for (i = 0; i < this->m_numElements; ++i) {
            if (this->m_array[i] > val) {
                break;
            }
        }

        for (k = this->m_numElements; k > i; --k) {
            this->m_array[k] = this->m_array[k - 1];
        }

        this->m_array[i] = val;
        this->m_numElements++;
    }

    int search(T searchKey) const {
        return binarySearch(searchKey, 0, this->m_numElements - 1);
    }

private:
    int binarySearch(T searchKey, int lowerBound, int upperBound) const {
        assert(this->m_array != nullptr);

        if (lowerBound > upperBound) {
            return -1;
        }

        int current = (lowerBound + upperBound) / 2;

        if (this->m_array[current] == searchKey) {
            return current;
        }
        else if (this->m_array[current] < searchKey) {
            return binarySearch(searchKey, current + 1, upperBound);
        }
        else {
            return binarySearch(searchKey, lowerBound, current - 1);
        }
    }

    bool m_duplicateCheck;
};
