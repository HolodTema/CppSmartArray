//
// Created by artem on 2/14/25.
//

#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <stdexcept>
#include <iostream>
#include "smartArrayExceptions.h"

template<typename T>
class SmartArray {
public:
    SmartArray(): size_(0),
                  capacity_(START_CAPACITY) {
        array_ = new T[capacity_];
    }

    //copy constructor
    SmartArray(const SmartArray<T> &other): size_(other.size_),
                                            capacity_(other.capacity_) {
        array_ = new T[capacity_];
        for (int i = 0; i < other.size_; ++i) {
            array_[i] = other.array_[i];
        }
    }

    //move constructor
    SmartArray(const SmartArray &&other) noexcept: size_(other.size_),
                                                   capacity_(other.capacity_),
                                                   array_(other.array_) {
    }

    ~SmartArray() {
        delete[] array_;
    }

    //copy assignment operator
    SmartArray<T>& operator=(const SmartArray& other) {
        if (this == &other) {
            return *this;
        }
        SmartArray<T> otherToCopy = SmartArray(other);
        swap(otherToCopy, *this);
        return *this;
    }

    //move assignment operator
    SmartArray<T>& operator=(SmartArray&& other) noexcept {
        swap(other, *this);
        return *this;
    }

    const int& getSize() const {
        return size_;
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

    const T& pop() {
        if (size_ > 0) {
            T result = array_[--size_];
            array_[size_] = 0;
            return result;
        }
        else {
            throw PopEmptyArrayException();
        }
    }

    int find(const T& element) const {
        for (int i = 0; i < size_; ++i) {
            if (element == array_[i]) {
                return i;
            }
        }
        return -1;
    }

    bool contains(const T& element) const {
        for (int i = 0; i < size_; ++i) {
            if (element == array_[i]) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    SmartArray<T>& sort() {
        if (size_ <= 1) {
            return *this;
        }

        for (int i = 0; i < size_; ++i) {
            for (int j = 0; j < size_-1; ++j) {
                if (array_[j] > array_[j+1]) {
                    std::swap(array_[j], array_[j+1]);
                }
            }
        }
        return *this;
    }

    void clear() {
        delete[] array_;
        capacity_ = START_CAPACITY;
        array_ = new T[capacity_];
        size_ = 0;
    }

    T &operator[](const int &index) const {
        if (index < size_) {
            return array_[index];
        }
        else {
            throw IndexOutOfRangeException();
        }
    }

    template<typename T1>
    friend std::ostream& operator<<(std::ostream &os, const SmartArray<T1> &smartArray);

private:
    const int START_CAPACITY = 16;

    int size_;
    int capacity_;
    T *array_;

    void swap(const SmartArray& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        array_ = other.array_;
    }
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
