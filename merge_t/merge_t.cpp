// merge_t.cpp
#include <iostream>

#include "merge_t.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int const n(10);
    int64_t a[n] = { 9, 1, 3, 10, 7, -3, 4, 2, 5, 0 };

    merge_sort_t(a, 0, n - 1);
    cout << "The sorted array is" << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    getchar();
    return 0;
}
