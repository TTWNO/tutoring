/*
 * Factorial
 * 
 * !n = n x n-1 x n-2 ... x 1
 **/

#include <iostream>
using namespace std;

int ifact(int);
int main()
{
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << n + "!=" + ifact(n) << endl;
    return 0;
}

int ifact(int x)
{
    int factorial = 1;
    for (int i = 1; i <= x; i++) // 1 to x
    {
        // equal to: factorial *= i;
        factorial = factorial * i;
    }
    return factorial;
}

/* This version will not compile under GCC (using the GCC compiler).
* GCC requires that a function have a garunteed return.
*/
int rfact_mohammed(int x)
{
    if (x == 0)  // can also be x == 1; more efficient by one function call
        return 1;
    if (x >= 1)
        return x * rfact_mohammed(x - 1);
}

// assumes positive value >= 1; will run infinitely if x <= 0
int rfact(int x)
{
    if (x == 1)
        return 1;
    else
        return x * rfact(x-1);
}

// you can inline if statements in some simple cases:
//  format is (statement) ? (if true) : (else)
// This is called the trenary operator. Like binary but one more.
int rfact_trenary(int x)
{
    return x == 1 ? 1 : x * rfact_trenary(x-1);
}