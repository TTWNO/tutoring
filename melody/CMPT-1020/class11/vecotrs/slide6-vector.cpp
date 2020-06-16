#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int SIZE = 10;

    // Define vector to hold SIZE numbers by default
    vector<int> numbers(SIZE);

    // store the values
    for (int index = 0; index < 99999; index++)
    {
        numbers.push_back(index);
    }
     
    // print 
    for (auto element : numbers)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}