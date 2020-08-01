#include <iostream>

using namespace std;

void add2()
{
   int x, y, sum;
   cout << "Add what two numbers together?" << endl;
   cin >> x;
   cin >> y;

    sum = x+y;

   // + - / * %
   cout << "The result is: " << sum << endl;
    if (sum % 2 == 0)
    {
        cout << "Even result!" << endl;
    }
    else
    {
        cout << "Odd result!" << endl;
    }
}

int main()
{
    string name;
    cout << "Name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    int times;
    cout << "How many pairs do you want to add? " << endl;
    cin >> times;

    for (int i = 0; i < times; i++)
    {
        add2();
    }
}

