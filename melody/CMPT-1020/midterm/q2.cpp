#include <iostream>
using namespace std;

class Money
{
	int dollars; /* dollar has two l's */
  int cents;
  static int counter; /* the counter should be private to stop the user from being able to change it */

public:
	int getDollars() const { /* need to declare as const method */
		return dollars;
	}

	int getCents() const {
		return cents;
	}

	int getCounter() const {
		return counter;
	}

	void setDollars(int d) {
		dollars = d;
	}

	void setCents(int c) {
		cents = c;
	}

	void input() {
		cout << "dolar?" << endl;
		cin >> dollars;
		while (dollars < 0) {
			cout << "can't be negative";
			cout << "dolar?" << endl;
			cin >> dollars;
		}
		cout << "cents?" << endl;
		cin >> cents;
		while (cents < 0 && cents > 99) { /* must add second case of cents being higher than 99 */
			cout << "can't be negative or larger than 99";
			cout << "cents?" << endl;
			cin >> cents;
		}
	}
	void output() {
    /* Becuase you need a leading zero in cents, conisder two ways to do this: 
     * original code:
     * cout << "$" << dollars << "." << cents << endl;
     *
     * here is a method which only slightly modifies the code
     */
    // cout << "$" << dollars << "." << (cents < 10 ? "0" << cents : "" << cents) << endl;
     /* this is equivelant to the following: */
     if (cents < 10)
     {
      cout << "$" << dollars << "." << "0" << cents << endl;
     }
     else
     {
      cout << "$" << dollars << "." << cents << endl;
     }
     
	}

	Money() {
		dollars = 0;
		cents = 0;
		counter++;
	}

	Money(int d) {
		dollars = d;
		cents = 0;
		++counter;
	}

	Money(int d, int c) {
		dollars = d;
		cents = c;
		counter++; /* counter was missing an 'e' */
	}

	~Money() {
    counter--; /* needed to reduce the "counter" varialbe when an object is destroyed */
	}
};
int Money::counter = 0; /* must initialize the static variable */

class Inventory{
	string retailer;
int capacity;
int numItems;
string* itemNames;
money* prices;
public:
	string getRetailer() {
		return retailer;
	}

	int getCapacity() {
		return capacity;
	}

	int getNumItems() {
		return numItems;
	}

	void setRetailer (int r) { // extra close parenthasis
		retailer = r; // extra close parenthasies
	}

  Inventory(){
    retailer = Walmart;
    capacity = 100;
  }
};
