#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_of_nums;
    cout << "How many numnbers do you want to add? ";
    cin >> num_of_nums;

    vector<int> nums;
    int sum = 0;

    nums.reserve(num_of_nums);
    for (int i = 0; i < num_of_nums; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0, n = nums.size(); i < n; i++)
    {
        sum += nums[i];
    }
    cout << "You sum is: " << sum << endl;

    return 0;
}

