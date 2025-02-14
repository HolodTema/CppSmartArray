#ifndef SMART_ARRAY_EXCEPTIONS_H
#define SMART_ARRAY_EXCEPTIONS_H

#include <stdexcept>

class IndexOutOfRangeException: public std::exception {
    const char *what() const noexcept override {
        return "Error: index of array is out of range.\n";
    }
};

class PopEmptyArrayException: public std::exception {
    const char* what() const noexcept override {
        return "Error: cannot pop element from the empty array.\n";
    }
};


#endif //SMART_ARRAY_EXCEPTIONS_H
