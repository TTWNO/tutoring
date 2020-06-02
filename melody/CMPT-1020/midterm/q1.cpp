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

/* every operation function is a non-member, non-friend;
 * this requires that you use the public methods, not the private variables
 *
 * if a friend or a member, the previous way: m.dollars = x.dollars + b.dollars, etc. would have worked just fine :)
 */
Money operator+(const Money& x, const Money& b) {
	Money m;
	m.setDollars(x.getDollars() + b.getDollars());
	m.setCents(x.getCents() + b.getCents());
	if (m.getCents() > 99)
	{
		m.setDollars(m.getDollars() + 1);
    m.setCents(m.getCents() - 100);
	}
	return m;
}

Money operator-(const Money& x, const Money& b) {
	Money m;
	m.setDollars(x.getDollars() - b.getDollars());
  // if m.dollars < 0 is not needed; that is not of concern to the operator function
  // if non-positives are to be explicitly unallowed, they should be handled in the class itself.
	if (m.getCents() < 0)
	{
    m.setDollars(m.getDollars() - 1);
    m.setCents(100 - m.getCents());
	}
	return m;
}

Money operator*(const Money& x, const int c) {
	Money m;
  m.setDollars(x.getDollars() * c);
  m.setCents(x.getCents() * c);
	if (m.getCents() > 99) {
    m.setDollars(m.getDollars() + (m.getCents() / 100));
    // the modulo (%) operator gets a remainder of a division
    m.setCents(m.getCents() % 100);
    // the previous code:
		// m.cents = m.cents - (m.cents / 100 * 100);
	}
	return m;
}

/* beautiful; almost perfect */
bool operator==(Money& x, Money& b) {
	if (x.getDollars() == b.getDollars())
		return (x.getCents() == x.getCents());
  return false; // must specify some return value at the end that is *garunteed* to run. It makes to compiler not hate you :)
}

/* was missing empty parenthasies; same with more than */
bool operator<(Money& x, Money& b) {
	if (x.getDollars() != b.getDollars())
		return x.getDollars() < b.getDollars();
  // if equal not necessary because by definition if it is equal, it will not get this far because it will return in the not equal if block
  // this is the same for the more than
  return x.getCents() < b.getCents();
}

bool operator>(Money& x, Money& b) {
	if (x.getDollars() != b.getDollars())
		return x.getDollars() > b.getDollars();
  return x.getCents() > b.getCents();
}


int main()
{
  // must capitcalize Money; use space not dot
  // previously: money.a[9], x, sum;
	Money a[9], x, sum;
	for (int i = 0; i < 9; i++) { 
		a[i].input(); // was missing empty parenthasies
	}
	x.input(); // was missing empty parenthasies

	for (int i = 0; i < 9; i++) { // must be up to 9 not 10
		// a[i].operator==; // makes no sense whatsoever
    a[i].output();
		if (a[i] == x)
			cout << i << " ";
	}

	for (int i = 0; i < 9; i++) { 
		// a[i].operator<; // also make no snese at all
		if (x < a[i])
			cout << i << " ";
	}

	for (int i = 0; i < 9; i++)
		sum = sum + a[i]; // += operator not overloaded

	sum.output(); // endl not needed; missing empty parenthasies
	cout << sum.getCounter() << endl; // endl missing; must use moneyObject.getCounter() to retrieve the private variable. You could also use Money::getCounter if the method was marked static (it was not)
	return 0;
}
