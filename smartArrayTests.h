#ifndef SMART_ARRAY_TESTS_H
#define SMART_ARRAY_TESTS_H

#include <iostream>
#include "SmartArray.h"

void testAdd() {
    std::cout << "####################\n";
    std::cout << "test add():\n";

    SmartArray<int> array;
    array.add(3);
    array.add(100);
    array.add(8);
    array.add(9);

    std::cout << "after add():\n";
    std::cout << array;
    std::cout << "####################\n";
}

#endif //SMART_ARRAY_TESTS_H
