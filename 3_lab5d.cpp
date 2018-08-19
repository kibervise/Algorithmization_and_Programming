#include <iostream>
using namespace std;

int main()
{
    int k = 0;
    cout << "Enter the number: ";
    cin >> k;
    if (k>0 && k<40)
    {
        switch(k/10)
        {
            case 1: cout << "X"; break;
            case 2: cout << "XX"; break;
            case 3: cout << "XXX"; break;
        }
        
        switch(k%10)
        {
            case 1: cout << "I"; break;
            case 2: cout << "II"; break;
            case 3: cout << "III"; break;
            case 4: cout << "IV"; break;
            case 5: cout << "V"; break;
            case 6: cout << "VI"; break;
            case 7: cout << "VII"; break;
            case 8: cout << "VIII"; break;
            case 9: cout << "IX"; break;
        }
    }
    else
        cout << "Enter number 1-39!";
    cout <<"\n";
}


