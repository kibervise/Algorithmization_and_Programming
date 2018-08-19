#include <iostream>
#include <cmath>
using namespace std;


void fraction(int n, int i, double result)
{
    if (i!=n)
    {
        i++;
        cout << "n = " << n << "\ni = "<<  i << "\nResult inside: " << result << endl;
        return fraction(n,i,1/((i)+result));
    }
    else
        cout << "General result: " << result << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    fraction(n,0,0.5);
}










