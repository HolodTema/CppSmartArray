#ifndef SMART_ARRAY_EXCEPTIONS_H
#define SMART_ARRAY_EXCEPTIONS_H

#include <stdexcept>

class IndexOutOfRangeException final: public std::exception {
public:
    const char *what() const noexcept override {
        return "Error: index of array is out of range.\n";
    }
};

class PopEmptyArrayException final: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: cannot pop element from the empty array.\n";
    }
};


#endif //SMART_ARRAY_EXCEPTIONS_H
