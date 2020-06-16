// All using vectors:
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size, t;

    // 1. Ask user how many numbers to store.
    cout<< "size?";
    cin>> size;
    vector<int> numbers(SIZE);
    // 2. Grab user input for each number.
    for (int index = 0; index < SIZE; index++){}
        cout<< "number"<<size+1;
        cin>> numbers[index];
        t+=numbers[index];
    }
    // 3. Print out the average
    cout<< t/size;