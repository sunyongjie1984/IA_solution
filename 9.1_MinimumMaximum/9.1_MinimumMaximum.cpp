#include <iostream>
#include <stdint.h>
#ifdef __linux
#include <stdio.h>
#endif
// MINIMUM(A)
// MIN = A[1]
// for i = 2 to A.length
//     if min > A[i]
//         min = A[i]
// return min

int64_t minimum(int64_t* A, int64_t n)
{
    int64_t min = A[0];
    for (int64_t i = 0; i < n; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
    }
    return min;
}

int64_t maximum(int64_t* A, int64_t n)
{
    int64_t max = A[0];
    for (int64_t i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

class MaxMin {
public:
    int64_t min;
    int64_t max;
};

MaxMin maxminmum(int64_t* A, int64_t n)
{
    MaxMin maxmin;
    if (0 == n % 2)
    {
        if (A[0] > A[1])
        {
            maxmin.min = A[1];
            maxmin.max = A[0];
        }
        else
        {
            maxmin.min = A[0];
            maxmin.max = A[1];
        }
        for (int64_t i = 2; i < n - 1; i+=2)
        {
            if (A[i] > A[i + 1])
            {
                if (A[i] > maxmin.max)
                {
                    maxmin.max = A[i];
                }
                if (A[i + 1] < maxmin.min)
                {
                    maxmin.min = A[i + 1];
                }
            }
            else
            {
                if (A[i + 1] > maxmin.max)
                {
                    maxmin.max = A[i + 1];
                }
                if (A[i] < maxmin.min)
                {
                    maxmin.min = A[i];
                }
            }
        }
    }
    else
    {
        maxmin.max = maxmin.min = A[0];
        for (int64_t i = 1; i < n - 1; i+=2)
        {
            if (A[i] > A[i + 1])
            {
                if (A[i] > maxmin.max)
                {
                    maxmin.max = A[i];
                }
                if (A[i + 1] < maxmin.min)
                {
                    maxmin.min = A[i + 1];
                }
            }
            else
            {
                if (A[i + 1] > maxmin.max)
                {
                    maxmin.max = A[i + 1];
                }
                if (A[i] < maxmin.min)
                {
                    maxmin.min = A[i];
                }
            }
        }

    }
    return maxmin;
}

int main()
{
    // even number array
    int64_t array0[6] = { 5, 2, 4, 6, 1, 3 };
    int64_t min = minimum(array0, sizeof(array0) / sizeof(int64_t));
    std::cout << min << std::endl;
    int64_t max = maximum(array0, sizeof(array0) / sizeof(int64_t));
    std::cout << max << std::endl;

    MaxMin maxmin = maxminmum(array0, sizeof(array0) / sizeof(int64_t));
    std::cout << maxmin.min << std::endl;
    std::cout << maxmin.max << std::endl;

    // not even number array
    int64_t array1[7] = { 5, 2, 4, 6, 1, 3, 10 };
    min = minimum(array1, sizeof(array1) / sizeof(int64_t));
    std::cout << min << std::endl;
    max = maximum(array1, sizeof(array1) / sizeof(int64_t));
    std::cout << max << std::endl;

    maxmin = maxminmum(array1, sizeof(array1) / sizeof(int64_t));
    std::cout << maxmin.min << std::endl;
    std::cout << maxmin.max << std::endl;

    getchar();
    return 0;
}
