#include <iostream>
#include <bitset>
using namespace std;

int fun_bit(int x, int y, int p, int n)
{
    int x_left, x_right, x_both;
    // cout << bitset<8>(x) << endl; // вывод х
    x_left = x >> (p + n);
    x_left <<= p + n;
    //cout << bitset<8>(x_left) << endl; // вывод левой части числа х
    x_right = x >> (p);
    x_right <<= p;
    x_right = x^x_right;
    // cout << bitset<8>(x_right) << endl; // вывод правой части числа х
    x_both = x_left | x_right;
    //cout << bitset<8>(x_both) << endl; // вывод без вырезаной части числа х
    //cout << bitset<8>(y) << endl; // вывод y в двоичном
    
    int leny = y, len = 0;
    while (leny != 0)
    {
        len++;
        leny>>=1;
    }
    int sdvig = 1;
    for (int i = 0; i < len; i++)
    {
        if (i < n)
        {
            if (y & sdvig) y &= ~sdvig;
            else y |= sdvig;
        }
        else
        {
            if (y & sdvig) y &= ~sdvig;
        }
        sdvig <<= 1;
    }
    //cout << bitset<8>(y) << endl; // n правых инвертированых битов
    y <<= p;
    //cout << bitset<8>(y) << endl; // сдвинули чтобы уравн€ть позиции по центру с вырезанной частью в х
    x = x_both | y;
    //  cout << bitset<8>(x) << endl; // склеили
    return x;
}

int main()
{
    int x, y, p, n;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter p: ";
    cin >> p;
    cout << "Enter n: ";
    cin >> n;
    int f = fun_bit(x, y, p, n);
    cout << "x = " << bitset<16>(x) << endl << "y = " << bitset<16>(y) << endl << "result = " << bitset<16>(f) << endl;
}


