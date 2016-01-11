#include <stdint.h>
#include <memory>
#include <iostream>
#ifdef __linux
#include <stdio.h>
#endif
// COUNTING-SORT(A, B, k)
// let C[0...k] be a new array
// for i = 0 to k
//     C[i] = 0
// for j = 1 to A.length
//     C[A[j]] = C[A[j]] + 1
// // C[i] now contains the number of elements equal to i .
// for i = 1 to k
//     C[i] = C[i] + C[i - 1]
// // C[i] now contains the number of elements less than or equal to i .
// for j = A.length to 1
//     B[C[A[j]]] = A[j]
//     C[A[j]] = C[A[j]] - 1

void counting_sort(int64_t* const A, int64_t* B, int64_t const n, int64_t const k)
{
    int64_t* C = new int64_t[k]();
    for (int64_t j = 0; j < n; j++)
    {
        C[A[j]]++;
    }
    for (int64_t i = 1; i < k; i++)
    {
        C[i] += C[i - 1];
    }
    for (int64_t j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

// array B is not necessary
void counting_sort2(int64_t* A, int64_t const n, int64_t const k)
{
    int64_t* C = new int64_t[k](); // each elements initialized 0
    for (int64_t j = 0; j < n; j++)
    {
        C[A[j]]++;
    }
    int z = 0;
    for (int i = 0; i <= k; i++)
    {
        while (C[i]-- > 0)
        {
            A[z++] = i;
        }
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
    int64_t array[8] = { 2, 5, 3, 0, 2, 3, 0, 3 };
    print_array(array, 8);
    int64_t output[8];
    counting_sort(array, output, 8, 6);
    print_array(output, 8);
    getchar();

    counting_sort2(array, 8, 6);
    print_array(array, 8);
    getchar();

    int64_t array2[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
    print_array(array2, 8);
    counting_sort2(array2, 8, 9);
    print_array(array2, 8);
    getchar();

    return 0;
}
