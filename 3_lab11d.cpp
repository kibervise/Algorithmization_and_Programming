#include <iostream>
using namespace std;

void Matrix(int **arr, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if (j < size-i-1)
                arr[i][j] = 0;
            if (j >= size-i-1)
                arr[i][j] = rand()%9+1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf ("Dimension: ");
    scanf("%d", &size);
    int **arr;
    arr = new int *[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = new int[size];
    }
    Matrix(arr, size);
    for(int i=0; i<size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
