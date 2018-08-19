#include <iostream>
using namespace std;

int main()
{
    int D = 0;
    cout << "Enter the day of January: ";
    cin >> D;
    if (D>0 && D<32)
    {
        switch(D % 7)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                cout << "is working day!\n"; break;
            case 6: cout << "is Saturday!\n"; break;
            case 0: cout << "is Sunday!\n"; break;
        }
    }
    else
        cout << "Such day doesn't exist! Try again\n";
}
















