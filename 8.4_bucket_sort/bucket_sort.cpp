#include <time.h>
#include <iostream>
#include <iomanip>
using namespace  std;

// BUCKET-SORT(A)
// let B[0..n - 1] be a new array
// n = A.length
// for i = 0 to n - 1
//     make B[i] an empty list
// for i = 1 to n
//     insert A[i] into list B[|_nA[i]_|]
// for i = 0 to n - 1
//     sort list B[i] with insertion sort
// concatenate the lists B[0], B[1],....B[n - 1] together in order

/*initial arr*/
void InitialArr(double *arr,int n)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i<n;i++)
    {
        arr[i] = rand()/double(RAND_MAX+1);   //(0.1)
    }
}

/* print arr*/
// void PrintArr(double *arr,int n)
// {
//     for (int i = 0;i < n; i++)
//     {
//         cout<<setw(15)<<arr[i];
//         if ((i+1)%5 == 0 || i ==  n-1)
//         {
//             cout<<endl;
//         }
//     }
// }

void PrintArr(double *arr,int n)
{
    for (int i = 0;i < n; i++)
    {
        cout<<setw(15)<<arr[i];
//         if ((i+1)%5 == 0 || i ==  n-1)
//         {
//             cout<<endl;
//         }
    }
    cout << endl;
}

void BucketSort(double * arr,int n)     
{
    double **bucket = new double*[10];
    for (int i = 0;i<10;i++)
    {
        bucket[i] = new double[n];
    }
    int count[10] = {0};
    for (int i = 0 ; i < n ; i++)
    {
        double temp = arr[i];
        int flag = (int)(arr[i]*10); //flag标识小树的第一位 
        bucket[flag][count[flag]] = temp; //用二维数组的每个向量来存放小树第一位相同的数据
        int j = count[flag]++;

        /* 利用插入排序对每一行进行排序 */
        for(;j > 0 && temp < bucket[flag][j - 1]; --j)
        {
            bucket[flag][j] = bucket[flag][j-1];
        }
        bucket[flag][j] =temp;
    }

    /* 所有数据重新链接 */
    int k=0;
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j< count[i];j++)
        {
            arr[k] = bucket[i][j];
            k++;
        }
    }
    for (int i = 0 ; i<10 ;i++)
    {
        delete bucket[i];
        bucket[i] =NULL;
    }
    delete []bucket;
    bucket = NULL;
}

int main()
{
    double *arr=new double[10];
    InitialArr(arr, 10);
    PrintArr(arr,10);
    BucketSort(arr, 10);
    PrintArr(arr,10);
    delete [] arr;
    getchar();
    return 0;
}
