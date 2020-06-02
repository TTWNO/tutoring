// fibbonaci

#include <iostream>
using namespace std;


int fibbonaci(int);
int main()
{
    int n, fi;
    cout << "Enter a positive integer: ";
    cin >> n;
    fi = fibbonaci(n);
    return 0;
}

int fibbonaci(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    else
        return fibbonaci(x-1) + fibbonaci(x-2);
    }   