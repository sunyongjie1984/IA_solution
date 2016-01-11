#include "heap.h"
int main()
{
    int64_t array[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    IA_heap A(array, sizeof(array) / sizeof(int64_t));
    A.print_array();
    A.print_heap();

    A.build_max_heap();
    std::cout << "A.heap_maximum: " << A.heap_maximum() << std::endl;
    A.print_array();
    A.print_heap();

    A.heap_increase_key(8, 15);
    A.print_array();
    A.print_heap();

    A.max_heap_insert(13);
    A.print_array();
    A.print_heap();

    int64_t max;
    
    if (0 == A.heap_extract_max(max))
    {
        std::cout << max << std::endl;
    }
    A.print_array();
    A.print_heap();
    while (0 == A.heap_extract_max(max))
    {
        std::cout << max << std::endl;
    }
    

//     A.heap_sort();
//     A.print_array();
//     A.print_heap();

    getchar();
    return 0;
}
