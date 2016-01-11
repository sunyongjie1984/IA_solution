// heap.h

// PARENT(i)
// return i / 2
// LEFT(i)
// return 2 * i
// RIGHT(i)
// return 2 * i + 1

// MAX-HEAPIFY(A, i)
// l = LEFT(i)
// r = RIGHT(i)
// if l <= A.heap-size and A[l] > a[i]
//     largest = l
// else largest = i
// if r <= A.heap-size and A[r] > A[largest]
//     largest = r
// if largest != i
//     exchange A[i] with A[largest]
//     MAX-HEAPIFY(A, largest)

// BUILD-MAX-HEAP(A)
// A.heap-size = A.length
// for i = A.length / 2 down to 1
//     MAX-HEAPIFY(A, i)

// HEAPSORT(A)
// BUILD-MAX-HEAP(A)
// for i = A.length down to 2
//     exchange A[1] with A[i]
//     A.heap-size = A.heap-size - 1
//     MAX-HEAPIFY(A, 1)

// HEAP-EXTRACT-MAX
// if A.heap-size < 1
//     error "heap underflow"
// max = A[1]
// A[1] = A[A.heap-size]
// A.heap-size--
// MAX-HEAPIFY(A, 1)
// return max

// HEAP-INCREASE-KEY(A, i, key)
// if key < A[i]
//     error "new key is smaller than current key"
// A[i] = key
// while i > 1 and A[PARENT(i)] < A[i]
//     exchange A[i] with A[PARENT(i)]
//     i = PARENT(i)

// MAX-HEAP-INSERT(key)
// A.heap-size = A.heap-size + 1
// A[A.heap-size] = -MAX
// HEAP-INCREASE-KEY(A, A.heap-size, key)
#include <iostream>
#include <stdint.h>

using std::cout;
using std::endl;

class IA_heap {
public:
    IA_heap(int64_t* p, uint64_t n): m_heap_size(0)
    {
        // m_array = p;
        m_length = n;

        m_array = new int64_t[n];
        memcpy(m_array, p, n * sizeof(int64_t));
    }
    void build_max_heap()
    {
        m_heap_size = m_length - 1;
        for (int64_t i = m_length / 2 - 1; i >= 0; i--)
        {
            max_heapify(i);
        }
    }
    void max_heapify(int64_t i)
    {
        int64_t l = left(i);
        int64_t r = right(i);
        int64_t largest;
        if (l <= m_heap_size && m_array[l] > m_array[i])
        {
            largest = l;
        }
        else
        {
            largest = i;
        }
        if (r <= m_heap_size && m_array[r] > m_array[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(i, largest);
            max_heapify(largest);
        }

    }
    void heap_sort()
    {
        for (uint64_t i = m_length - 1; i >= 1 ; i--)
        {
            swap(0, i);
            m_heap_size--; // a heap after sorting, no a heap anymore
            max_heapify(0);
        }
    }
    int64_t heap_maximum() { return m_array[0]; }
    int64_t heap_extract_max(int64_t& max)
    {
        if (m_heap_size < 0)
        {
            std::cout << "error underflow" <<  std::endl;
            return -1;
        }
        max = m_array[0];
        m_array[0] = m_array[m_heap_size];
        m_heap_size--;
        max_heapify(0);
        return 0;
    }
    void heap_increase_key(int64_t i, int64_t key)
    {
        if (key < m_array[i])
        {
            std::cout << "new key is smaller than current key" << std::endl;
        }
        m_array[i] = key;
        while (i > 0 && m_array[parent(i)] < m_array[i])
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }
    void max_heap_insert(int64_t key)
    {
        m_heap_size++;
        if (m_heap_size == m_length)
        {
            int64_t* p = new int64_t[sizeof(int64_t) * (m_length + 1)];
            memcpy(p, m_array, sizeof(int64_t) * m_length);
            delete [] m_array;
            m_array = p;
            m_length++;
        }
        m_array[m_heap_size] = INT64_MIN;
        heap_increase_key(m_heap_size, key);
    }
    void print_array()
    {
        std::cout << "print_array" << std::endl;
        for (int64_t i = 0; i < m_length; i++)
        {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }
    void print_heap()
    {
        std::cout << "print_heap" << std::endl;
        if (0 == m_heap_size)
        {
            std::cout << "no heap element" << std::endl;
        }
        for (int64_t i = 0; i <= m_heap_size; i++)
        {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    uint64_t left(uint64_t i)
    {
        return 2 * i + 1;
    }
    uint64_t right(uint64_t i)
    {
        return 2 * i + 2;
    }
    uint64_t parent(uint64_t i)
    {
        return (i - 1) / 2;
    }
    void swap(uint64_t i, uint64_t j)
    {
        int64_t tmp = m_array[i];
        m_array[i] = m_array[j];
        m_array[j] = tmp;
    }
    int64_t* m_array;
    int64_t m_heap_size;
    int64_t m_length;
};