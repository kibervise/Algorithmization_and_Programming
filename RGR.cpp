#include <iostream>
#include <fstream>
#include <cmath>
#define pi 3.14159265
using namespace std;


double TaylorArccos(double x, double e, int n, double arccos, double K)
{
    if (abs(K) >= e)
    {
        arccos = K + TaylorArccos(x, e, n + 1, 0, K * ( pow((2*n-1) , 2) * pow(x,2) ) / ( 2*n* (2*n + 1)));
    }
    return arccos;
}


void OutputFile(double &Xbegin, double &Xend, double &Xdelta, double &e)
{
    FILE *entry = fopen("/Users/adminisrtator/Documents/C++/FileEntry.txt", "w");
    printf("%s\t|\t %s\t\t|\t %s\n", "\n\tx", "\ty\t", "\tf(x)");
    
    for (double x = Xbegin; x <= Xend; x += Xdelta)
    {
        printf("%.3lf\t|\t %.7lf\t\t|\t %.7lf\n", x, pi / 2 - TaylorArccos(x, e, 1, x, x), acos(x));
        fprintf(entry, "%.3lf\t %.7lf\t %.7lf\n", x, pi / 2 - TaylorArccos(x, e, 1, x, x), acos(x));
    }
    fclose(entry);
}

void CheckData(double Xbegin, double Xend, double Xdelta, double e)
{
    while (Xbegin < -1 || Xbegin >= 1)
    {
        cout << "Incorrect data! Xbegin has a range [-1;1)!\nEnter a number from this range: ";
        cin >> Xbegin;
    }
    
    while (Xend)
    {
        if (Xend > 1)
        {
            cout << "Incorrect data! Xend has a range (-1;1]!\nEnter a number from this range: ";
            cin >> Xend;
        }
        
        else if (Xend <= Xbegin)
        {
            cout << "Incorrect data! Xend should be greater than Xbegin on range (-1;1]!\nEnter a number from this range: ";
            cin >> Xend;
        }
        else
            break;
    }
    
    while (Xdelta <= 0 || Xdelta > 1)
    {
        cout << "Incorrect data! Xdelta should be in a range (0;1]!\nEnter a number from this range: ";
        cin >> Xdelta;
    }
    
    while (e <= 0 || e >= 1)
    {
        cout << "Incorrect data! Epsilon(e) should be in a range (0;1)! Enter another number: ";
        cin >> e;
    }
    
    cout << "\nYour data:\tXbegin: " << Xbegin << endl;
    cout << "\t\t\tXend: " << Xend << endl;
    cout << "\t\t\tXdelta: " << Xdelta << endl;
    cout << "\t\t\te: " << e << endl;
    
    OutputFile(Xbegin, Xend, Xdelta, e);
}

void KeyboardInput(double &Xbegin, double &Xend, double &Xdelta, double &e)
{
    cout << "\nPlease, enter: Xbegin, Xend, Xdelta, e: ";
    cin >> Xbegin >> Xend >> Xdelta >> e;
    CheckData(Xbegin, Xend, Xdelta, e);
}

void FileRead(double &Xbegin, double &Xend, double &Xdelta, double &e)
{
    FILE *read = fopen("/Users/adminisrtator/Documents/C++/FileRead.txt", "r");
    if (read == NULL)
    {
        cout << "Error of file!";
    }
    else
    {
        fscanf(read, " %lf %lf %lf %lf ", &Xbegin, &Xend, &Xdelta, &e);
        cout << "\nYour data:\tXbegin: " << Xbegin << endl;
        cout << "\t\t\tXend: " << Xend << endl;
        cout << "\t\t\tXdelta: " << Xdelta << endl;
        cout << "\t\t\te: " << e << endl;
    }
    OutputFile(Xbegin, Xend, Xdelta, e);
    fclose(read);
    
}

void Call(double &Xbegin, double &Xend, double &Xdelta, double &e)
{
    int num;
    cout << "Enter:\n0 - reading from file\n1 - keyboard input\nYou decision: ";
    cin >> num;
    
    if (num == 0)
    {
        FileRead(Xbegin, Xend, Xdelta, e);
    }
    else
    {
        KeyboardInput(Xbegin, Xend, Xdelta, e);
    }
}

int main()
{
    double Xbegin, Xend, Xdelta, e;
    Call(Xbegin, Xend, Xdelta, e);
}


