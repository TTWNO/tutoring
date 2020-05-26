#include <iostream>
#include <string>

using namespace std;
int gcd(int m, int n)
{
	int g = 1;
	for (int i = 2; i <= m && i <= n; i++)
		if (m % i == 0 && n % i == 0)
			g = i;
	return g;
}
class Rational
{
private:
	int numerator;
	int denominator;
public:
	int getNumerator() const;
	int getDenominator() const;
	void setNumerator(int);
	void setDenominator(int);
	void output();
	void input();
	Rational();
	Rational(int);
	Rational(int, int);
	void simplify();
	Rational operator-(); // unary minus (-) operator; implementation near 123
	Rational friend operator+(const Rational &a, const Rational &b);
	Rational friend operator-(const Rational &a, const Rational &b);
	Rational operator*(const Rational &b);
	Rational operator/(const Rational &b);
	Rational operator++() // prefix: ++x
	{
		this->numerator += this->denominator;
		return *this;
	}
	Rational operator++(int x) // postfix: x++
	{
		Rational temp;
		temp = *this;
		this->numerator += this->denominator;
		return temp;
	}

	Rational operator--() // prefix: --x
	{
		this->numerator -= this->denominator;
		return *this;
	}
	Rational operator--(int x) // postfix: x--
	{
		Rational temp;
		temp = *this;
		this->numerator -= this->denominator;
		return temp;
	}
};

void Rational::simplify()
{	int a = gcd(abs(this->numerator), abs(this->denominator));
	if (this->denominator > 0)
	{
		this->numerator /= a;
		this->denominator /= a;
	}
	else
	{
		this->numerator /= -a;
		this->denominator /= -a;
	}
}
int Rational::getNumerator() const
{
	return this->numerator;
}
int Rational::getDenominator() const
{
	return this->denominator;
}
void Rational::setNumerator(int x)
{
	this->numerator = x;
	simplify();
}
void Rational::setDenominator(int x)
{
	if (x != 0)
	{
		this->denominator = x;
		simplify();
	}
			
}
void Rational::output()
{
	if (this->denominator == 1)
		cout << this->numerator << endl;
	else if (this->denominator>=0)
		cout << this->numerator << "/" << this->denominator << endl;
}
void Rational::input()
{
	cout << "Numerator? ";
	cin >> this->numerator;
	cout << "Denominator? ";
	cin >> this->denominator;
	while (this->denominator == 0)
	{
		cout << "Denominator? ";
		cin >> this->denominator;
	}
	simplify();
}
Rational::Rational()
{
	this->numerator = 0;
	this->denominator = 1;
}
Rational::Rational(int x)
{
	this->numerator = x;
	this->denominator = 1;
}
Rational::Rational(int x, int y)
{
	this->numerator = x;
	this->denominator = y;
	simplify();
}
//operator overloading
Rational operator+(const Rational &a, const Rational &b)
{
	Rational c;
	c.numerator = a.numerator * b.denominator + a.denominator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	c.simplify();
	return c;
}
Rational operator-(const Rational &a, const Rational &b)
{
	Rational c;
	c.numerator = a.numerator * b.denominator - a.denominator * b.numerator;
	c.denominator = a.denominator * b.denominator;
	c.simplify();
	return c;
}
// member function because has Rational::
Rational Rational::operator-()
{
	Rational c;
	c.numerator = -1 * this->numerator;
	c.denominator = this->denominator;
	c.simplify();
	return c;
}

Rational Rational::operator*(const Rational & b)
{
	Rational c;
	c.numerator = this->numerator * b.numerator;
	c.denominator = this->denominator * b.denominator;
	c.simplify();
	return c;
}
Rational Rational::operator/(const Rational &b)
{
	Rational c;
	c.numerator = this->numerator * b.denominator;
	c.denominator = this->denominator * b.denominator;
	c.simplify();
	return c;
}
void operator+=(Rational& a, const Rational& b)
{
	a = a + b;
	a.simplify();
}
void operator-=(Rational& a, const Rational& b)
{
	a = a - b;
	a.simplify();
}
void operator*=(Rational& a, const Rational& b)
{
	a = a * b;
	a.simplify();
}
void operator/=(Rational& a, const Rational& b)
{
	a = a / b;
	a.simplify();
}
bool operator>(const Rational& a, const Rational& b)
{
	return (a.getNumerator()*b.getDenominator())> (b.getNumerator() * a.getDenominator());
}
bool operator>=(const Rational& a, const Rational& b)
{
	return (a.getNumerator() * b.getDenominator()) >= (b.getNumerator() * a.getDenominator());
}
bool operator<(const Rational& a, const Rational& b)
{
	return (a.getNumerator() * b.getDenominator()) < (b.getNumerator() * a.getDenominator());
}
bool operator<=(const Rational& a, const Rational& b)
{
	return (a.getNumerator() * b.getDenominator()) <= (b.getNumerator() * a.getDenominator());
}
bool operator==(const Rational& a, const Rational& b)
{
	return (a.getNumerator() * b.getDenominator()) == (b.getNumerator() * a.getDenominator());
}
bool operator!=(const Rational& a, const Rational& b)
{
	return (a.getNumerator() * b.getDenominator()) != (b.getNumerator() * a.getDenominator());
}

int main()
{
	Rational a(6,8), b(5,20), e, h(4, 5);
	a.output();
	b.output();
	e = a + b;
	e.output();
	e = a - b;
	e.output();
	e = a * b;
	e.output();
	e = a / b;
	e.output();
	e += b;
	e.output();
	a++;

	if (a > b)
		cout << "a is greater than b";
	// increment and decrement until supposedly back to original value
	++h;
	--h;
	h++;
	h--;

	a = ++h;
	h.output();

	return 0;
}




/*
WHITEBOARD 1:
e = a + b
(a -> x; b -> y; operator+ returns c -> e)
rational operator+(rational x, rational y){
	rational c;
	...
}

e = a + b
(a -> this; b -> x; operator+ returns c -> e)
rational operator+(rational x){
	rational c;
	...
}

WHITEBOARD 2:
a = c-d (binary operator; two operands: c, d)
a = -d (unary operator; one operand: d)

To overload unary operators:
// As members:
class Rational {
	// As members:
	Rational operator+(); // unary operator: +d
	Rational operator-(); // unary operator: -d
	Rational operator++(); // unary operator: ++d/d++
}
Rational Rational::operator+(){ ... }
Rational Rational::operator-(){ ... }
Rational Rational::operator++(){ ... }

// As friends (or non-members)
class Rational {
	// defining the friendship makes the private variables accessable
	Rational friend operator+(Rational r); // unary operator: +d
	Rational friend operator-(Rational r); // unary operator: -d
	Rational friend operator++(Rational r); // unary operator: ++d/d++
}
// Can be implemented as friend function (using private variables),
//		or as a non-friend function (using public methods)
Rational operator+(Rational &r){ ... }
Rational operator-(Rational &r){ ... }
Rational operator++(Rational &r){ ... }

*/