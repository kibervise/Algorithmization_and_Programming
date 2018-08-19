#include <iostream>
using namespace std;
#define s 17

void Matrix(int arr[s][s])
{
    for(int i=0; i<s; i++)
    {
        for(int j=0; j<s; j++)
        {
            if (j < s-i-1)
                arr[i][j] = 0;
            if (j >= s-i-1)
                arr[i][j] = rand()%9+1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[s][s];
    Matrix(arr);
}




















