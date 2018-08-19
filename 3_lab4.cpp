#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, R, circle;
    printf("Input x: "); scanf("%lf", &x);
    printf("Input y: "); scanf("%lf", &y);
    printf("Input R: "); scanf("%lf", &R);
    
    circle = ((pow(x,2)+pow(y,2)) >= pow(R,2));
    
    if ( x==0 && y==0 )
        printf("intersection: point with coordinates (0,0)\n");
    else
        if  (circle)
            printf("location: outside the circle\n");
        else
        {
            printf("location: inside the circle\n");
            if ( y >= abs(x))
                printf("intersection: above the curve\n");
            else
                if ( y<=-abs(x) )
                    printf("intersection: under the curve\n");
                else
                    printf("intersection: outside the shaded area\n");
            
        }
}



