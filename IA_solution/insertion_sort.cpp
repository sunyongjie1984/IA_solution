// insertion_sort.cpp
#include "insertion_sort.h"

#ifdef __linux
#include <stdio.h>
#endif

int main()
{
    uint64_t array[6] = { 5, 2, 4, 6, 1, 3 };
    for (uint64_t i = 0; i < sizeof(array) / sizeof(uint64_t); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    insertion_sort(array, sizeof(array) / sizeof(uint64_t));
    for (uint64_t i = 0; i < sizeof(array) / sizeof(uint64_t); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    getchar();
    return 0;
}