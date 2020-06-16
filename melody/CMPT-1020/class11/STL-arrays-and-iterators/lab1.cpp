#include <iostream>
#include <array>

using namespace std;

int main()
{
    double t;
    // 1. create an array of five doubles
    array<double, 5> nums;
    array<double, 5>::iterator it;
    // 2. Ask the user to input the numbers using iterators
    for (it = nums.begin(); it != nums.end(); it++)
        cin >> *it;

    // 3. Calculate the average
    
    for (it = nums.begin(); it != nums.end(); it++){
        cout << *it<<" ";
        t += *it;
    }
    cout << t/5;

    array<double, 5>::reverse_iterator rit;
    for (rit = nums.rbegin(); rit != nums.rend(); rit++)
        cout << *rit<<" ";
    
}