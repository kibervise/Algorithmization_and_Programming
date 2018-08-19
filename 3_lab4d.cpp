#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, R, circle;
    printf("Input x: "); scanf("%lf", &x);
    printf("Input y: "); scanf("%lf", &y);
    printf("Input R: "); scanf("%lf", &R);
    
    circle = ((pow(x,2)+pow(y,2)) < pow(R,2));
    
    if ( circle && (y >= abs(x) || y<=-abs(x)))
        printf("location: inside the shaded area\n");
    
    else
        printf("location: outside of the shaded area\n");
    
}






