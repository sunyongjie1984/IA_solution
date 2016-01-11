// insertion_sort_t.cpp
#include "insertion_sort_t.h"

#ifdef __linux
#include <stdio.h>
#endif

int main()
{
    int a[6] = { 5, 2, 4, 6, 1, 3 };
    insert_sort_t(a, 6);
    for (int i = 0; i < 6; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    std::string b[4] = { "hello", "China", "haha",  "I Love China"};
    insert_sort_t(b, 4);
    for (int i = 0; i < 4; i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    getchar();
    return 0;
}