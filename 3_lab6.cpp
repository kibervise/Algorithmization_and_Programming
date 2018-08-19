#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "\tПри делении на 5 и получения остатка 3, надо что бы число заканчивалось на 3 или 8\n\n";
    
    int m, n, i, sum = 0;
    printf("Input m: "); scanf("%i",&m);
    printf("Input n: "); scanf("%i",&n);
    
    for (i = m; i <= n; i++)
        if (i % 5 == 3)
        {
            sum += i;
            cout << "Number: "<< i << endl;
        }
    
    cout << "Sum = " << sum << endl;

}



