// �������� insertion_sort_t.h

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
    // j��ֵΪ1��Ϊ�Ǵӵڶ���Ԫ�ؿ�ʼ��������
    // j<n��Ϊn�����Ŵ����������Ԫ�صĸ�����n-1Ϊ���һ��Ԫ��
    for (int j = 1; j < n; j++)
    {
        key = a[j];    // �ȴ������Ԫ��Ϊa[j]
        int i = j - 1; // a[0...j-1]Ϊ�Ѿ�����Ĳ��֣�a[j+1...n-1]Ϊ��û������Ĳ���
        // ��������Ҫ�Ƚϵ���a[j]��a[j-1]
        while ((i >= 0) && (a[i] > key))
        {
            a[i + 1] = a[i]; // ���б�a[j]���Ԫ�غ���һλ
            i--;
        }
        a[i + 1] = key;      // ��a[j]�ŵ���ȷ��λ����ȥ
    }
}

