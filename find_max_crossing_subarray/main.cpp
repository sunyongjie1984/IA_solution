// main.cpp
#include <iostream>
#ifdef __linux
#include <stdio.h>
#endif

#include "find_max_sub_array.h"

using std::cout;
using std::endl;

int B[10] = { 1, -10, 2, 4, 6, -15, 6, 1, 9, -8 };

int main()
{
    cout<<endl;
    int max_left, max_right, max_value;
    Find_MaxiMum_SubArray(B, 0, sizeof(B)/sizeof(int) - 1 , max_left, max_right, max_value);
    cout<< max_left << "\t" << max_right << "\t" << max_value <<endl;
    cout <<endl;
    getchar();
    return 0;
}