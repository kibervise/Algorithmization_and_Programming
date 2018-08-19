#include <iostream>
using namespace std;

void Array_el(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        arr[i] = rand() %5;
        cout << arr[i] << " ";
    }
}

void Array_z(int arr[], int size)
{
    for (int i=size-1; i>0; i--)
    {
        if (arr[i] == 0)
        {
            for(int j = i+1; j<size; j++)
            {
                arr[j-1] = arr[j];
            }
            arr[size-1]=0;
        }
    }
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main ()
{
    int size;
    cout << "Dimension: ";
    cin >> size;
    int *arr;
    arr = new int[size];
    Array_el(arr, size);
    cout << endl;
    Array_z(arr, size);
    delete[] arr;
}





