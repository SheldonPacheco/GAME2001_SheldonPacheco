#pragma once
#include "Array.h"
#include <cassert>

template <class T>
class UnorderedArray : public Array<T> {
public:
    UnorderedArray(int size, int growBy = 1) : Array<T>(size, growBy) {}

    int search(T val) {
        assert(this->m_array != nullptr);

        for (int i = 0; i < this->m_numElements; ++i) {
            if (this->m_array[i] == val) {
                return i;
            }
        }

        return -1;
    }
};
