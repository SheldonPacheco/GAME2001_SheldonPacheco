#pragma once
#include <cassert>
template<class T>
class OrderedArray {
public:
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) {
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0 ? growBy : 0));
		}
	}
	~OrderedArray()
	{
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
		int i, k;
		for (i = 0; i < m_numElements; i++) {
			if (m_array[i] > val) {
				break;
			}
		}

		for (k = m_numElements; k > i; k--) {
			m_array[k] = m_array[k - 1];
		}
		m_array[i] = val;
		m_numElements++;
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
		for (int i = index; i < m_numElements; i++) {
			if (i + 1 < m_numElements) {
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	//int search(T searchKey) {
	//	assert(m_array != nullptr);

	//	int lowerBound = 0; 
	//	int upperBound = m_numElements - 1;
	//	int current = 0; 

	//	while (1) {
	//		current = (lowerBound + upperBound) >> 1;

	//		if (m_array[current] == searchKey) {
	//			return current;
	//		}
	//		else if (lowerBound > upperBound) {
	//			return -1;
	//		}
	//		else {
	//			if (m_array[current] < searchKey) {
	//				lowerBound = current + 1;
	//			}
	//			else {
	//				upperBound = current - 1;
	//			}
	//		}
	//	}
	//}
	int search(T searchKey) {
		return binarySearch(searchKey, 0, m_numElements - 1);
	}
	T& operator[](int index) {
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	void Clear() {
		m_numElements = 0;
	}
	int GetSize() {
		return m_numElements;
	}
	int GetMaxSize() {
		return m_maxSize;
	}
	int GetGrowSize(int val) {
		assert(val >= 0);
		m_growSize = val;
	}
private:
	int binarySearch(T searchKey, int lowerBound, int upperBound) {
		assert(m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		int current = (lowerBound + upperBound) >> 1;

		if (m_array[current] == searchKey) {
			return current;
		}
		else if (lowerBound > upperBound) {
			return -1;
		}
		else {
			if (m_array[current] < searchKey) {
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else {
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}
		return -1;
	}
	bool Expand() {
		if (m_growSize <= 0) {
			return false;
		}

		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		delete[] m_array;

		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;
	}
private:
	T* m_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;
};