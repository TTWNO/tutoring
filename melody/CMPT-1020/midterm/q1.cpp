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

Money operator+(const Money& x, const Money& b) {
	Money m;
	m.dolars = x.dolars + b.dolars;
	m.cents = x.cents + b.cents;
	if (m.cents > 99)
	{
		++m.dolars;
		m.cents = m.cents - 100;
	}
	return m;
}

Money operator-(const Money& x, const Money& b) {
	Money m;
	m.dolars = x.dolars - b.dolars;
	if (m.dolars < 0)
		m.dolars = 0 - m.dolars;
	m.cents = x.cents - b.cents;
	if (m.cents < 0)
	{
		--m.dolars;
		m.cents = 100 - m.cents;
	}
	return m;
}
return m;
}

Money operator*(const Money& x, const Money int& b) {
	Money m;
	m.dolars = x.dolars * c;
	m.cents = x.cents * c;
	if (m.cents > 99) {
		m.dolars = m.dolars + m.cents / 100;
		m.cents = m.cents - (m.cents / 100 * 100);
	}
	return m;
}

bool operator==(Money& x, Money& b) {
	if (x.getDolars() == b.getDolars())
		return (x.getCents() == x.getCents());
}

bool operator<(Money& x, Money& b) {
	if (x.getDolars != b.getDolars)
		return x.getDolars < b.getDolars;
	if (x.getDolars == b.getDolars)
		return x.getCents < b.getCents;
}

bool operator>(Money& x, Money& b) {
	if (x.getDolars != b.getDolars)
		return x.getDolars > b.getDolars;
	if (x.getDolars == b.getDolars)
		return x.getCents > b.getCents;
}


int main()
{
	money.a[9], x, sum;
	for (int i = 0; i < 10; i++) {
		a[i].input;
	}
	x.input;

	for (int i = 0; i < 10; i++) {
		a[i].operator==;
		if (a[i] == x)
			cout << i << " ";
	}

	for (int i = 0; i < 10; i++) {
		a[i].operator<;
		if (x < a[i])
			cout << i << " ";
	}

	for (int i = 0; i < 10; i++)
		sum += a[i];
	sum.output<<endl;
	cout << counter;
	return 0;
}
