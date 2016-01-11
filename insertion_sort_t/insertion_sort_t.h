// 插入排序 insertion_sort_t.h

#include <iostream>
#include <string>

// INSERTION-SORT(A)
// for j = 2 to A.length
//     key = A[j]
//     // Insert A[j] into sorted sequence A[1..j - 1].
//     i = j - 1
//     while i > 0 and a[i] > key
//         a[i + 1] = a[i]
//         i = i - 1
//     a[i + 1] = key

template <class Type> void insert_sort_t(Type * const a, int const & n)
{
    Type key;
    // j赋值为1因为是从第二个元素开始插入排序
    // j<n因为n代表着待排序的数组元素的个数，n-1为最后一个元素
    for (int j = 1; j < n; j++)
    {
        key = a[j];    // 等待插入的元素为a[j]
        int i = j - 1; // a[0...j-1]为已经有序的部分，a[j+1...n-1]为还没有排序的部分
        // 我们首先要比较的是a[j]与a[j-1]
        while ((i >= 0) && (a[i] > key))
        {
            a[i + 1] = a[i]; // 所有比a[j]大的元素后移一位
            i--;
        }
        a[i + 1] = key;      // 将a[j]放到正确的位置上去
    }
}

