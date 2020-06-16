#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int searchValue;
    vector<int> numbers = {10, 2, 5, 222, 52, 982, 12, 4};

    // sort the nums
    sort(numbers.begin(), numbers.end());
    cout << "Printing sorted values!" << endl;
    // will now print in low to high order
    for (auto element : numbers)
        cout << element << " ";
    cout << endl;

    cout << "Search for: ";

    cin >> searchValue;
    if (binary_search(numbers.begin(), numbers.end(), searchValue))
    {
        cout << "That value is in the list.\n";
    }
    else 
    {
        cout << "That value is not in the list.\n";
    }
}