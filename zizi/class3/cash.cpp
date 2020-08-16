#include <iostream>

using namespace std;

int main()
{	
	float change;
	float printed = 0;
	float money;
	float cac[] = {100, 50, 20, 10, 5, 2, 1, 0.25, 0.10, 0.05};
	cout << "Enter cash amount: ";
	cin >> money;

	while (money > printed)
    {
        change = money - printed;
        for (auto denom : cac)
        {
			if (change >= denom)
            {
				cout << "$" << denom << endl;
				printed += denom;
				break;
            }
        }
		if (change <= 0.04)
			break;
    }
    return 0;
}

/*
The goal is to create a virtual cash register.
When a user enters a given amount, describe what bills and coins are necessary to get the user their specified amount of money.

/* get input from user (amount of money paid)
arraycac [100, 50, 20, 10, 5, 2, 1, 0.25, 0.10, 0.05]
while amount entered is > amount printed
    change required = input-amount printed
	loop through each denomination in array	
		check if change is >= denomination
			print denomination	

	if change <= 0.04
		break

*/