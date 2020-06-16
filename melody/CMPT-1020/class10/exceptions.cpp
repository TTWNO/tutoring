#include <iostream>
#include <exception>

using namespace std;

double divide(double, double);

int main()
{
    int x, y;
    cout << "Enter the first number: ";
    cin >> x;

    cout << "Enter the second number: ";
    cin >> y;

    try 
    {
        double g = divide(x, y);
        cout << x << "/" << y << "=" << g << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    return 0;
}

double divide(double a, double b)
{
    if (b == 0)
        throw "Second number should not be zero!";
    return a / b; 
}