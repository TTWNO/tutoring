#include <iostream>
using namespace std;
class Money
{
	int dolars;
int cents;

public:
	static int counter;
	int getDolars() {
		return dolars;
	}

	int getCents() {
		return cents;
	}

	int getCounter() {
		return counter;
	}

	void setDolars(int d) {
		dolars = d;
	}

	void setCents(int c) {
		cents = c;
	}

	void input() {
		cout << "dolar?" << endl;
		cin >> dolars;
		while (dolars < 0) {
			cout << "can't be negative";
			cout << "dolar?" << endl;
			cin >> dolars;
		}
		cout << "cents?" << endl;
		cin >> cents;
		while (cents < 0) {
			cout << "can't be negative";
			cout << "cents?" << endl;
			cin >> cents;
		}
	}

	void output() {
		cout << "$" << dolars << "." << cents << endl;
	}

	Money() {
		dolars = 0;
		cents = 0;
		counter++;
	}

	Money(int d) {
		dolars = d;
		cents = 0;
		++counter;
	}

	Money(int d, int c) {
		dolars = d;
		cents = c;
		countr++;
	}

	~Money() {
		delete[];
	}
};


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

	void setRetailer) (int r) {
		retailer) = r;
	}

Inventory(){
	retailer = Walmart;
	capacity = 100;
