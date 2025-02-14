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

void testPop() {
    std::cout << "####################\n";
    std::cout << "test pop():\n";

    SmartArray<int> array;
    array.add(3);
    array.add(100);
    array.add(8);
    array.add(9);
    std::cout << "before pop():\n";
    std::cout << array;

    array.pop();
    std::cout << "after pop():\n";
    std::cout << array;
    std::cout << "####################\n";
}

void testEmptyPop() {
    std::cout << "####################\n";
    std::cout << "test pop() with empty array (exception):\n";

    SmartArray<int> array;
    std::cout << "before pop():\n";
    std::cout << array;

    std::cout << "after pop():\n";
    try {
        array.pop();
    }
    catch (const PopEmptyArrayException& e) {
        std::cout << e.what();
    }
    std::cout << "####################\n";
}

void testSort() {
    std::cout << "####################\n";
    std::cout << "test sort():\n";

    SmartArray<int> array;
    array.add(3);
    array.add(0);
    array.add(100);
    array.add(50);
    array.add(20);
    array.add(5);
    array.add(7);
    std::cout << "before sort():\n";
    std::cout << array;

    array.sort();
    std::cout << "after sort():\n";
    std::cout << array;
    std::cout << "####################\n";
}

void testFind() {
    std::cout << "####################\n";
    std::cout << "test find():\n";

    SmartArray<int> array;
    array.add(3);
    array.add(0);
    array.add(100);
    array.add(50);
    array.add(20);
    array.add(5);
    array.add(7);
    std::cout << "before find():\n";
    std::cout << array;

    array.sort();
    std::cout << "try to find(20). Result:\n";
    int result = array.find(20);
    std::cout << result << "\n";
    std::cout << "####################\n";
}

#endif //SMART_ARRAY_TESTS_H
