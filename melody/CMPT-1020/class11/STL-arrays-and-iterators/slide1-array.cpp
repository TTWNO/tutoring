#include <iostream>
#include <array>
#include <string>
using namespace std;

int main()
{
    const int SIZE = 4;
    // Store some names in an array object
    array<string, SIZE> names = {"Jamie", "Ashley", "Doug", "Claire"};

    // display the names
    cout << "Here are the names: " << endl;
    for (int index = 0; index < names.size(); index++)
    {
        cout << names[index] << endl;
    }
    return 0;
}