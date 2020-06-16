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

    // define iterator; will do bound checking for you.
    array<string, SIZE>::iterator it;

    cout << "Here are the names: " << endl;
    // set the 'it' iterator to the beginning; check if it has exceeded the bounds; increment operator to next item in list
    for (it = names.begin(); it != names.end(); it++)
    {
        // without the * the iterator will print its address, not the value in the address
        cout << *it << endl;
    }
}