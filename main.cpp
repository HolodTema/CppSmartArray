#include <iostream>
#include "SmartArray.h"

int main()
{
    int el = 9;
    SmartArray<int> array;
    for (int i = 0; i < 100; ++i) {
        array.add(i);
    }
    std::cout << array;
    return 0;
}
