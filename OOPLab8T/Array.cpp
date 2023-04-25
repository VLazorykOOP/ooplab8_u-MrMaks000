#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
private:
    T* data;
    int size;
public:
    // Constructor
    Array(int n = 10) {
        size = n;
        data = new T[n];
    }

    // Copy Constructor
    Array(const Array& arr) {
        size = arr.size;
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = arr.data[i];
        }
    }

    // Destructor
    ~Array() {
        delete[] data;
    }

    // Operator []
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            std::cerr << "Index out of range!" << std::endl;
            std::exit(1);
        }
        return data[index];
    }

    // Operator =
    Array& operator=(const Array& arr) {
        if (this != &arr) {
            delete[] data;
            size = arr.size;
            data = new T[size];
            for (int i = 0; i < size; ++i) {
                data[i] = arr.data[i];
            }
        }
        return *this;
    }

    // Operator +
    Array operator+(const Array& arr) const {
        if (size != arr.size) {
            std::cerr << "Array sizes do not match!" << std::endl;
            std::exit(1);
        }
        Array sum(size);
        for (int i = 0; i < size; ++i) {
            sum.data[i] = data[i] + arr.data[i];
        }
        return sum;
    }

    // Operator +=
    Array& operator+=(const Array& arr) {
        if (size != arr.size) {
            std::cerr << "Array sizes do not match!" << std::endl;
            std::exit(1);
        }
        for (int i = 0; i < size; ++i) {
            data[i] += arr.data[i];
        }
        return *this;
    }

    // Operator -
    Array operator-(const Array& arr) const {
        if (size != arr.size) {
            std::cerr << "Array sizes do not match!" << std::endl;
            std::exit(1);
        }
        Array diff(size);
        for (int i = 0; i < size; ++i) {
            diff.data[i] = data[i] - arr.data[i];
        }
        return diff;
    }

    // Operator -=
    Array& operator-=(const Array& arr) {
        if (size != arr.size) {
            std::cerr << "Array sizes do not match!" << std::endl;
            std::exit(1);
        }
        for (int i = 0; i < size; ++i) {
            data[i] -= arr.data[i];
        }
        return *this;
    }
};


