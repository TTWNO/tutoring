#include <iostream>
#include <vector>

using namespace std;

int main()
{
int x;
// 1. Define an empty vector
vector<int> n;
// 2. Ask the user to enter some positive numbers
cout << "enter numbers";
do{
    cin >> x;
    n.push_back(x);
}
while(n[n.size()]>=0)

// 3. When the user enters a negative number:
// 3.1 Tell the user how many number were entered by then.

// 3.2 Show the average of all the numbers the user typed
// 3.3 Print the numbers in reverse order.

