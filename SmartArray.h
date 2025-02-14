//
// Created by artem on 2/14/25.
//

#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <stdexcept>
#include <iostream>

template<typename T>
class SmartArray {
public:
    SmartArray(): size_(0),
                  capacity_(START_CAPACITY) {
        array_ = new T[capacity_];
    }

    SmartArray(const SmartArray<T> &other): size_(other.size_),
                                            capacity_(other.capacity_) {
        array_ = new T[capacity_];
        for (int i = 0; i < other.size_; ++i) {
            array_[i] = other.array_[i];
        }
    }

    SmartArray(const SmartArray &&other) noexcept: size_(other.size_),
                                                   capacity_(other.capacity_),
                                                   array_(other.array_) {
    }

    ~SmartArray() {
        delete[] array_;
    }

    int getSize() const {
        return size_;
    }

    int getCapacity() const {
        return capacity_;
    }

    void add(const T &element) {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            T *newArray = new T[capacity_];
            for (int i = 0; i < size_; ++i) {
                newArray[i] = array_[i];
            }
            delete[] array_;
            array_ = newArray;
        }
        array_[size_] = element;
        ++size_;
    }

    T &operator[](const int &index) const {
        return array_[index];
    }

    template<typename T1>
    friend std::ostream& operator<<(std::ostream &os, const SmartArray<T1> &smartArray);

private:
    const int START_CAPACITY = 16;

    int size_;
    int capacity_;
    T *array_;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const SmartArray<T> &smartArray) {
    for (int i = 0; i < smartArray.size_; ++i) {
        os << smartArray[i] << " ";
    }
    os << "\n";
    return os;
}


#endif //SMARTARRAY_H
