#include <iostream>
#include <iomanip>
#define LEN 10
using namespace std;

void Out(int arr[LEN][LEN])
{
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}

void ShakerSort(int Array[LEN][LEN])
{
    
    int m = LEN;
    int SortedList[LEN][LEN]; int z = 0;
    while (z < LEN)
    {
        int arr[LEN];
        for (int i = 0; i < LEN; i++)
            arr[i] = Array[i][z];
        
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
            }
            m--;
            
            for (int k = m - 1; k > i; k--)
            {
                if (arr[k] < arr[k - 1])
                    swap(arr[k], arr[k - 1]);
            }
        }
        
        for (int q = 0; q < LEN; q++)
        {
            SortedList[q][z] = arr[q];
        }
        z++; m = LEN;
    }
    printf("Sorted matrix:\n\n");
    Out(SortedList);
}

void Create_Matrix(int arr[LEN][LEN])
{
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            arr[i][j] = rand() % 51;
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    ShakerSort(arr);
}

int main()
{
    int arr[LEN][LEN];
    printf("Initial matrix:\n\n");
    Create_Matrix(arr);

}



