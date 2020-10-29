/* Zizi Amadike
	Redact-o-matic
*/

/**
 *
Phrase to redact: and

I went to the store and bought a sour pickle sandwhich.
I went to the store *** bought a sour pickle s***which.
Show me your gameboy and PS5!
Show me your gameboy *** PS5!
More input... And more!
More input... And more!
 */


#include <string>
#include <iostream>

using namespace std;

string redact;
string temp;

int main() {

	cout << "Please enter phrase to redact: " << endl;
	cin >> redact;
    string str;

    for (int i = 0; i < redact.length(); i++) {
    (temp.push_back('*'));
	}
		

	while (getline(cin, str))
    {
    //    str.replace(redact, '*');
		

		redact.length();
	}
}
