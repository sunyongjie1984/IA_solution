// strassen.cpp
#include <ctime>
#include "strassen.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Strassen_class<int> stra; // ����Strassen_class�����
    int MatrixSize = 0;

    int** MatrixA;            // ��ž���A
    int** MatrixB;            // ��ž���B
    int** MatrixC;            // ��Ž������

    clock_t startTime_For_Normal_Multipilication ;
    clock_t endTime_For_Normal_Multipilication ;

    clock_t startTime_For_Strassen ;
    clock_t endTime_For_Strassen ;
    srand(static_cast<unsigned int>(time(0)));

    cout << "\n����������С(������2����ָ��ֵ(����:32,64,512,..): ";
    cin >> MatrixSize;
    cout << endl;
    int N = MatrixSize; // for readiblity.

    // �����ڴ�
    MatrixA = new int*[MatrixSize];
    MatrixB = new int*[MatrixSize];
    MatrixC = new int*[MatrixSize];

    for (int i = 0; i < MatrixSize; i++)
    {
        MatrixA[i] = new int[MatrixSize];
        MatrixB[i] = new int[MatrixSize];
        MatrixC[i] = new int[MatrixSize];
    }

    stra.FillMatrix(MatrixA, MatrixB, MatrixSize);  // ����ֵ

    //*******************conventional multiplication test
    cout << "���ؾ����㷨��ʼʱ��: " << (startTime_For_Normal_Multipilication = clock());

    stra.MUL(MatrixA, MatrixB, MatrixC, MatrixSize); // ���ؾ�������㷨 T(n) = O(n^3)

    cout << "\n���ؾ����㷨����ʱ��: " << (endTime_For_Normal_Multipilication = clock());

    cout << "\n����������... \n";
    stra.PrintMatrix(MatrixC, MatrixSize);

    //*******************Strassen multiplication test
    cout << "\nStrassen�㷨��ʼʱ��: " << (startTime_For_Strassen = clock());

    stra.Strassen(N, MatrixA, MatrixB, MatrixC); // strassen��������㷨

    cout << "\nStrassen�㷨����ʱ��: " << (endTime_For_Strassen = clock());


    cout << "\n����������... \n";
    stra.PrintMatrix(MatrixC, MatrixSize);

    cout << "�����С " << MatrixSize;
    cout << "\n���ؾ����㷨: " << (endTime_For_Normal_Multipilication - startTime_For_Normal_Multipilication) << " Clocks.." << (endTime_For_Normal_Multipilication - startTime_For_Normal_Multipilication) / CLOCKS_PER_SEC << " Sec";
    cout << "\nStrassen�㷨: " << (endTime_For_Strassen - startTime_For_Strassen) << " Clocks.." << (endTime_For_Strassen - startTime_For_Strassen) / CLOCKS_PER_SEC << " Sec\n";

    getchar();
    return 0;

}
