/* Zizi Amadike
	Redact-o-matic
*/

#include <string>
#include <iostream>

using namespace std;

string redact;
string line;
string stars;
int redact_index;

int main() {
	cout << "Please enter phrase to redact: " << endl;
	cin >> redact;

    for (int i = 0; i < redact.length(); i++) {
    	stars.push_back('*');
	}

	while (getline(cin, line))
    {
		redact_index = line.find(redact);

		while (redact_index != string::npos) {
			line.replace(redact_index, redact.length() , stars);
			redact_index = line.find(redact);
		}
		cout << line << endl;
	}
}