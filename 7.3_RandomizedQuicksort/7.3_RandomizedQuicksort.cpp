#include <stdint.h>
#include <iostream>
#include <time.h>
#ifdef __linux
#include <stdlib.h>
#include <stdio.h>
#endif

// RANDOMIZED-QUICKSORT(A, p, r)
// if p < r
//     q = PARTITION(A, p, r)
//     RANDOMIZED-QUICKSORT(A, p, q - 1)
//     RANDOMIZED-QUICKSORT(A, q + 1, r)
// To sort an entire array, the initial call is RANDOMIZED-QUICKSORT(A, 1, A.length)

// PARTITION(A, p, r)
// x = A[r]
// i = p - 1
// for j = p to r - 1
//     if A[j] <= x
//         i = i + 1
//         exchange A[i + 1] with A[r]
// exchange a[i + 1] with A[r]
// return i + 1

// RANDOMIZED-PARTITION
// i = RANDOM(p, r)
// exchangeA[r] with A[i]
// return PARTITION(A, p, r)

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

int64_t RandomizedPartition(int64_t* A, int64_t p, int64_t r)
{
    int64_t i = (rand() % (r - p)) + p;
    swap(A, i, r);
    return partition(A, p, r);
}

void RandomQuicksort(int64_t* A, int64_t p, int64_t r)
{
    if (p < r)
    {
        int64_t q = RandomizedPartition(A, p, r);
        RandomQuicksort(A, p, q - 1);
        RandomQuicksort(A, q + 1, r);
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

int main()
{
    srand((int)time(0));

    int64_t array[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
    print_array(array, 8);
    RandomQuicksort(array, 0, 7);
    print_array(array, 8);
    getchar();
    return 0;
}
