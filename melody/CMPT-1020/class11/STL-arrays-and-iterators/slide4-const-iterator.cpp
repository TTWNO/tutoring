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

    // define constant iterator.
    array<string, SIZE>::const_iterator it;

    cout << "Here are the names: " << endl;
    // uses const begin, and const end; disallows editing of the iterator
    for (it = names.cbegin(); it != names.cend(); it++)
    {
        // without the * the iterator will print its address, not the value in the address
        cout << *it << endl;
    }
}
