// rational.cpp

// TODO 1: Disallow 0 as a denominator as a paramater to Rational(n, d)
// TODO 2: Disaalow 0 as a denominator in the input function
//      Meaning, validate the input; use a while loop
// TODO 3: If d == 1 then output as only the neumenator.
//      Meaning "x/1" output should become "x"

#include <iostream>
#include <string>
using namespace std;


class Rational {
private:
    int numenator;
    int denominator;
public:
   // accesors
	int getNumenator() const;
	int getDenominator() const;
	// mutators
	void setNumenator(int);
	void setDenominator(int);
	// output
	string output();
	// input (ask the user for numenator and denominator; e.g. 3/4)
	void input();
	// constructor 1: default, no params n=0/d=1
	Rational();
	// constructor 2: 1 argument n/1
	Rational(int);
	// constructor 3: 2 arguments n/d
	Rational(int, int);
    void simplify();
};

/*
returnType ClassName::methodName(varType varName, varType varName, etc.){
    // the actual code
}
*/
int gcd(int m, int n){
    int g = 1;
    for (int i = 2; i <= m && i <= n; i++){
        if (m % i == 0 && n % i == 0){
            g = i;
        }
    }
    return g;
}

int Rational::getNumenator() const{
    return numenator;
}
int Rational::getDenominator() const{
    return denominator;
}
void Rational::setNumenator(int n){
    numenator = n;
}
void Rational::setDenominator(int d){
    // TODO: only set if d != 0
    denominator = d;
}
// TODO: make 3/-4 appear as -3/4. Negative denominator should show up beforte.
string Rational::output(){
    cout << numenator << "/" << denominator;
}
void Rational::input(){
    cout<< "n?";
    cin >> numenator;
    cout << "d?";
    cin >> denominator;
}
Rational::Rational(){
    numenator = 0;
    denominator = 1;
}
Rational::Rational(int n){
    numenator = n;
    denominator = 1;
}
Rational::Rational(int n, int d){
    numenator = n;
    denominator = d;
}

void Rational::simplify(){
    int gcdi = gcd(abs(numenator), abs(denominator));
    if (denominator > 0){
        denominator /= gcdi;
        numenator /= gcdi;
    } else {
        denominator /= -gcdi;
        numenator /= -gcdi;
    }
}

// operator overloading
Rational operator+(const Rational &r1, const Rational &r2){
    Rational returnValue;
    returnValue.setNumenator(r1.getNumenator() * r2.getDenominator() + r1.getDenominator() + r2.getNumenator());
    returnValue.setDenominator(r1.getDenominator() * r2.getDenominator());
    returnValue.simplify();
    return returnValue;
}
Rational operator-(const Rational &r1, const Rational &r2){
    Rational returnValue;
    returnValue.setNumenator(r1.getNumenator() * r2.getDenominator() - r1.getDenominator() + r2.getNumenator());
    returnValue.setDenominator(r1.getDenominator() * r2.getDenominator());
    returnValue.simplify();
    return returnValue;
}
Rational operator*(const Rational &r1, const Rational &r2){
    Rational returnValue;
    returnValue.setNumenator(r1.getNumenator() * r2.getNumenator());
    returnValue.setDenominator(r1.getDenominator() * r2.getDenominator());
    returnValue.simplify();
    return returnValue;
}
Rational operator/(const Rational &r1, const Rational &r2){
    Rational returnValue;
    returnValue.setNumenator(r1.getNumenator() * r2.getDenominator());
    returnValue.setDenominator(r1.getDenominator() * r2.getNumenator());
    returnValue.simplify();
    return returnValue;
}
void operator+=(Rational &r1, const Rational &r2){
	r1 = r1 + r2;
}
void operator-=(Rational &r1, const Rational &r2){
	r1 = r1 - r2;
}
void operator*=(Rational &r1, const Rational &r2){
	r1 = r1 * r2;
}
void operator/=(Rational &r1, const Rational &r2){
	r1 = r1 / r2;
}
bool operator>(const Rational &r1, const Rational &r2){
    // new float r1.n/r1.d
    // same with r2
    // use float to return true if r1's flaot > r2's
    // likewise with < (less than), == (equals), <= (less than or equal), >= (more than or equal), != (not equal)
}


int main()
{
    Rational a(1, 4), b(3, 4), e;
    a.output();
    b.output();

    e = a + b; // should be 1
    e.output();
    e = a - b; // should be -1/2
    e.output();
    e = a * b; // should be 3/16
    e.output();
    e = a / b; // should be 1/3
    e.output();

    return 0;
}
