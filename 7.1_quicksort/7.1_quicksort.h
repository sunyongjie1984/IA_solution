#include <stdint.h>
#include <iostream>
// QUICKSORT(A, p, r)
// if p < r
//     q = PARTITION(A, p, r)
//     QUICKSORT(A, p, q - 1)
//     QUICKSORT(A, q + 1, r)
// To sort an entire array, the initial call is QUICKSORT(A, 1, A.length)

// PARTITION(A, p, r)
// x = A[r]
// i = p - 1
// for j = p to r - 1
//     if A[j] <= x
//         i = i + 1
//         exchange A[i + 1] with A[r]
// exchange a[i + 1] with A[r]
// return i + 1

void swap(int64_t* A, uint64_t i, uint64_t j)
{
    int64_t tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int64_t partition(int64_t* A, int64_t p, int64_t r)
{
    int64_t x = A[r];
    int64_t i = p;
    for (int64_t j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            swap(A, i, j);
            i++;
        }
    }
    swap(A, i, r);
    return i;
}

void quicksort(int64_t* A, int64_t p, int64_t r)
{
    if (p < r)
    {
        int64_t q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

void print_array(int64_t* A, int64_t n)
{
    std::cout << "print array" << std::endl;
    for (int64_t i = 0; i < n; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}