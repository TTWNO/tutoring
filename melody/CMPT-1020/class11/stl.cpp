#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> numbers = {1, 2, 3, 4, 5};
    array<string, 4> names = {"James", "Ashley", "Doug", "Claire"};

    cout << numbers[0] << endl; // prints the 0th element; like standard arrays, does no bound checking: will crash if out of range
}

