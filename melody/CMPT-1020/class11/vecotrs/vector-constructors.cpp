#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // types of constructors
    // default 0 length; expand if necessary
    vector<int> nums1;
    // allocate memory for 50; expand if needed
    vector<int> nums2(50);
    // allocate memory for 50; fill all items with 99; expand if needed
    vector<int> nums3(50, 99);
    // copy constuctor; copy nums3 contents into nums4
    vector<int> nums4(nums3);
    // range constructor

    nums1.push_back(1);
    nums1.insert(nums1.begin(), 5); // make list [5, 1]; add 5 to the start of the vector
    nums1.insert(nums1.end(), 5, 10); // add 5 10s at the end of the list
    
}