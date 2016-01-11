// insertion_sort.h
#include <iostream>
#include <stdint.h>
// INSERTION-SORT(A)
// for j = 2 to A.length
//     key = A[j]
//     // Insert A[j] into sorted sequence A[1..j - 1].
//     i = j - 1
//     while i > 0 and a[i] > key
//         a[i + 1] = a[i]
//         i = i - 1
//     a[i + 1] = key

// allow the same key

void insertion_sort(uint64_t* A, uint64_t const n)
{   
    uint64_t key;
    int64_t i;
    // j = 2 to A.length(j 1 to n - 1)
    for (uint64_t j = 1; j < n; j++) // j begin with A[1]
    {
        key = A[j];
        i = j - 1;                   // i begin with A[0]
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}