// containerType::iterator iteratorName;

#include <iostream>
#include <array>
#include <iterator>

using namespace std;

int main()
{
    const int SIZE = 3;
    // store some names in an array object
    array<string, SIZE> names = {"Sarah", "William", "Alfredo"};

    cout << "Here are the names: " << endl;
    // use auto type to guess based on return type of names.begin()
    for (auto it = names.begin(); it != names.end(); it++)
    {
        cout << *it << endl;
    }
}