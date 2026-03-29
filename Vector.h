#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

/**
 * @class Vector
 * @brief A dynamic array implementation.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * Manages its own heap memory and provides bounds-checked access.
 * Heavily utilized throughout the application to store pointers and standard types.
 */
template <class T>
class Vector {
public:
    /** @brief Default constructor. Initializes with capacity of 10. */
    Vector();

    /** * @brief Parameterized constructor.
     * @param initialCapacity The starting capacity of the vector.
     * @details FIXED: Added to support declarations like Vector<float> speeds(100);
     */
    Vector(int initialCapacity);

    /** @brief Destructor. Frees heap memory. */
    ~Vector();

    /** @brief Copy constructor for deep copies. */
    Vector(const Vector<T>& other);

    /** @brief Assignment operator for deep copies. */
    Vector<T>& operator=(const Vector<T>& other);

    bool insert(int index, const T& item);
    bool remove(int index);
    bool contains(const T& item) const;
    void push_back(const T& item);

    int size() const;
    int capacity() const;
    bool empty() const;
    void clear();

    T& operator[](int index);
    const T& operator[](int index) const;

private:
    T* data;         ///< Pointer to the heap-allocated array.
    int currentSize; ///< Number of elements currently in the Vector.
    int m_capacity;  ///< Maximum elements before a resize is required.

    void expandCapacity();
};

// --- IMPLEMENTATION ---

// FIXED: CRITICAL MEMORY BUG FIX. Changed "new T" to "new T"
template <class T>
Vector<T>::Vector() : data(new T), currentSize(0), m_capacity(10) {}

// FIXED: Implementation of the new constructor
template <class T>
Vector<T>::Vector(int initialCapacity) : data(new T[initialCapacity]), currentSize(0), m_capacity(initialCapacity) {}

template <class T>
Vector<T>::~Vector() {
    delete[] data;
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) : data(new T[other.m_capacity]), currentSize(other.currentSize), m_capacity(other.m_capacity) {
    for (int i = 0; i < currentSize; ++i) {
        data[i] = other.data[i];
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if (this != &other) {
        delete[] data;
        currentSize = other.currentSize;
        m_capacity = other.m_capacity;
        data = new T[m_capacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <class T>
void Vector<T>::expandCapacity() {
    m_capacity *= 2;
    T* newData = new T[m_capacity];
    for (int i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template <class T>
bool Vector<T>::insert(int index, const T& item) {
    if (index < 0 || index > currentSize) return false;
    if (currentSize == m_capacity) expandCapacity();

    for (int i = currentSize; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = item;
    currentSize++;
    return true;
}

template <class T>
bool Vector<T>::remove(int index) {
    if (index < 0 || index >= currentSize) return false;

    for (int i = index; i < currentSize - 1; ++i) {
        data[i] = data[i + 1];
    }
    currentSize--;
    return true;
}

template <class T>
bool Vector<T>::contains(const T& item) const {
    for (int i = 0; i < currentSize; ++i) {
        if (data[i] == item) return true;
    }
    return false;
}

template <class T>
void Vector<T>::push_back(const T& item) {
    if (currentSize == m_capacity) expandCapacity();
    data[currentSize++] = item;
}

template <class T>
int Vector<T>::size() const { return currentSize; }

template <class T>
int Vector<T>::capacity() const { return m_capacity; }

template <class T>
bool Vector<T>::empty() const { return currentSize == 0; }

template <class T>
void Vector<T>::clear() { currentSize = 0; }

template <class T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= currentSize) throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= currentSize) throw std::out_of_range("Index out of bounds");
    return data[index];
}

#endif // VECTOR_H
