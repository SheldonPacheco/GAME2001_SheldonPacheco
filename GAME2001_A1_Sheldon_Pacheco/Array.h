#pragma once
#include <cassert>
template <class T>
class UnorderedArray;

template <class T>
class OrderedArray;

template <class T>
class Array {
    friend class UnorderedArray<T>; 
    friend class OrderedArray<T>; 
public:
    Array(int size, int growBy = 1) :
        m_array(nullptr), m_maxSize(size), m_growSize(growBy), m_numElements(0)
    {
        if (size) {
            m_array = new T[m_maxSize];
            memset(m_array, 0, sizeof(T) * m_maxSize);
        }
    }

    ~Array() {
        if (m_array != nullptr) {
            delete[] m_array;
            m_array = nullptr;
        }
    }

    void push(T val) {
        assert(m_array != nullptr);
        if (m_numElements >= m_maxSize) {
            Expand();
        }
        m_array[m_numElements++] = val;
    }

    void pop() {
        if (m_numElements > 0) {
            m_numElements--;
        }
    }

    void remove(int index) {
        assert(m_array != nullptr);

        if (index >= m_numElements) {
            return;
        }

        for (int i = index; i < m_numElements - 1; ++i) {
            m_array[i] = m_array[i + 1];
        }

        m_numElements--;
    }

    T& operator[](int index) {
        assert(m_array != nullptr && index < m_numElements);
        return m_array[index];
    }

    void clear() {
        m_numElements = 0;
    }

    int getSize() const {
        return m_numElements;
    }

    int getMaxSize() const {
        return m_maxSize;
    }

    void setGrowSize(int val) {
        assert(val >= 0);
        m_growSize = val;
    }

private:
    bool Expand() {
        if (m_growSize <= 0) {
            return false;
        }

        int newSize = m_maxSize * 2; 
        T* temp = new T[newSize];
        assert(temp != nullptr);

        memcpy(temp, m_array, sizeof(T) * m_maxSize);

        delete[] m_array;
        m_array = temp;
        m_maxSize = newSize;
        std::cout << "New array size " << m_maxSize << std::endl;
        return true;
    }

private:
    T* m_array;
    int m_maxSize;
    int m_growSize;
    int m_numElements;
    std::string m_name;
};
