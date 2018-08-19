#include <iostream>
using namespace std;
#define s 14

void Array_el(int arr[s])
{
    for (int i=0; i<s; i++)
    {
        arr[i] = rand() %5;
        cout << arr[i] << " ";
    }
}

void Array_z(int arr[s])
{
    for (int i=s-1; i>0; i--)
    {
        if (arr[i] == 0)
        {
            for(int j = i+1; j<s; j++)
            {
                arr[j-1] = arr[j];
            }
            arr[s-1]=0;
        }
    }
    for (int i=0; i<s; i++)
    {
        cout << arr[i] << " ";
    }
}

int main ()
{
    int arr[s];
    Array_el(arr);
    cout << endl;
    Array_z(arr);
    
}

