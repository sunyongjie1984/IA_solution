#include<iostream>
#include<malloc.h>
#include <stdint.h>
#ifdef __linux
#include <string.h>
#endif

using namespace std;

void PrintArr(int64_t ar[], int64_t n)
{
    for(int64_t i = 0; i < n; ++i)
        cout << ar[i] << " ";
    cout << endl;
}

// int64_t  ar[] = {12, 14, 354, 5, 6, 233, 9, 8, 47, 89};
// 使用计数排序，稳定的排序按数组A中第d位排序数组A，如下约定123的第一位是3,第三位是1
// A待排序数组 B排序之后的数组 n数组元素个数 k待排序数中最大的数字是多少 d数组A中最大数的位数
void counting_sort(int64_t* const A, int64_t* B, int64_t const n, int64_t const k, int64_t const d)
{
    int64_t* number_to_sort = new int64_t[n];
    memcpy(number_to_sort, A, n * sizeof(int64_t));
    for (int64_t i = 0; i < n; i++)
    {
        for (int64_t j = 1; j < d; j++)
        {
            number_to_sort[i] = number_to_sort[i] / 10;
        }
    }
    int64_t* C = new int64_t[k]();
    for (int64_t j = 0; j < n; j++)
    {
        C[number_to_sort[j] % 10]++;
    }
    for (int64_t i = 1; i < k; i++)
    {
        C[i] += C[i - 1];
    }
    for (int64_t j = n - 1; j >= 0; j--)
    {
        B[C[number_to_sort[j] % 10] - 1] = A[j];
        C[number_to_sort[j] % 10]--;
    }
}

// RADIX-SORT(A, d)
// for i = 1 to d
//     use a stable sort to sort array A on digit i
void radix_sort(int64_t* A, int64_t* output_ar, int64_t n, int64_t d)
{
    int64_t* arr = new int64_t[n];
    for (int64_t i = 1; i <= d; i++)
    {   
        counting_sort(A, arr, n, 10, i);
        memcpy(A, arr, 10 * sizeof(int64_t));
    }
    memcpy(output_ar, arr, 10 * sizeof(int64_t));
}

int main()
{
    int64_t  ar[] = {14, 12, 354, 5, 123, 233, 9, 8, 47, 89};
    int64_t  output_ar[10];
    int len = sizeof(ar) / sizeof(int64_t);
    cout << "before sort：" << endl;
    PrintArr(ar, len);
    radix_sort(ar, output_ar, 10, 3);
    cout << "before sort：" << endl;
    PrintArr(output_ar, len);
    getchar();

    return 0;
}
