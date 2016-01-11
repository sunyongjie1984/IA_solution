// find_max_sub_array.h
#include <stdint.h>

int Find_MAX_CROSSING_SUBARRAY(int* A, int low, int mid, int high, int& max_left, int& max_right, int& max_value)
{
    int left_sum = 0xFFFFFFFF; // 不可能的最小值
    int sum = 0;

    for(int i = mid; i > low; i--)
    {
        sum = sum + A[i];
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = 0xFFFFFFFF; // 不可能的最小值
    sum = 0;

    for(int j = mid + 1; j < high; j++)
    {
        sum = sum + A[j];
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }

    max_value = left_sum + right_sum;
    return 0;
}

int Find_MaxiMum_SubArray(int* A, int low, int high, int& max_left, int& max_right, int& max_value)
{
    if(high == low)
    {
        max_left  = low;
        max_right = high;

        max_value = A[low];
    }
    else
    {
        int mid = (low + high) / 2;

        int tmp_left_low;
        int tmp_left_high;
        int tmp_left_sum;

        Find_MaxiMum_SubArray(A, low, mid, tmp_left_low, tmp_left_high, tmp_left_sum);

        int tmp_right_low;
        int tmp_right_high;
        int tmp_right_sum;

        Find_MaxiMum_SubArray(A, mid + 1, high, tmp_right_low, tmp_right_high, tmp_right_sum);

        int tmp_cross_low;
        int tmp_cross_high;
        int tmp_cross_sum;

        Find_MAX_CROSSING_SUBARRAY(A, low, mid, high, tmp_cross_low, tmp_cross_high, tmp_cross_sum);

        if ((tmp_left_sum >= tmp_right_sum) && (tmp_left_sum >= tmp_cross_sum))
        {
            max_left  = tmp_left_low;
            max_right = tmp_left_high;
            max_value = tmp_left_sum;
        }
        else if((tmp_right_sum >= tmp_left_sum) && (tmp_right_sum >= tmp_cross_sum))
        {
            max_left  = tmp_right_low;
            max_right = tmp_right_high;
            max_value = tmp_right_sum;
        }
        else
        {
            max_left  = tmp_cross_low;
            max_right = tmp_cross_high;
            max_value = tmp_cross_sum;
        }
    }
    return 0;
}
