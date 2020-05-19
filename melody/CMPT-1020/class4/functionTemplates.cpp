#include <iostream>
using namespace std;

template <typename T>
T mult10(T x)
{
    T y;
    y = 10 * x;
    return y;
}
template <typename T>
T simplified_mult10(T x){
    return x * 10;
}

// example 1 from ppt
// This allows two independently arbitrary types; e.g. miles is a float, gallons is an int, vice-versa, etc.
template <class T1, class T2>
double mpg(T1 miles, T2 gallons)
{
    return miles / gallons;
}
// the following version requires that miles and gallons are of the same type; they may be of any type, but they must be the same type
template <class T1>
double mpg(T1 miles, T1 gallons)
{
    return miles / gallons;
}


int main(){
    int a = 3;
    cout << "10 times " << a << " = " << mult10(a) << endl;

    double b = 3.14159265357;
    cout << "10 times " << b << " = " << mult10(b) << endl;

    float c = 3.22;
    cout << "10 times " << c << " = " << mult10(c) << endl;

    return 0;
}