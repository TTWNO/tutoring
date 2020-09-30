#include <iostream>

using namespace std;

int main() {
	int a, b;
	float f, g;
	bool x, y;
	int choice = 0;
	
	cout << "Please enter 0 for integers, 1 for floats or 2 for bools: ";
	cin >> choice;

	if (choice == 0) {
		cout << "Please enter one integer: ";
		cin >> a;
		cout << "Please enter one integer: ";
		cin >> b;

		/*	One of these is not like the others. It is up to
			you to determine which one and how to address the
			problem.
		*/
		cout << "a and b are integers" << endl;
		cout << "a is:      " << a << endl;
		cout << "b is:      " << b << endl;
		cout << endl;
		cout << "a + b:     " << a + b << endl;
		cout << "a - b:     " << a - b << endl;
		cout << "a * b:     " << a * b << endl;
	    if (b != 0) {
            cout << "a / b:     " << a / b << endl; 
            cout << "a % b:     " << a % b << endl;
	    }
		cout << endl;
		cout << "-a is:     " << -a << endl;
		cout << "-b is:     " << -b << endl;
		cout << endl;
		cout << "a == b	is: " << (a == b ? "True" : "False") << endl;
		cout << "a < b 	is: " << (a < b ? "True" : "False") << endl;
		cout << "a <= b	is: " << (a <= b ? "True" : "False") << endl;
		cout << "a > b 	is: " << (a > b ? "True" : "False") << endl;
		cout << "a >= b	is: " << (a >= b ? "True" : "False")<< endl;
		cout << "a != b	is: " << (a != b ? "True" : "False") << endl;
		cout << endl;
	} else if (choice == 1) {
		cout << "Please enter one floating point number: ";
		cin >> f;
		cout << "Please enter one floating point number: ";
		cin >> g;

		cout << "f and g are floats" << endl;
		cout << "f is:      " << f << endl;
		cout << "g is:      " << g << endl;
		cout << endl;

		cout << "f + g:     " << f + g << endl;
		cout << "f - g:     " << f - g << endl;
		cout << "f * g:     " << f * g << endl;
		if (g != 0) {
            cout << "f / g:     " << f / g << endl; 
		}
		cout << endl;
		
		cout << "-f is:     " << -f << endl;
		cout << "-g is:     " << -g << endl;
		cout << endl;
		
		cout << "f == g is: " << (f == g ? "True" : "False") << endl;
		cout << "f <  g is: " << (f < g ? "True" : "False")  << endl;
		cout << "f <= g is: " << (f <= g ? "True" : "False") << endl;
		cout << "f >  g is: " << (f > g ? "True" : "False") <<  endl;
		cout << "f >= g is: " << (f >= g ? "True" : "False")<< endl;
		cout << "f != g is: " << (f != g ? "True" : "False") << endl;
		cout << endl;
	} else if (choice == 2) {
		cout << "Please enter a boolean value - 0 is false, anything else is true: ";
		cin >> x;
		cout << "Please enter a boolean value - 0 is false, anything else is true: ";
		cin >> y;

		cout << "x and y are bools" << endl;
		cout << "x is:      " << (x ? "True" : "False") << endl;
		cout << "y is:      " << (y ? "True" : "False") << endl;
		cout << "!x is:     " << (!x ? "True" : "False") << endl;
		cout << "!y is:     " << (!y ? "True" : "False") << endl;
		cout << "x == y is: " << (x == y ? "True" : "False") << endl;
		cout << "x != y is: " << (x != y ? "True" : "False") << endl;
		cout << endl;

		cout << "x && y:    " << (x && y ? "True" : "False") << endl;
		cout << "x || y:    " << (x || y ? "True" : "False") << endl;
		cout << endl;

		cout << "x + y:     " << (x + y ? "True" : "False") << endl;
		cout << "x - y:     " << (x - y ? "True" : "False") << endl;
		cout << "x * y:     " << (x * y ? "True" : "False") << endl;
		if (y != 0) {
            cout << "x / y:     " << (x / y ? "True" : "False") << endl;
            cout << "x % y:     " << (x % y ? "True" : "False") << endl; 
		}
		cout << endl;

		cout << "-x is:     " << (-x ? "True" : "False") << endl;
		cout << "-y is:     " << (-y ? "True" : "False") << endl;
		cout << endl;

		cout << "x <  y is: " << (x < y ? "True" : "False")  << endl;
		cout << "x <= y is: " << (x <= y ? "True" : "False") << endl;
		cout << "x >  y is: " << (x > y ? "True" : "False") << endl;
		cout << "x >= y is: " << (x >= y ? "True" : "False") << endl;
	} else {
		cout << "Entry is not one of 0, 1 or 2" << endl;
	}
	return 0;
}
