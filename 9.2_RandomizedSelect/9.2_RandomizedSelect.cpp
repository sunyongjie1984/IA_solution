#include <stdint.h>
#include <time.h>
#include <iostream>
#ifdef __linux
#include <stdio.h>
#include <stdlib.h>
#endif

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

// RANDOMIZED-SELECT(A, p, r, i)
// if p == r
//     return A[p]
// q = RANDOMIZED-PARTITION(A, p, r)
// k = q - p + 1
// if i == k
// return A[q]
// else if i < k
//     return RANDOMIZED-SELECT(A, p, q - 1, i)
// else
//     return RANDOMIZED-SELECT(A, q + 1, r, i - k)

int64_t RandomizedSelect(int64_t* A, int64_t p, int64_t r, int64_t i)
{
    if (p == r)
    {
        return A[p];
    }
    int64_t q = RandomizedPartition(A, p, r);
    int64_t k = q - p + 1;
    if (i == k)
    {
        return A[q];
    }
    else if (i < k)
    {
        return RandomizedSelect(A, p, q - 1, i);
    }
    else
    {
        return RandomizedSelect(A, q + 1, r, i - k);
    }
}
int main()
{
    int64_t array[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
    
    std::cout << RandomizedSelect(array, 0, 7, 3) << std::endl;
    getchar();
    return 0;
}
