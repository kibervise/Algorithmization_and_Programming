#include <iostream>
using namespace std;

int FirstBinF(char *bin)
{
    int n = 20;
    int pstv = 0; int ngtv = 0;
    FILE *F1;
    F1 = fopen(bin, "wb");
    for (int i = 0; i < n; i++)
    {
        int c = -10 + rand() % 21;
        if ((c == 0) || (c > 0 && pstv == 10) || (c < 0 && ngtv == 10))
        {
            i--;
        }
        else
        {
            if (c > 0)
            {
                pstv++;
            }
            else
            {
                ngtv++;
            }
            fputc(c, F1);
        }
    }
    fclose(F1);
    return n;
}

void SecondBinF(int n, char *bin1, char *bin2)
{
    // чтение с файла F1
    int *Arr = new int[n];
    FILE *F1;
    F1 = fopen(bin1, "rb");
    int i = 0;
    while (1)
    {
        int symb = fgetc(F1);
        if (feof(F1) != 0)
            break;
        if (symb > 200)
        {
            symb = symb - 256;
        }
        *(Arr + i) = symb;
        i++;
    }
    fclose(F1);
    
    //запись в файл F2
    FILE *F2;
    F2 = fopen(bin2, "wb");
    int pstv = 1;
    for (int i = 0; i <= n-1; i++)
    {
        int j = 0;
        while (j <= n-1)
        {
            if ((pstv == 1 && *(Arr + j) > 0) || (pstv == 0 && *(Arr + j) < 0))
            {
                fputc(*(Arr + j), F2);
                *(Arr + j) = 0;
                if (pstv)
                {
                    pstv = 0;
                }
                else
                {
                    pstv = 1;
                }
                break;
            }
            j++;
        }
    }
    fclose(F2);
}

void FinFunc(int n, char *bin)
{
    FILE *finishfile;
    finishfile = fopen(bin, "rb");
    while (1)
    {
        int value = fgetc(finishfile);
        if (feof(finishfile) != 0)
        {
            printf("\nEnd of reading file!");
            break;
        }
        if (value > 200)
        {
            value = value - 256;
        }
        cout << value << " ";
    }
    fclose(finishfile);
}

int main()
{
    char bin1[] = "/Users/adminisrtator/C++/F1.dat";
    char bin2[] = "/Users/adminisrtator/C++/F2.dat";
    int n;
    n = FirstBinF(bin1);
    printf("Elements of F1: \t");
    FinFunc(n, bin1);
    SecondBinF(n, bin1, bin2);
    printf("\nElements of F2: \t");
    FinFunc(n, bin2);
    
}
