#include <iostream>
#include <array>
#include <iterator>

using namespace std;

int main()
{
    array<int, 5> numbers = {1, 2, 3, 4, 5};

    array<int, 5>::reverse_iterator it;

    // display the elements
    for (it = numbers.rbegin(); it != numbers.rend(); it++)
    {
        cout << *it << endl;
    }
}