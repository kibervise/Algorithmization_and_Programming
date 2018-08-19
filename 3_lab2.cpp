#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    cout << "Enter x : ";
    cin >> x;
    y = ( 5 * pow(x,2) + sin(x) ) / cos(x);
    cout << "Result = " << y << endl;
    
    
    return 0;
}

