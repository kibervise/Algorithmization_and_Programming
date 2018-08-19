#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, d, y;
    printf ("Enter a, b, c, d: \n");
    scanf("%f%f%f%f",&a,&b,&c,&d);
    y = cos(pow(a,-b)) + 7 * abs(asin(-3 * sqrt(c/d)));
    
    printf("\ny = : y =%f", y);
}


