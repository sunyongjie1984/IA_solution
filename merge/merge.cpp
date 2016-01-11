// 2.3.1 merge.cpp
#include <iostream>

#ifdef __linux
#include <stdio.h>
#endif

#include "merge.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
#if __WORDSIZE == 64
    std::cout << "WORD_SIZE == 64" << std::endl;
#endif
    int const n(10);
    int64_t a[n] = { 9, 1, 3, 10, 7, -3, 4, 2, 5, 0 };

    merge_sort(a, 0, n - 1);
    cout << "The sorted array is" << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    getchar();
    return 0;
}
